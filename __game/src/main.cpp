#include <iostream>
#include <string>
#include <objectUtils.hpp>

EXPORT char* mystring = "";
EXPORT int myint = 0;


EXPORT void setup() {
	std::cout << mystring << std::endl;
}

EXPORT void update() {
	std::cout << myint << std::endl;
}