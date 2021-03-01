#include "Player.h"

Player::Player()
{
	rigidbody = new Rigidbody();
	rigidbody->setup(this);
}

Player::~Player()
{
}

void Player::Rotate(bool clockwise) {
	Math math;
	dir = math.angleToVector(math.degreesToRadians(rotation));
	rotation += (clockwise) ? rotationSpeed : -rotationSpeed;
}

void Player::ThrustForward() {
	Vector2 force;
	force.x = dir.x * thrustPower;
	force.y = dir.y * thrustPower;
	rigidbody->addForce(force);
}

void Player::RenderPlayer(SDL_Renderer* renderer)
{
	float a1 = getPosition().x + (dir.x * cos(-60) - dir.y * sin(-60)) * 25;
	float a2 = getPosition().y + (dir.x * sin(-60) + dir.y * cos(-60)) * 25;
	float b1 = getPosition().x + (dir.x * cos(60) - dir.y * sin(60)) * 25;
	float b2 = getPosition().y + (dir.x * sin(60) + dir.y * cos(60)) * 25;
	float c1 = getPosition().x + dir.x * 25;
	float c2 = getPosition().y + dir.y * 25;
	SDL_RenderDrawLine(renderer, a1, a2, b1, b2);
	SDL_RenderDrawLine(renderer, b1, b2, c1, c2);
	SDL_RenderDrawLine(renderer, c1, c2, a1, a2);
	/*SDL_FillRect(renderer, SDL_Rect rectangle);*/
}

void Player::UpdatePlayer() {

	getRigidbody()->handleVelocity();
}