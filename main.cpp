#define UNIT_CATCH_UNIT_ERRORS
#include <fabric/unit_framework.hpp>
#include <fabric/engine.hpp>
#include <fabric/map.hpp>
#include <fabric/gameobjectHandler.hpp>

#include <fabric/engineObj.hpp>

using namespace fabric;


int main(int argc, char* argv[]){
	fabric::Engine::get()->startRoutin();
	
	return 0;
}