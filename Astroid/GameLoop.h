#pragma once
#include <iostream>
#include <math.h>
#include <SDL.h>
#include <chrono>
#include <algorithm>

using namespace std::chrono;
class GameLoop
{
public:
	SDL_Window* gameWindow;
	SDL_Renderer* renderer;
	SDL_Rect* rect;
	GameLoop(int height, int width);
	~GameLoop();

	void UpdateLoop();
	void RenderUpdate();
	void FixedUpdate(double dt);
	void GatherPlayerInput();

private:
	bool activeGame;
};

