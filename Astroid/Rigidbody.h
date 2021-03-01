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
	void Nullify()
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	Vector2 GetVelocity()
	{
		return velocity;
	}
private:
	Vector2 velocity;
};
