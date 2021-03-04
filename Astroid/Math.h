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
		float mag = sqrtf(powf(fabs(x), 2.0) + powf(fabs(y), 2.0));
		return mag;
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

	Vector2 operator /(float a)
	{
		return Vector2(x / a, y / a);
	}

	Vector2 operator *=(float a)
	{
		x *= a;
		y *= a;
		return Vector2(x, y);
	}
} Vector2;

typedef struct Collider
{
	Vector2 center;
	float radius;
	Collider() {
		center = Vector2();
		radius = 0;
	}
	Collider(Vector2 pos, float r) 
	{
		center = pos;
		radius = r;
	}
	~Collider() 
	{

	}

	bool Overlaping(Collider col) 
	{
		Vector2 dist = center - col.center;
		if (dist.Magnitude() < col.radius + radius)
		{
			return true;
		}
		return false;
	}
} Collider;

class Math
{
public:
	Math();
	~Math();
	Vector2 AngleToVector(float angle);
	float VectorToAngle(Vector2 dir);
	float DegreesToRadians(float angle);
};
