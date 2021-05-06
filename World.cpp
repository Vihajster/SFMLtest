#pragma once
#include "World.h"
#include "Ball.h"
#include <conio.h>



World::World(int width, int height)
{
	this->width = width;
	this->height = height;
}

void World::spawnBalls(int num)
{
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		new Ball(*this);
	}
}

void World::draw(RenderTarget& target, RenderStates state) const
{
	for (std::list<Ball*>::const_iterator iter = balls.begin(); iter != balls.end(); iter++)
	{
		target.draw((*iter)->shape,state);
	}
}

void World::update()
{
	for (std::list<Ball*>::const_iterator iter = balls.begin(); iter != balls.end(); iter++)
	{
		(*iter)->update();
	}
	for (std::list<Ball*>::const_iterator iter = balls.begin(); iter != balls.end(); iter++)
	{
		(*iter)->move();
	}
}