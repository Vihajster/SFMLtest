#pragma once
#include <SFML/Graphics.hpp>
#include <list>
using namespace sf;

class Ball;

class World : public Drawable
{
public:
	int width;
	int height;
	std::list<Ball*> balls;

	World(int width, int height);

	void draw(RenderTarget& target, RenderStates state) const override;

	void spawnBalls(int num);

	void update();

};