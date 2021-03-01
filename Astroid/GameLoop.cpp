#include "GameLoop.h"

GameLoop::GameLoop(int height, int width)
{
	gameWindow = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);
	renderer = SDL_CreateRenderer(gameWindow, -1, 0);
	inputs = new bool[4];
	for (int i = 0; i < 4; i++)
	{
		inputs[i] = false;
	}
	player = new Player();
	player->position.x = 300;
	player->position.y = 300;
	player->UpdateRect();
	activeGame = true;
}

GameLoop::~GameLoop()
{
	delete player;
	delete[] inputs;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(gameWindow);
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
				inputs[0] = true;
				break;		
			case SDLK_w:
				inputs[1] = true;
				break;
			case SDLK_d:
				inputs[2] = true;
				break;
		}
		break;
	case SDL_KEYUP:
		switch (newEvent.key.keysym.sym)
		{
		case SDLK_a:
			inputs[0] = false;
			break;
		case SDLK_w:
			inputs[1] = false;
			break;
		case SDLK_d:
			inputs[2] = false;
			break;
		}
		break;
	}
}

void GameLoop::FixedUpdate(double dt)
{
	GatherPlayerInput();
	if (inputs[0])
		player->Rotate(-5 * dt);
	if (inputs[2])
		player->Rotate(5 * dt);
	if (inputs[1])
		player->Move(100 * dt);

	//Do stuffs that we want like move around ye?
}

void GameLoop::RenderUpdate()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &(player->playerRect));

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &(player->dirrRect));

	SDL_RenderPresent(renderer);
}