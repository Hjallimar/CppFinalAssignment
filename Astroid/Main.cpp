#include "GameLoop.h"

int main(int argc, char** argv)
{
	GameLoop* game = new GameLoop(600, 600);
	std::cout << "Starting Game" << std::endl;
	game->UpdateLoop();
	delete game;
	std::cout << "Quitting Game" << std::endl;
	return 0;
}