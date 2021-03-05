#include "GameLoop.h"
#include "StateMachine.h"
#include "ResourceManager.h"

void WhoooDoMe()
{
	//ResourceManager manager = ResourceManager();
	//manager.AssignBase("External");

	//int i = 10;
	//float j = 13.37f;
	//std::string value = "Sick Value bro";

	//manager.AddItem<int>("First", &i);
	//manager.AddItem<float>("Second", &j);
	//manager.AddItem<std::string>("Third", &value);
	//manager.AddItemFromPath("Test.txt");

	//std::shared_ptr<std::ofstream> temp = manager.GetItem<std::ofstream>("Test.txt");



	//std::cout << "Geting things from list: first-" << manager.GetItem<int>("First") << " | Second-" << manager.GetItem<float>("Second")
	//	<< " | Third-" << manager.GetItem<std::string>("Third") << std::endl;
}

int main(int argc, char** argv)
{
	//test for resource manager
	//WhoooDoMe();
	//return 0;

	// Create Statemachine
	// MenuState
	StateMachine* stateMachine = new StateMachine();
	std::cout << "Starting Game" << std::endl;
	stateMachine->Initialize(600, 600);
	stateMachine->UpdateLoop();
	delete stateMachine;
	std::cout << "Quitting Game" << std::endl;
	return 0;
}