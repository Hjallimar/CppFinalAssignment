#include "Rigidbody.h"
#include <iostream>

Rigidbody::Rigidbody() {
	velocity = Vector2(0, 0);
}
Rigidbody::~Rigidbody()
{}

void Rigidbody::setup(GameObject* go) {
	parent = go;
}

void Rigidbody::handleVelocity() {
	std::cout << parent->getPosition().x << std::endl;
	std::cout << parent->getPosition().y << std::endl;
	parent->setPosition(parent->getPosition() + velocity);
}

void Rigidbody::addForce(Vector2 force) {
	velocity.x += force.x;
	velocity.y += force.y;
}