#include "Player.h"


Player::Player()
{
	direction = Vector2(1.0f, 0.0f);
	position = Vector2();
	playerRect = SDL_Rect();
	playerRect.x = position.x;
	playerRect.y = position.y;

	playerRect.h = 35;
	playerRect.w = 35;

	dirrRect = SDL_Rect();
	dirrRect.x = position.x + direction.x * 60;
	dirrRect.y = position.y + direction.y * 60;

	dirrRect.h = 5;
	dirrRect.w = 5;
}

Player::~Player()
{
}
void Player::UpdateRect()
{
	playerRect.x = position.x;//- (playerRect.w / 2);
	playerRect.y = position.y;// - (playerRect.h / 2);
	dirrRect.x = position.x + direction.x * 60;
	dirrRect.y = position.y + direction.y * 60;
}

void Player::Rotate(float angle)
{
	float newX = direction.x * cos(angle) - direction.y * sin(angle);
	float newY = direction.x * sin(angle) + direction.y * cos(angle);
	direction.x = newX;
	direction.y = newY;
	UpdateRect();
}

void Player::Move(float speed)
{
	position.x += direction.x * speed;
	position.y += direction.y * speed;
	UpdateRect();
}