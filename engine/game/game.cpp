/*
Auto Generated file
Do NOT edit by hand unless you know what you're doing!
The Engine wont load when this file has an error
*/
#include <engine.hpp>


//HEADER
#include "scripts/header/Player.hpp" 


void fabric::Engine::registerGameObject(){
//ENGINE_REGISTER
	game::Player* player = new game::Player();
	fabric::Engine::vRegisteredGameObjects->push_back(player);
 

}


