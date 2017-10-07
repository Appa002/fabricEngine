#ifndef MAP_HPP
#define MAP_HPP

#include <lua.hpp>
#include <string>
#include <iostream>
#include <memory>
#include <fabric/gameobjectHandler.hpp>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <cctype>
#include <fabric/types.hpp>
#include <fabric/gameobject.hpp>
#include <fabric/engineObj.hpp>


namespace fabric {

	class Map : public EngineObject {
	public:

		std::vector<vec3> loadObjFromFile(std::string src);
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