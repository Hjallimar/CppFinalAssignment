#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

Vector2 GameObject::getPosition()
{
	return position;
}

void GameObject::setPosition(Vector2 newPosition)
{
	position = newPosition;
}
