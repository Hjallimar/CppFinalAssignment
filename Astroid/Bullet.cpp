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
	delete collider;
}

void Bullet::UpdateBullet(double dt)
{
	lifeTime -= dt;
	GetRigidbody()->HandleVelocity();
	rectangle.x = GetPosition().x;
	rectangle.y = GetPosition().y;
	GetCollider()->center = GetPosition();

	if (GetPosition().x < 0)
	{
		SetPosition(Vector2(GetPosition().x + 600, GetPosition().y));
	}
	else if (GetPosition().x > 600)
	{
		SetPosition(Vector2(GetPosition().x - 600, GetPosition().y));
	}
	if (GetPosition().y < 0)
	{
		SetPosition(Vector2(GetPosition().x, GetPosition().y + 600));
	}
	else if (GetPosition().y > 600)
	{
		SetPosition(Vector2(GetPosition().x, GetPosition().y - 600));
	}
}

void Bullet::RenderBullet(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rectangle);
}

void Bullet::Die()
{

}
