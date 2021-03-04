#pragma once

#include "StateMachine.h"
#include <iostream>

class StateMachine;

class IState
{
public:
	virtual void Init(StateMachine* newHead) = 0;
	virtual void Enter() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;
	virtual void GatherPlayerInput() = 0;
	virtual ~IState() {}

	StateMachine* head;
};

#include "Player.h"
#include "Bullet.h"
#include "AstroidRock.h"
#include <vector>

[event_receiver(native)]
class GameState : public IState
{
public:
	~GameState();

	virtual void Init(StateMachine* newHead);
	virtual void Enter();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	virtual void GatherPlayerInput();
	void OnBulletFired();
	void CheckCollisions();

	void HookEvent(Player* pSource) {
		__hook(&Player::BulletFiredEvent, pSource, &GameState::OnBulletFired);
	}

	void UnhookEvent(Player* pSource) {
		__unhook(&Player::BulletFiredEvent, pSource, &GameState::OnBulletFired);
	}

private:
	Player* player;
	std::vector<Bullet*> bullets;
	std::vector<AstroidRock*> rocks;
};

class MenuState : public IState
{
public:
	~MenuState();

	virtual void Init(StateMachine* newHead);
	virtual void Enter();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	virtual void GatherPlayerInput();
};


