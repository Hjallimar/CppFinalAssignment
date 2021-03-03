#pragma once

#include "IState.h"
#include "Player.h"
#include "Bullet.h"
#include "AstroidRock.h"
#include <vector>

[event_receiver(native)]
class GameState : public IState
{
public:
	GameState() {}
	~GameState() {}

	void Enter();
	void Update(double dt);
	void Render();
	void Exit();

	void GatherPlayerInput();
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

