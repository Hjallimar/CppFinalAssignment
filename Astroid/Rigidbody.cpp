#include "Rigidbody.h"
#include <iostream>

Rigidbody::Rigidbody() {
	velocity = Vector2(0, 0);
}
Rigidbody::~Rigidbody()
{
	delete parent;
}

void Rigidbody::setup(GameObject* go) {
	parent = go;
}

void Rigidbody::handleVelocity() {
	parent->SetPosition(parent->GetPosition() + velocity);
}

void Rigidbody::addForce(Vector2 force) {
	velocity.x += force.x;
	velocity.y += force.y;
}
