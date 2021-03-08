#pragma once

#include "SDL.h"
#include "IComponent.h"
#include "Math.h"

class Rigidbody : public IComponent
{
public:
	Rigidbody();
	~Rigidbody();

	void Setup(GameObject* go);

	void HandleVelocity();
	void AddForce(Vector2 force);
	void Nullify();
	void HandleBorderPortal();

	Vector2 GetVelocity() { return velocity; }

private:
	Vector2 velocity;
	SDL_Window* window;
};
