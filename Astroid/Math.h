#pragma once

#include <math.h>

typedef struct Vector2
{
	float x;
	float y;

	Vector2() 
	{
		x = 0;
		y = 0;
	}

	Vector2(float newX, float newY) 
	{
		x = newX;
		y = newY;
	}

	~Vector2()
	{

	}

	float Magnitude()
	{
		return fabs(x) + fabs(y);
	}

	Vector2 operator +(Vector2 a) 
	{
		return Vector2(a.x + x, a.y + y);
	}

	Vector2 operator -(Vector2 a) 
	{
		return Vector2(a.x - x, a.y - y);
	}

	Vector2 operator *(float a) 
	{
		return Vector2(a * x, a * y);
	}

	Vector2 operator *=(float a)
	{
		x *= a;
		y *= a;
		return Vector2(x, y);
	}
} Vector2;

class Math
{
public:
	Math();
	~Math();
	Vector2 angleToVector(float angle);
	float vectorToAngle(Vector2 dir);
	float degreesToRadians(float angle);
};
