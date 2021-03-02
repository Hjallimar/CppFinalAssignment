#pragma once

#include "SDL.h"
#include "GameObject.h"
#include "Rigidbody.h"
#include "Math.h"
#include <iostream>

class Player : public GameObject
{
public:

	Player();
	~Player();

	Rigidbody* getRigidbody() { return rigidbody; }
	void Rotate(bool clockwise);
	void ThrustForward();
	void RenderPlayer(SDL_Renderer* renderer);
	void UpdatePlayer();
	void Die();
	void Deaccelerate()
	{
		if (rigidbody->GetVelocity().Magnitude() > 0.1)
		{
			Vector2 force = rigidbody->GetVelocity();
			force *= -1.0f;
			force *= 0.01f;
			rigidbody->addForce(force);
		}
		else
		{
			rigidbody->Nullify();
		}
	}

private:
	Rigidbody* rigidbody;
	Vector2 dir;
	float rotation;
	float rotationSpeed = 5.0;
	float thrustPower = 0.05;
};

