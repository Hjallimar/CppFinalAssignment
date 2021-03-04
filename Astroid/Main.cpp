#include "GameLoop.h"
#include "StateMachine.h"

int main(int argc, char** argv)
{
	// Create Statemachine
	// MenuState
	StateMachine* stateMachine = new StateMachine();
	std::cout << "Starting Game" << std::endl;
	stateMachine->Initialize(1920, 1080);
	stateMachine->UpdateLoop();
	delete stateMachine;
	std::cout << "Quitting Game" << std::endl;
	return 0;
}