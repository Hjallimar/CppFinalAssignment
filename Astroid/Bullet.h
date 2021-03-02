#pragma once

#include "SDL.h"
#include "Rigidbody.h"

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	Rigidbody* GetRigidbody() { return rigidbody; }
	void UpdateBullet(double dt);
	void RenderBullet(SDL_Renderer* renderer);
	void Die();
	double GetLifeTime() { return lifeTime; }

private:
	Rigidbody* rigidbody;
	double lifeTime = 5.0;
	SDL_Rect rectangle;
};

