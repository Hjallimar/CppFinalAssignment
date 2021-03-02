#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
	rigidbody = new Rigidbody();
	GetRigidbody()->Setup(this);

	collider = new Collider(GetPosition(), 2);

	rectangle = SDL_Rect();
	rectangle.h = 2;
	rectangle.w = 2;
}

Bullet::~Bullet()
{
	delete rigidbody;
}

void Bullet::UpdateBullet()
{
	SetPosition(GetPosition() + GetRigidbody()->GetVelocity());
	rectangle.x = GetPosition().x;
	rectangle.y = GetPosition().y;
	GetCollider()->center = GetPosition();
}

void Bullet::RenderBullet(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rectangle);
}

void Bullet::Die()
{
}
