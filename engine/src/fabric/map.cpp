#include <fabric/map.hpp>


fabric::Map::Map(std::string fileName)
{
	Map::L = luaL_newstate();
	luaL_openlibs(Map::L);

	if (luaL_loadfile(Map::L, fileName.c_str()) || lua_pcall(Map::L, 0, 0, 0)) {
		Map::L = 0;
		std::cout << "Error" << std::endl;
	}

	
}

fabric::Map::~Map()
{
	Map::close();
	lua_close(Map::L);
}

int fabric::Map::pushToTop(std::string name) {
	Map::pushToTop(name, true);
	return 0;
}


int fabric::Map::pushToTop(std::string name, bool __first)
{
	bool first = __first;
	std::string subPropertyName = "";			//example: "foo.bar.x": here foo, bar and x are subPropertyNames as they are seperated by a .
	for (unsigned int i = 0; i < name.size(); i++) {
		
		if(name.at(i) != '.') subPropertyName = subPropertyName + name.at(i);

		if (name.at(i) == '.' || i + (unsigned int)(1) >= name.size())
		{
			if (first)
				lua_getglobal(Map::L, subPropertyName.c_str());
			else
				lua_getfield(Map::L, -1, subPropertyName.c_str());

			first = false;

			if (lua_isnil(Map::L, -1)) {
				std::cout << subPropertyName.c_str() << " in " << name.c_str() << " is nil" << std::endl;
				lua_pop(Map::L, 1);
				return 1;
			}

			subPropertyName = "";
		}

	}

	return 0;
}


int fabric::Map::close() {

	for (unsigned int gameObjectIndex = 0; gameObjectIndex < Map::gameObjects.size(); gameObjectIndex++) {
		Map::gameObjects.at(gameObjectIndex)->free();

		delete Map::gameObjects.at(gameObjectIndex);
		Map::gameObjects.erase(Map::gameObjects.begin() + gameObjectIndex);
		
	}
	return 0;
}

typedef void(*functionType)();
int fabric::Map::open(){
	pushToTop("game_objects.amount");
	int amount = (int)lua_tointeger(Map::L, -1);
	lua_pop(Map::L, 1);

	for (int idx = 0; idx < amount; idx++) {
		pushToTop("game_objects.object_" + std::to_string(idx)); // "game_objects.object_" + idx
		pushToTop("path", false); // Stack looks like:  ["path"] ["object_" + idx] ["game_objects"]
		std::string path = std::string(lua_tostring(Map::L, -1)); // ["path"] gets turned into string
		
		lua_remove(Map::L, -1); // ["path"] gets poped from stack
		
		GameObject* gObj = new GameObject();

		HINSTANCE dllHandle = LoadLibrary(("./__game/" + path).c_str()); // "./__game/" + path
		gObj->dllHandle = dllHandle;

		gObj->setupPointer = (functionType)(GetProcAddress(dllHandle, "setup"));
		gObj->updatePointer = (functionType)(GetProcAddress(dllHandle, "update"));

		pushToTop("amount", false); // Stack looks like:  ["amount"] ["object_" + idx] ["game_objects"]

		int amountAttributes = (int)lua_tointeger(Map::L, -1); 

		lua_remove(Map::L, -1); // ["amount"] gets poped from stack

		for (int jdx = 0; jdx < amountAttributes; jdx++) {
			pushToTop("attribute_" + std::to_string(jdx), false);

			pushToTop("name", false);
			std::string name = std::string(lua_tostring(Map::L, -1));
			lua_remove(Map::L, -1);

			pushToTop("type", false);
			std::string type = std::string(lua_tostring(Map::L, -1));
			lua_remove(Map::L, -1);

			pushToTop("content", false);

			if (type == "int") {
				gObj->addAttribute<int>(name, (int*)GetProcAddress(dllHandle, name.c_str()));
				gObj->setAttribute<int>(name, (int)lua_tointeger(Map::L, -1));
			}

			else if (type == "string") {
				gObj->addAttribute<char*>(name, (char**)GetProcAddress(dllHandle, name.c_str()));
				gObj->setAttribute<char*>(name, (char*)lua_tostring(Map::L, -1));
			}


			else if (type == "boolean") {
				gObj->addAttribute<bool>(name, (bool*)GetProcAddress(dllHandle, name.c_str()));
				gObj->setAttribute<bool>(name, (bool)lua_toboolean(Map::L, -1));
			}


			else if (type == "double") {
				gObj->addAttribute<double>(name, (double*)GetProcAddress(dllHandle, name.c_str()));
				gObj->setAttribute<double>(name, (double)lua_tonumber(Map::L, -1));
			}

			else
				return 1;

			lua_remove(Map::L, -1);
			lua_remove(Map::L, -1);

		}
		lua_pop(Map::L, 1);
		gObj->setupPointer();
		gObj->updatePointer();
	
		dllHandles.push_back(dllHandle);
		gameObjects.push_back(gObj);
	
	}



	return 0;
}