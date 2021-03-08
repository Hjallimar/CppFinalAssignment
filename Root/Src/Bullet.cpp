#include "Bullet.h"
#include <iostream>

Bullet::Bullet()
{
	rigidbody = new Rigidbody();
	GetRigidbody()->Setup(this);

	rectangle = SDL_Rect();
	rectangle.h = 2;
	rectangle.w = 2;
}

Bullet::~Bullet()
{
	delete rigidbody;
	delete collider;
}

void Bullet::UpdateBullet(double dt)
{
	lifeTime -= dt;
	rigidbody->HandleVelocity();
	rigidbody->HandleBorderPortal();
}

void Bullet::RenderBullet(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	rectangle.x = GetPosition().x;
	rectangle.y = GetPosition().y;
	SDL_RenderFillRect(renderer, &rectangle);
}
