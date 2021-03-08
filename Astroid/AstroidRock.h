#pragma once
#include "GameObject.h"
#include "SDL.h"
#include "Rigidbody.h"

class AstroidRock:public GameObject
{
public:
	AstroidRock();
	AstroidRock(int newSize, Vector2 startPos);
	~AstroidRock();
	Rigidbody* GetRigidBody() { return rigidbody; }
	void ChangeDirection(Vector2 newDir);
	void Render(SDL_Renderer* render);
	void TrySplit(std::vector<AstroidRock*>* vect);
	void UpdateAstroid();
private:
	Rigidbody* rigidbody;
	float speed;
	int size;
	Vector2 direction;
	SDL_Rect rect;
};

