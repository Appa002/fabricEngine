#include <behavior.hpp>
#include <iostream>

void fabric::Behavior::setup() {
	std::cout << "Intilized" << std::endl;
}

void fabric::Behavior::update() {
	std::cout << "Updated" << std::endl;

}