#include "Player.h"

Player::Player()
{
	rigidbody = new Rigidbody();
	rigidbody->Setup(this);
	dir = Vector2(1, 0);
}

Player::~Player()
{
	delete rigidbody;
}

void Player::Rotate(bool clockwise) {
	Math math;
	dir = math.AngleToVector(math.DegreesToRadians(rotation));
	rotation += (clockwise) ? rotationSpeed : -rotationSpeed;
}

void Player::ThrustForward() {
	Vector2 force;
	force.x = dir.x * thrustPower;
	force.y = dir.y * thrustPower;
	rigidbody->AddForce(force);
}

void Player::Shoot()
{
	if (timeSinceLastBullet >= 1 / fireRate) {
		__raise BulletFiredEvent();
		timeSinceLastBullet = 0;
	}
}

void Player::RenderPlayer(SDL_Renderer* renderer)
{
	float a1 = GetPosition().x + (dir.x * cos(-60) - dir.y * sin(-60)) * GetCollider()->radius;
	float a2 = GetPosition().y + (dir.x * sin(-60) + dir.y * cos(-60)) * GetCollider()->radius;
	float b1 = GetPosition().x + (dir.x * cos(60) - dir.y * sin(60)) * GetCollider()->radius;
	float b2 = GetPosition().y + (dir.x * sin(60) + dir.y * cos(60)) * GetCollider()->radius;
	float c1 = GetPosition().x + dir.x * GetCollider()->radius;
	float c2 = GetPosition().y + dir.y * GetCollider()->radius;
	SDL_RenderDrawLine(renderer, a1, a2, b1, b2);
	SDL_RenderDrawLine(renderer, b1, b2, c1, c2);
	SDL_RenderDrawLine(renderer, c1, c2, a1, a2);
	/*SDL_FillRect(renderer, SDL_Rect rectangle);*/
}

void Player::UpdatePlayer(double dt) {
	if (timeSinceLastBullet <= 1 / fireRate) {
		timeSinceLastBullet += dt;
	}

	GetRigidbody()->HandleVelocity();
	GetRigidbody()->HandleBorderPortal();
}

void Player::Die()
{
}
