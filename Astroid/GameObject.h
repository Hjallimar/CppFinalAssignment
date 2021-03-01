#pragma once

#include "Math.h"

class GameObject 
{
public:
	GameObject();
	~GameObject();

	Vector2 getPosition();
	void setPosition(Vector2 newPosition);
	void AddPosition(Vector2 velocity);
private:
	Vector2 position;
};