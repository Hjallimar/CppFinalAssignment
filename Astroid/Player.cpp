#include "Player.h"

Player::Player()
{
	direction = Vector2(1.0f, 0.0f);
	position = Vector2();
}

Player::~Player()
{
}

void Player::Rotate(float angle)
{
	float newX = direction.x * cos(angle) - direction.y * sin(angle);
	float newY = direction.x * sin(angle) + direction.y * cos(angle);
	direction.x = newX;
	direction.y = newY;
}

void Player::Move(float speed)
{
	position.x += direction.x * speed;
	position.y += direction.y * speed;
}

void Player::RenderPlayer(SDL_Renderer* renderer)
{
	float a1 = (direction.x * cos(-60) - direction.y * sin(-60)) * 25 + position.x + 0.5;
	float a2 = (direction.x * sin(-60) + direction.y * cos(-60)) * 25 + position.y + 0.5;

	float b1 = (direction.x * cos(60) - direction.y * sin(60)) * 25 + position.x + 0.5;
	float b2 = (direction.x * sin(60) + direction.y * cos(60)) * 25 + position.y + 0.5;

	SDL_RenderDrawLine(renderer, a1, a2, b1, b2);
	SDL_RenderDrawLine(renderer, a1, a2, direction.x + position.x + 0.5, direction.y + position.y + 0.5);
	SDL_RenderDrawLine(renderer, b1, b2, direction.x + position.x + 0.5, direction.y + position.y + 0.5);
}