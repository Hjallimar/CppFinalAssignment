#pragma once

#include "SDL.h"
#include "IState.h"
#include "Math.h"
#include <vector>
#include <chrono>

class IState;

using namespace std::chrono;
class StateMachine
{
	friend class IState;

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
	void SetWindowSize(Vector2 v) { windowSize = v; }
	Vector2 GetWindowSize() { return windowSize; }
	
private:
	bool activeGame;
	Vector2 windowSize;
	std::vector<IState*> states;
	IState* currentState; 
};

