#pragma once
#include <math.h>
#include <SDL.h>
class Player
{
private:
	struct Vector2
	{
	public:
		float x, y;
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
	};
	Vector2 direction;

public:
	Vector2 position;

	Player();
	~Player();
	void Rotate(float angle);
	void Move(float speed);
	void RenderPlayer(SDL_Renderer* renderer);
};

