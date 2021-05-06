#pragma once
#include <cstdlib>
#include <ctime>
using namespace sf;


float vectorLenght(Vector2f vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

Vector2f vectorNormalize(Vector2f vector)
{
	return vector / vectorLenght(vector);
}


