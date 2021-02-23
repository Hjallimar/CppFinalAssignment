#include <iostream>
#include "SDL.h"


int main(int argc, char** argv)
{
	//Creates a window with size 800x600. The 0 stands for not fullscreen.
	SDL_Window* window =  SDL_CreateWindow("Astroid-Group 7", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	//Creates a renderer that can display things on the window.
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Rect* rect = new SDL_Rect();
	rect->x = 250;
	rect->y = 250;
	rect->h = 50;
	rect->w = 50;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer); // clears the renderer and renders the background to the color assigned above

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, rect);

	SDL_RenderPresent(renderer);

	SDL_Delay(5000); // delays the program with 5 sec

	delete rect;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Delay(5000);

	return 0;
}