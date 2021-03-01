#pragma once

#include "GameObject.h"

class IComponent 
{
public:
	GameObject* parent;
	virtual void setup(GameObject* go) = 0;
};
