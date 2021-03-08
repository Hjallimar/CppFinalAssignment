#pragma once

#include "Math.h"
#include <vector>

class GameObject 
{
public:
	GameObject();
	~GameObject();
	Vector2 GetPosition();
	Collider* GetCollider();
	void SetPosition(Vector2 newPosition);

	Vector2 GetBoundaries() { return windowBounderies; }
	void SetBoundaries(Vector2 v);

protected:
	Collider* collider;

private:
	Vector2 position;
	Vector2 windowBounderies;
};