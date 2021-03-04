#include "IState.h"


MenuState::~MenuState()
{
}

void MenuState::Init(StateMachine* newHead)
{
	head = newHead;
}

void MenuState::Enter()
{
	std::cout << "Enter MenuState" << std::endl;
}

void MenuState::Update(double dt)
{
	GatherPlayerInput();
}

void MenuState::Render()
{
	SDL_SetRenderDrawColor(head->renderer, 0, 0, 0, 255);
	SDL_RenderClear(head->renderer);

	SDL_SetRenderDrawColor(head->renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(head->renderer, 200, 400, 400, 300);
	SDL_RenderDrawLine(head->renderer, 200, 200, 400, 300);
	SDL_RenderDrawLine(head->renderer, 200, 200, 200, 400);

	SDL_RenderPresent(head->renderer);
}

void MenuState::Exit()
{
	std::cout << "Exit MenuState" << std::endl;
}

void MenuState::GatherPlayerInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{
				case SDLK_SPACE:
					std::cout << "Space pressed" << std::endl;
					head->SwitchState(1);
					break;
				case SDLK_ESCAPE:
					head->SetActiveGame(false);
					break;
			}
		}
	}
}
