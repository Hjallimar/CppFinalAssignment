#pragma once

#include "SDL.h"
#include "Rigidbody.h"

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	Rigidbody* GetRigidbody() { return rigidbody; }
	void UpdateBullet();
	void RenderBullet(SDL_Renderer* renderer);
	void Die();

private:
	Rigidbody* rigidbody;
	double lifetime = 5.0;
	SDL_Rect rectangle;
};

