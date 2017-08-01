#include <engine.hpp>
#include <iostream>
#include <types.hpp>
#include <gameobject.hpp>
#include <behavior.hpp>

using namespace std;
using namespace fabric;

int Engine::eventLoop() {

	for (unsigned int i = 0; i < vLoadedGameObjects->size(); i++) {
		vLoadedGameObjects->at(i)->update();
	}

	// To be debricated //
	// Asks the user for an input,
	// if it equals yes the exitRoutin is ran and the programm exits
	// else the eventloop calls it self
	char* input = new char[255];
	cin >> input;
	if (strcmp(input, "yes") == 0)
		exitRoutin();
	else 
		eventLoop();

	return 0;
}

int Engine::exitRoutin() {

	cout << "Good bye!" << endl;
	Engine::get()->del();
	return 0;
}
