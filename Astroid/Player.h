#pragma once

#include "SDL.h"
#include "GameObject.h"
#include "Rigidbody.h"
#include "Math.h"
#include "Bullet.h"
#include <stdio.h>
#include <iostream>

[event_source(native)]
class Player : public GameObject
{
public:

	Player();
	~Player();

	__event void BulletFiredEvent();

	Rigidbody* GetRigidbody() { return rigidbody; }
	void Rotate(bool clockwise);
	void ThrustForward();
	void Shoot();
	void RenderPlayer(SDL_Renderer* renderer);
	void UpdatePlayer(double dt);
	void Deaccelerate()
	{
		if (rigidbody->GetVelocity().Magnitude() > 0.1)
		{
			Vector2 force = rigidbody->GetVelocity();
			force *= -1.0f;
			force *= 0.01f;
			rigidbody->AddForce(force);
		}
		else
		{
			rigidbody->Nullify();
		}
	}
	Vector2 GetDirection() { return dir; }

private:
	Rigidbody* rigidbody;
	Vector2 dir;
	float rotation = 0;
	float rotationSpeed = 5.0;
	float thrustPower = 0.05;
	float fireRate = 2;
	float timeSinceLastBullet = 0;
};

