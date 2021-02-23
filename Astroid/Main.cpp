#include "GameLoop.h"

int main(int argc, char** argv)
{
	GameLoop* game = new GameLoop(800, 600);
	std::cout << "Starting Game" << std::endl;
	game->UpdateLoop();
	delete game;
	std::cout << "Quitting Game" << std::endl;
	SDL_Delay(5000);
	return 0;
}