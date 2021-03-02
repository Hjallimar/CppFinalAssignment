#pragma once

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
