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
	void Move(Vector2 dir);
	void ThrustForward();
	void RenderPlayer(SDL_Renderer* renderer);
	void Update();

private:
	Rigidbody* rigidbody;
	float rotation;
	float rotationSpeed = 10.0;
	float thrustPower = 0.05;
};

