#pragma once
#include <iostream>
#include <math.h>
#include <SDL.h>
#include <chrono>
#include <algorithm>
#include "Player.h"

using namespace std::chrono;
class GameLoop
{
public:
	SDL_Window* gameWindow;
	SDL_Renderer* renderer;
	SDL_Rect* rect;
	Player* player;
	GameLoop(int height, int width);
	~GameLoop();

	void UpdateLoop();
	void RenderUpdate();
	void GatherPlayerInput(double dt);
	void FixedUpdate(double dt);

private:
	bool* inputs;
	bool activeGame;
};

