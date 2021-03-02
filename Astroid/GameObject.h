#pragma once

#include "Math.h"
#include <vector>

class GameObject 
{
public:
	GameObject();
	~GameObject();
	Vector2 GetPosition();
	Collider GetCollider();
	void SetPosition(Vector2 newPosition);
	virtual void Die() = 0;

private:
	Vector2 position;
	Collider collider;
};