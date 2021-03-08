#include "StateMachine.h"
#include "IState.h"

StateMachine::StateMachine()
{
	states.reserve(2);
}

StateMachine::~StateMachine()
{
	delete currentState;
}

void StateMachine::Initialize(int height, int width)
{
	window = SDL_CreateWindow("Astroids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SetWindowSize(Vector2(height, width));
	activeGame = true;

	MenuState* menuState = new MenuState();
	GameState* gameState = new GameState();
	states.push_back(menuState);
	states.push_back(gameState);

	menuState->Init(this);
	gameState->Init(this);

	currentState = menuState;
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
