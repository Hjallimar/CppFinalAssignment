#pragma once

#include "Math.h"

class GameObject 
{
public:
	GameObject();
	~GameObject();

	Vector2 getPosition();
	void setPosition(Vector2 newPosition);
private:
	Vector2 position;
};