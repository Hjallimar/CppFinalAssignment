#include "GameLoop.h"

GameLoop::GameLoop(int height, int width)
{
	GameWindow = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);
	renderer = SDL_CreateRenderer(GameWindow, -1, 0);
	player = new Player();
	player->setPosition(Vector2(300, 300));
	activeGame = true;
}

GameLoop::~GameLoop()
{
	delete player;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(GameWindow);
}

void GameLoop::UpdateLoop()
{
	double t = 0.0;
	double dt = 1.0 / 60.0;

	steady_clock::time_point currentTime = steady_clock::now();
	double timeChecker = 0;
	double accumulator = 0.0;
	while (activeGame)
	{
		steady_clock::time_point newTime = steady_clock::now();
		double frametime = (duration_cast<duration<double>>(newTime - currentTime)).count();
		currentTime = newTime;
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
void GameLoop::GatherPlayerInput(double dt)
{
	SDL_PumpEvents();
	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_LEFT])
		player->Rotate(false);
	if (state[SDL_SCANCODE_RIGHT])
		player->Rotate(true);
	if (state[SDL_SCANCODE_UP])
		player->ThrustForward();
	else if (!state[SDL_SCANCODE_UP])
		player->Deaccelerate();
	if (state[SDL_SCANCODE_ESCAPE])
		activeGame = false;	
}

void GameLoop::FixedUpdate(double dt)
{
	GatherPlayerInput(dt);
	player->Update();
}

void GameLoop::RenderUpdate()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	player->RenderPlayer(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	/*
	SDL_RenderDrawLine(renderer, 100, 0, 100, 600);
	SDL_RenderDrawLine(renderer, 200, 0, 200, 600);
	SDL_RenderDrawLine(renderer, 300, 0, 300, 600);
	SDL_RenderDrawLine(renderer, 400, 0, 400, 600);
	SDL_RenderDrawLine(renderer, 500, 0, 500, 600);
	SDL_RenderDrawLine(renderer, 600, 0, 600, 600);
	SDL_RenderDrawLine(renderer, 700, 0, 700, 600);*/

	SDL_RenderPresent(renderer);
}