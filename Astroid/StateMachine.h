#pragma once

#include "SDL.h"
#include "GameState.h"
#include <vector>
#include <chrono>

class IState;

using namespace std::chrono;
class StateMachine
{
public:
	SDL_Window* window;
	SDL_Renderer* renderer;

	StateMachine();
	~StateMachine();

	void Initialize(int height, int width);
	void UpdateLoop();
	void SwitchState(int index); // enum or smth
	// -1 Exit, 0 Menu, 1 Game

	void SetActiveGame(bool b) { activeGame = b; }

private:
	bool activeGame;
	std::vector<IState*> states;
	IState* currentState;
};

