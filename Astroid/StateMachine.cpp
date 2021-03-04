#include "StateMachine.h"

StateMachine::StateMachine()
{
	states.reserve(5);
	currentState = nullptr;
}

StateMachine::~StateMachine()
{
}

void StateMachine::Initialize(int height, int width)
{
	window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	activeGame = true;
	GameState* gameState = new GameState();
	gameState->head = this;
	states.push_back(gameState);
	currentState = gameState;
	currentState->Enter();
}

void StateMachine::UpdateLoop()
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
			currentState->Update(dt);
			t += dt;
			accumulator -= dt;
		}
		currentState->Render();
	}
}

void StateMachine::SwitchState(int index)
{
	if (index > states.size())
		return;

	currentState->Exit();
	std::cout << "switching state to state nr: " << index << std::endl;
	currentState = states[index];
	currentState->Enter();
}
