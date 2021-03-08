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

Vector2 Player::GetDirFromAngle(int angle) 
{
	Vector2 temp = Vector2();
	temp.x = GetPosition().x + (dir.x * cos(angle) - dir.y * sin(angle)) * GetCollider()->radius;
	temp.y = GetPosition().y + (dir.x * sin(angle) + dir.y * cos(angle)) * GetCollider()->radius;
	return temp;
}

void Player::RenderPlayer(SDL_Renderer* renderer)
{
	Vector2 nPoint = GetDirFromAngle(-60);
	Vector2 pPoint = GetDirFromAngle(60);
	float r = GetCollider()->radius;
	Vector2 fPoint = Vector2(GetPosition().x + dir.x * r, GetPosition().y + dir.y * r);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(renderer, nPoint.x, nPoint.y, pPoint.x, pPoint.y);
	SDL_RenderDrawLine(renderer, pPoint.x, pPoint.y, fPoint.x, fPoint.y);
	SDL_RenderDrawLine(renderer, fPoint.x, fPoint.y, nPoint.x, nPoint.y);
}

void Player::UpdatePlayer(double dt) 
{
	if (timeSinceLastBullet <= 1 / fireRate) {
		timeSinceLastBullet += dt;
	}

	GetRigidbody()->HandleVelocity();
	GetRigidbody()->HandleBorderPortal();
}
