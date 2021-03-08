#include "GameLoop.h"
#include "StateMachine.h"
#include "ResourceManager.h"

int main(int argc, char** argv)
{
	StateMachine* stateMachine = new StateMachine();
	std::cout << "Starting Game" << std::endl;
	stateMachine->Initialize(600, 600);
	stateMachine->UpdateLoop();
	delete stateMachine;
	std::cout << "Quitting Game" << std::endl;
	return 0;
}