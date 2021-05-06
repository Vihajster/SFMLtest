#pragma once
#include <SFML/Graphics.hpp>
//#include "Structures.h"

using namespace sf;

class World;

class Ball : public Drawable
{
public:
	World & world;
	CircleShape shape;
	void update();
	void move();
	Vector2f position;


	Ball(World & world, float x, float y);
	Ball(World & world, Vector2f position);
	Ball(World & world);
	Ball() = delete;
	~Ball() = default;
	
	

private:
	float radius = 10.f;
	float velocityValue = 1.f;
	Vector2f velocity;
	float rotation = 0;
	float rotation_speed;
	Vector2f acceleration;

	Vector2f target;

	void rotate();
	void calculateSpeed();
	void calculateAcceleration();
	//void move();
	void goWhereHeaded();
	Vector2f gravityToTarget();

	void setTarget(Vector2f position);
	void setTarget(Ball* ball);

	Ball* findClosestBall();

	void draw(RenderTarget& target, RenderStates state) const override;
};