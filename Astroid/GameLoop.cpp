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
void GameLoop::GatherPlayerInput(double dt)
{
	SDL_PumpEvents();
	const Uint8* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_LEFT])
		player->Rotate(-5 * dt);
	if (state[SDL_SCANCODE_RIGHT])
		player->Rotate(5 * dt);
	if (state[SDL_SCANCODE_UP])
		player->Move(100 * dt);

	
}

void GameLoop::FixedUpdate(double dt)
{
	GatherPlayerInput(dt);
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