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
	virtual void Die() = 0;
	Vector2* windowBounderies;

	virtual void SetBouneries(int x, int y) {
		windowBounderies = new Vector2(x, y);
	}
protected:
	Collider* collider;

private:
	Vector2 position;
};