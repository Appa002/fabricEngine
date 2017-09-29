#ifndef MAP_HPP
#define MAP_HPP

#include <lua.hpp>
#include <string>
#include <iostream>
#include <memory>
#include <fabric/gameobjectHandler.hpp>
#include <Windows.h>
#include <vector>
#include <fabric/gameobject.hpp>

namespace fabric {


	class Map {
	public:

		int open(std::string fileName);
		int close();
		Map();
		~Map();

	private:
		int pushToTop(std::string name, lua_State* L);
		int pushToTop(std::string name, lua_State* L, bool __first);
		lua_State* L;
	};

}
#endif