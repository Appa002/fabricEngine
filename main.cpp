#define UNIT_CATCH_UNIT_ERRORS
#include <fabric/unit_framework.hpp>
#include <fabric/engine.hpp>


using namespace fabric;

int main(int argc, char* argv[]){

	fabric::Engine::get()->startRoutin();
	

//	fabric::tests::registerTests();
//	fabric::UnitTestFramework::get()->doTests();
	return 0;
}