#pragma once

#include "GameObject.h"

class IComponent 
{
public:
	GameObject* parent;
	virtual void Setup(GameObject* go) = 0;
};
