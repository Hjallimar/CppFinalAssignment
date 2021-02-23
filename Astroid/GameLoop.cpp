#include "GameLoop.h"

GameLoop::GameLoop(int height, int width)
{
	gameWindow = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);
	renderer = SDL_CreateRenderer(gameWindow, -1, 0);

	rect = new SDL_Rect();
	rect->x = 250;
	rect->y = 250;
	rect->h = 50;
	rect->w = 50;

	activeGame = true;
}

GameLoop::~GameLoop()
{
	delete rect;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(gameWindow);
}

void GameLoop::UpdateLoop()
{
	double t = 0.0;
	double dt = 1.0 / 60.0;

	steady_clock::time_point currentTime = steady_clock::now();

	double accumulator = 0.0;
	while (activeGame)
	{
		steady_clock::time_point newTime = steady_clock::now();
		double frametime = (duration_cast<duration<double>>(newTime - currentTime)).count();
		accumulator += frametime;

		while (accumulator >= dt)
		{
			FixedUpdate(dt);
			t += dt;
			accumulator -= dt;
		}

		RenderUpdate();
	}
}

//Input system that uses switch/case
void GameLoop::GatherPlayerInput()
{
	SDL_Event newEvent;
	SDL_PollEvent(&newEvent);

	switch (newEvent.type)
	{
	case SDL_KEYDOWN:
		switch (newEvent.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				activeGame = false;
				break;
			case SDLK_a:
				rect->x -= 10;
				break;		
			case SDLK_w:
				rect->y -= 10;
				break;
			case SDLK_s:
				rect->y += 10;
				break;
			case SDLK_d:
				rect->x += 10;
				break;
		}
		break;
	}
}

void GameLoop::FixedUpdate(double dt)
{
	GatherPlayerInput();
	//Do stuffs that we want like move around ye?
}

void GameLoop::RenderUpdate()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, rect);

	SDL_RenderPresent(renderer);
}