#include "AstroidRock.h"
#include <iostream>
AstroidRock::AstroidRock() 
{}

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
	GetCollider()->radius = rect.h / 2;
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
	float r = GetCollider()->radius;
	Vector2 point = Vector2(0, r);
	Vector2 prevPoint;
	Math math;
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	int corner = 8;
	int angle = 360 / corner;

	for (int i = 0; i < corner + 1; i++)
	{
		float newAngle = math.VectorToAngle(point);
		newAngle += angle * i;
		point = math.AngleToVector(math.DegreesToRadians(newAngle));
		point *= r;
		if (prevPoint != Vector2(0, 0)) 
		{
			//just to make it more readable
			int x1 = GetPosition().x + prevPoint.x + 0.5;
			int y1 = GetPosition().y + prevPoint.y + 0.5;
			int x2 = GetPosition().x + point.x + 0.5;
			int y2 = GetPosition().y + point.y + 0.5;
			SDL_RenderDrawLine(render, x1, y1, x2, y2);
		}
		prevPoint = point;
	}
}

void AstroidRock::TrySplit(std::vector<AstroidRock*>* rocks) 
{
	if (size <= 1)
		return;
	if (rocks->size() > rocks->max_size() - 1)
	{
		int cap = rocks->size();
		rocks->resize(rocks->max_size() * 2);
		rocks->erase(rocks->begin() + cap, rocks->end());
	}
	Math math;
	float angle = math.VectorToAngle(direction);
	//split 1
	rocks->push_back(HandleSplit(size, angle, std::rand() % 120));
	//split 2
	rocks->push_back(HandleSplit(size, angle, -std::rand() % 120));
}

AstroidRock* AstroidRock::HandleSplit(int size, float angle, int rand)
{
	Math math;
	AstroidRock* rock = new AstroidRock(size - 1, GetPosition());
	Vector2 dir = math.AngleToVector(math.DegreesToRadians(angle + rand));
	rock->ChangeDirection(dir);
	rock->SetBoundaries(rigidbody->parent->GetBoundaries());
	return rock;
}

void AstroidRock::UpdateAstroid() 
{
	rigidbody->HandleVelocity();
	rigidbody->HandleBorderPortal();
}