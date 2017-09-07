#define UNIT_CATCH_UNIT_ERRORS
#include <fabric/unit_framework.hpp>
#include <fabric/engine.hpp>
#include <fabric/tests.hpp>

#include <fabric/map.hpp>
#include <Windows.h>


int main(int argc, char* argv[]){
	fabric::Map* map = new fabric::Map("__game/badwater.lua");

	map->open();

	delete map;
//	fabric::Engine::get()->startRoutin();
	
//	fabric::tests::registerTests();

//	fabric::UnitTestFramework::get()->doTests();
	while (std::cin.get() == 0);
	return 0;
}