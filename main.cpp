#define UNIT_CATCH_UNIT_ERRORS
#include <fabric/unit_framework.hpp>
#include <fabric/engine.hpp>
#include <fabric/tests.hpp>

#include <fabric/map.hpp>
#include <fabric/gameobjectHandler.hpp>
#include <Windows.h>


using namespace fabric;

int main(int argc, char* argv[]){

	

	Map* map = new Map("./__game/badwater.lua");

	map->open();
	GameObjectHandler::get()->updateAll();


	delete map;


	fabric::Engine::get()->startRoutin();
	
	

//	fabric::tests::registerTests();
//	fabric::UnitTestFramework::get()->doTests();
	return 0;
}