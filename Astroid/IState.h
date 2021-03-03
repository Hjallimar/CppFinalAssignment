#pragma once

#include "StateMachine.h"

class IState
{
public:
	StateMachine* head;
	virtual void Enter() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;
};