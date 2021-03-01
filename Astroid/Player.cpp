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
	rotation += (clockwise) ? rotationSpeed : -rotationSpeed;
}

void Player::Move(Vector2 dir) {
	Vector2 force;
	force.x = dir.x * thrustPower;
	force.y = dir.y * thrustPower;
	rigidbody->addForce(force);
}

void Player::ThrustForward() {
	Vector2 dir;
	Math math;
	dir = math.angleToVector(math.degreesToRadians(rotation));
	std::cout << "x: " << dir.x << std::endl;
	std::cout << "y: " << dir.y << std::endl;
	Move(dir);
}

void Player::RenderPlayer(SDL_Renderer* renderer)
{
	/*SDL_FillRect(renderer, SDL_Rect rectangle);*/
}

//void Player::Update() {
//	renderer->setPosition(getPosition());
//}