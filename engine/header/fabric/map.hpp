#ifndef MAP_HPP
#define MAP_HPP

#include <lua.hpp>
#include <string>
#include <iostream>
#include <memory>
#include <Windows.h>
#include <vector>
#include <fabric/gameobject.hpp>

namespace fabric {


	class Map {
	public:

		int open();
		int close();
		Map(std::string fileName);
		~Map();

	private:


		int pushToTop(std::string name);
		int pushToTop(std::string name, bool __first);
		lua_State* L;
		std::vector<fabric::GameObject*> gameObjects;
		std::vector<HINSTANCE> dllHandles;
	};

}
#endif