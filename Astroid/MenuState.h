#pragma once

#include "IState.h"

class MenuState : public IState
{
public:
	void Enter();
	void Update(double dt);
	void Render();
	void Exit();
};

