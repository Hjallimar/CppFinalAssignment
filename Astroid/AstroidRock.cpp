#include "AstroidRock.h"
#include <iostream>
AstroidRock::AstroidRock() 
{
	size = 1;
	speed = 5.0f;
	SetPosition(Vector2(100,100));
	rigidbody = new Rigidbody();
	rigidbody->Setup(this);
	Math math;
	int angle = std::rand() % 360;
	direction = math.AngleToVector(math.DegreesToRadians(angle));
	rigidbody->AddForce(direction * speed);
	rect = SDL_Rect();
	rect.h = size * GetCollider()->radius;
	rect.w = size * GetCollider()->radius;
}

AstroidRock::AstroidRock(int newSize, Vector2 startPos) 
{
	size = newSize;
	speed = 2.0f;
	SetPosition(startPos);
	rigidbody = new Rigidbody();
	rigidbody->Setup(this);
	Math math;
	int angle = std::rand() % 360;
	direction = math.AngleToVector(math.DegreesToRadians(angle));
	rigidbody->AddForce(direction * speed);
	rect = SDL_Rect();
	rect.h = size * GetCollider()->radius;
	rect.w = size * GetCollider()->radius;
}

AstroidRock::~AstroidRock() 
{
	delete rigidbody;
}

void AstroidRock::ChangeDirection(Vector2 newDir) 
{
	direction = newDir;
}

void AstroidRock::Render(SDL_Renderer* render) 
{
	rect.x = GetCollider()->center.x - rect.w / 2;
	rect.y = GetCollider()->center.y - rect.w / 2;
	SDL_SetRenderDrawColor(render, 0, 255, 0, 0);
	SDL_RenderFillRect(render, &rect);
}

void AstroidRock::Die() 
{
	//create 2 new astroids with size -1 and a new dirr
}

void AstroidRock::TrySplit(std::vector<AstroidRock*>* rocks) 
{
	if (size <= 1)
		return;

	if (rocks->size() > rocks->max_size() - 1)
	{
		int cap = rocks->size();
		rocks->resize(rocks->capacity() * 2);
		rocks->erase(rocks->begin() + cap, rocks->end());
	}
	int rand = std::rand() % 120;
	Math math;
	//split 1
	AstroidRock* rock1 = new AstroidRock(size - 1, GetPosition());
	float angle = math.VectorToAngle(direction);
	Vector2 newDirr = math.AngleToVector(math.DegreesToRadians(angle + rand));
	rock1->ChangeDirection(newDirr);
	rocks->push_back(rock1);
	//split 2
	rand = std::rand() % 120;
	AstroidRock* rock2 = new AstroidRock(size - 1, GetPosition());
	newDirr = math.AngleToVector(math.DegreesToRadians(angle -rand));
	rock2->ChangeDirection(newDirr);
	rocks->push_back(rock2);

}

void AstroidRock::UpdateAstroid() 
{
	rigidbody->HandleVelocity();
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
	GetCollider()->center = GetPosition();
}