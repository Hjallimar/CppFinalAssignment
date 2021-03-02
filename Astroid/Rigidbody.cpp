#include "Rigidbody.h"
#include <iostream>

Rigidbody::Rigidbody() {
	velocity = Vector2(0, 0);
}
Rigidbody::~Rigidbody()
{
	//delete parent;
}

void Rigidbody::Setup(GameObject* go) {
	parent = go;
}

void Rigidbody::HandleVelocity() {
	parent->SetPosition(parent->GetPosition() + velocity);
}

void Rigidbody::AddForce(Vector2 force) {
	velocity.x += force.x;
	velocity.y += force.y;
}
