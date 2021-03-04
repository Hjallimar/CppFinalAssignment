#pragma once

#include "Math.h"
#include <vector>

class GameObject 
{
public:
	GameObject(int x, int y);
	~GameObject();
	Vector2 GetPosition();
	Collider* GetCollider();
	void SetPosition(Vector2 newPosition);
	virtual void Die() = 0;
	Vector2* windowBounderies;

protected:
	Collider* collider;

private:
	Vector2 position;
};