#include "GameObject.h"
#include <iostream>
GameObject::GameObject(int x, int y)
{
	position = Vector2(0.0f, 0.0f);
	collider = new Collider(GetPosition(), 10.0f);
	windowBounderies = new Vector2(x, y);
}

GameObject::~GameObject()
{
}

Vector2 GameObject::GetPosition()
{
	return position;
}

void GameObject::SetPosition(Vector2 newPosition)
{
	position = newPosition;
	collider->center = position;
}

Collider* GameObject::GetCollider() 
{
	return collider;
}
