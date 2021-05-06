#pragma once
#define _USE_MATH_DEFINES

#include "Ball.h"
#include "World.h"
#include <conio.h>
#include <cmath>
#include "Structures.h"


Ball::Ball(World & world, float x, float y)
	:world(world)
{
	position.x = x;
	position.y = y;
	shape.setFillColor(Color::Green);
	shape.setRadius(radius);
	world.balls.push_back(this);

	rotation_speed = ((float(rand()) / RAND_MAX )-0.5)/8;
	target.x = world.width / 2;
	target.y = world.height / 2;
	//velocity.x = (rand() % 5) - 2.5;
	//velocity.y = (rand() % 5) - 2.5;

}

Ball::Ball(World& world, Vector2f position)
	:Ball(world,position.x,position.y)
{
}

Ball::Ball(World& world)
	: Ball(world, rand() % world.width, rand() % world.height)
{
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}



void Ball::update()
{

	setTarget(findClosestBall());
	calculateAcceleration();
	// gravityToTarget();
	//move();
	//goWhereHeaded();
	shape.setPosition(position.x-radius, position.y-radius);
}

void Ball::rotate()
{
	rotation += rotation_speed;
	if (rotation > M_PI * 2)
		rotation -= M_PI * 2;
	else if (rotation < M_PI * 2)
		rotation += M_PI * 2;


}

void Ball::calculateSpeed()
{
	velocity.x = velocityValue * cos(rotation);
	velocity.y = velocityValue * sin(rotation);
}

void Ball::move()
{
	position.x += velocity.x;
	position.y += velocity.y;
	if (position.x > world.width)
		position.x -= world.width;
	else if (position.x < 0)
		position.x += world.width;
	if (position.y > world.height)
		position.y -= world.height;
	else if (position.y < 0)
		position.y += world.height;
}

void Ball::goWhereHeaded()
{
	rotate();
	calculateSpeed();
	move();
}

Vector2f Ball::gravityToTarget()
{
	Vector2f x = target - position;
	float distanceToTarget = vectorLenght(x);
	if (distanceToTarget < 20.f)
		distanceToTarget = 20.f;
	double G =40;
	double gravityForce = G / (double(distanceToTarget) * double(distanceToTarget));
	float acc = gravityForce;
	Vector2f gravityVector;
	x = vectorNormalize(x);
	gravityVector.x = x.x * acc;
	gravityVector.y = x.y * acc;
	return gravityVector;
}

void Ball::calculateAcceleration()
{
	acceleration = gravityToTarget();

	velocity += acceleration;
}
void Ball::setTarget(Vector2f position)
{
	target = position;
}
void Ball::setTarget(Ball* ball)
{
	if(ball !=nullptr)
		target = ball->position;
}

Ball* Ball::findClosestBall()
{
	Ball *closestBall = nullptr;
	float smallestDistance = INFINITY;
	for (std::list<Ball*>::const_iterator iter = world.balls.begin(); iter != world.balls.end(); iter++)
	{
		float distenceToBall = vectorLenght(position - (*iter)->position);
		if (distenceToBall < smallestDistance && (*iter) !=this)
		{
			smallestDistance = distenceToBall;
			closestBall = (*iter);
		}
	}
	return closestBall;
}

