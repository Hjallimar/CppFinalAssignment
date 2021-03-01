#pragma once

#include "IComponent.h"
#include "Math.h"

class Rigidbody : public IComponent
{
public:
	Rigidbody();
	~Rigidbody();

	void setup(GameObject* go);

	void handleVelocity();
	void addForce(Vector2 force);
private:
	Vector2 velocity;
};
