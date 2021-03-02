#include "GameObject.h"

GameObject::GameObject()
{
	collider = Collider(GetPosition(), 10.0f);
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
}

Collider GameObject::GetCollider() 
{
	return collider;
}
