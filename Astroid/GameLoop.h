#pragma once
#include <iostream>
#include <math.h>
#include <SDL.h>
#include <chrono>
#include <algorithm>
#include "Player.h"

using namespace std::chrono;
[event_receiver(native)]
class GameLoop
{
public:
	SDL_Window* GameWindow;
	SDL_Renderer* renderer;
	Player* player;
	GameLoop(int height, int width);
	~GameLoop();

	void UpdateLoop();
	void RenderUpdate();
	void GatherPlayerInput(double dt);
	void FixedUpdate(double dt);

	void OnBulletFired();

	void HookEvent(Player* pSource) {
		__hook(&Player::BulletFiredEvent, pSource, &GameLoop::OnBulletFired);
	}

	void UnhookEvent(Player* pSource) {
		__unhook(&Player::BulletFiredEvent, pSource, &GameLoop::OnBulletFired);
	}

private:
	bool activeGame;
	std::vector<Bullet*> bullets;
};

