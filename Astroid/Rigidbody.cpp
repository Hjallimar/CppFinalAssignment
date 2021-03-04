#include "Rigidbody.h"
#include <iostream>

Rigidbody::Rigidbody() 
{
	velocity = Vector2(0, 0);
}
Rigidbody::~Rigidbody()
{}

void Rigidbody::Setup(GameObject* go)
{
	parent = go;
}

void Rigidbody::HandleVelocity() 
{
	parent->SetPosition(parent->GetPosition() + velocity);
}

void Rigidbody::AddForce(Vector2 force) 
{
	velocity.x += force.x;
	velocity.y += force.y;
}

void Rigidbody::Nullify() 
{
	velocity.x = 0;
	velocity.y = 0;
}

void Rigidbody::HandleBorderPortal() 
{
	Vector2 pos = parent->GetPosition();
	Vector2 border = parent->GetBoundaries();

	if (pos.x < 0)
	{
		parent->SetPosition(Vector2(pos.x + border.x, pos.y));
	}
	else if (pos.x > border.x)
	{
		parent->SetPosition(Vector2(pos.x - border.x, pos.y));
	}

	if (pos.y < 0)
	{
		parent->SetPosition(Vector2(pos.x, pos.y + border.y));
	}
	else if (pos.y > border.y)
	{
		parent->SetPosition(Vector2(pos.x, pos.y - border.y));
	}
}