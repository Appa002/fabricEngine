#include <fabric/map.hpp>


fabric::Map::Map()
{
}

fabric::Map::~Map()
{
	Map::close();
	lua_close(Map::L);
}

int fabric::Map::pushToTop(std::string name, lua_State* L) {
	Map::pushToTop(name, L, true);
	return 0;
}


int fabric::Map::pushToTop(std::string name, lua_State* L, bool __first)
{
	bool first = __first;
	std::string subPropertyName = "";			//example: "foo.bar.x": here foo, bar and x are subPropertyNames as they are seperated by a .
	for (unsigned int i = 0; i < name.size(); i++) {

		if (name.at(i) != '.') subPropertyName = subPropertyName + name.at(i);

		if (name.at(i) == '.' || i + (unsigned int)(1) >= name.size())
		{
			if (first)
				lua_getglobal(L, subPropertyName.c_str());
			else
				lua_getfield(L, -1, subPropertyName.c_str());

			first = false;

			if (lua_isnil(L, -1)) {
				std::cout << subPropertyName.c_str() << " in " << name.c_str() << " is nil" << std::endl;
				lua_pop(L, 1);
				return 1;
			}

			subPropertyName = "";
		}

	}

	return 0;
}


int fabric::Map::close() {

	for (unsigned int gameObjectIndex = 0; gameObjectIndex < GameObjectHandler::get()->gObjs.size(); gameObjectIndex++) {
		GameObjectHandler::get()->gObjs.at(gameObjectIndex)->free();

		delete GameObjectHandler::get()->gObjs.at(gameObjectIndex);
		GameObjectHandler::get()->gObjs.erase(GameObjectHandler::get()->gObjs.begin() + gameObjectIndex);

	}
	return 0;
}



typedef void(*functionType)();
int fabric::Map::open(std::string fileName) {


	Map::L = luaL_newstate();
	luaL_openlibs(Map::L);

	if (luaL_loadfile(Map::L, fileName.c_str()) || lua_pcall(Map::L, 0, 0, 0)) {
		Map::L = 0;
		std::cout << "Error" << std::endl;
	}


	pushToTop("data.size", Map::L);
	int gameObjectSize = (int)lua_tointeger(Map::L, -1);
	lua_pop(Map::L, 1);

	for (int idx = 0; idx < gameObjectSize; idx++) {
		pushToTop("data.object_" + std::to_string(idx), Map::L);
		std::string path = std::string((char*)lua_tostring(Map::L, -1));
		lua_pop(Map::L, 1);

		lua_State* curGameObjectFile = luaL_newstate();
		luaL_openlibs(curGameObjectFile);

		if (luaL_loadfile(curGameObjectFile, ("./__game/" + path).c_str()) || lua_pcall(curGameObjectFile, 0, 0, 0)) {
			curGameObjectFile = 0;
			std::cout << "Error" << std::endl;
		}



		pushToTop("data.size", curGameObjectFile);
		unsigned int dllAmount = (unsigned int)lua_tointeger(curGameObjectFile, -1);
		lua_pop(curGameObjectFile, 1);


		GameObject* gObj = new GameObject();

		for (size_t jdx = 0; jdx < dllAmount; jdx++) {
			pushToTop("data.dll_" + std::to_string(jdx), curGameObjectFile);
			pushToTop("path", curGameObjectFile, false);

			std::string dllPath = std::string((char*)lua_tostring(curGameObjectFile, -1));
			lua_remove(curGameObjectFile, -1);

			HINSTANCE dllHandle = LoadLibrary(dllPath.c_str());
		
			gObj->dllHandles.push_back(dllHandle);
			gObj->setupPointers.push_back((functionType)(GetProcAddress(dllHandle, "setup")));
			gObj->updatePointers.push_back((functionType)(GetProcAddress(dllHandle, "update")));

			pushToTop("size", curGameObjectFile, false);
			unsigned int attrAmount = (unsigned int)lua_tonumber(curGameObjectFile, -1);
			lua_remove(curGameObjectFile, -1);

			for (size_t attrIdx = 0; attrIdx < attrAmount; attrIdx++)
			{
				pushToTop("attribute_" + std::to_string(attrIdx), curGameObjectFile, false);

				pushToTop("name", curGameObjectFile, false);
				std::string name = std::string((char*)lua_tostring(curGameObjectFile, -1));
				lua_remove(curGameObjectFile, -1);

				// Basic name mangeling
				std::string mangledName = std::to_string(jdx) + "$" + name;
				//


				pushToTop("type", curGameObjectFile, false);
				std::string type = std::string(lua_tostring(curGameObjectFile, -1));
				lua_remove(curGameObjectFile, -1);

				pushToTop("content", curGameObjectFile, false);

				if (type == "int") {
					gObj->addAttribute<int>(mangledName, (int*)GetProcAddress(dllHandle, name.c_str()));
					gObj->setAttribute<int>(mangledName, (int)lua_tointeger(curGameObjectFile, -1));
				}

				else if (type == "string") {
					gObj->addAttribute<char*>(mangledName, (char**)GetProcAddress(dllHandle, name.c_str()));
					gObj->setAttribute<char*>(mangledName, (char*)lua_tostring(curGameObjectFile, -1));
				}


				else if (type == "boolean") {
					gObj->addAttribute<bool>(mangledName, (bool*)GetProcAddress(dllHandle, name.c_str()));
					gObj->setAttribute<bool>(mangledName, (bool)lua_toboolean(curGameObjectFile, -1));
				}


				else if (type == "double") {
					gObj->addAttribute<double>(mangledName, (double*)GetProcAddress(dllHandle, name.c_str()));
					gObj->setAttribute<double>(mangledName, (double)lua_tonumber(curGameObjectFile, -1));
				}
				else if (type == "vec3"){
					vec3 myVec;

					pushToTop("x", curGameObjectFile, false);
					double x = (double)lua_tonumber(curGameObjectFile, -1);
					lua_remove(curGameObjectFile, -1);

					pushToTop("y", curGameObjectFile, false);
					double y = (double)lua_tonumber(curGameObjectFile, -1);
					lua_remove(curGameObjectFile, -1);

					pushToTop("z", curGameObjectFile, false);
					double z = (double)lua_tonumber(curGameObjectFile, -1);
					lua_remove(curGameObjectFile, -1);

					myVec.x = x;
					myVec.y = y;
					myVec.z = z;

					gObj->addAttribute<vec3>(mangledName, (vec3*)GetProcAddress(dllHandle, name.c_str()));
					gObj->setAttribute<vec3>(mangledName, myVec);

				}

				else
					return 1;

				lua_remove(curGameObjectFile, -1);
				lua_remove(curGameObjectFile, -1);

			}


		}



		std::vector<vec3> _data = loadObjFromFile("__game/cube.obj");
		Mesh mesh = Mesh();

		mesh.make(_data);
		gObj->setMesh(mesh);
		GameObjectHandler::get()->addGameObject(gObj, true);

	}





	return 0;
}

std::vector<fabric::vec3> fabric::Map::loadObjFromFile(std::string src)
{
	std::vector<double> vertices;
	std::vector<vec3> faces;
	std::ifstream fileStream(src);

	if (!fileStream) {
		std::cout << "Couldn't open model " + src << std::endl;
		return faces;
	}

	while (fileStream) {
		std::string curLine = "";
		std::getline(fileStream, curLine);

		
		// Load Vertices
		if (curLine[0] == 'v' && curLine[1] != 'n' && curLine != "") {
			std::string num = "";
			
			for (size_t i = 2; i < curLine.size(); i++){
				if (curLine.at(i) == ' ' || i + 1 >= curLine.size()) {
					
					if (i + 1 >= curLine.size()) num += curLine.at(i); 
					vertices.push_back(std::stod(num));

					num = "";
					
				}else
					num += curLine.at(i);
		
					
			}
		}
		
		// Load faces (this will allways happen after all Vertices are loaded)
		if (curLine[0] == 'f'  && curLine != "") {
			std::string num;
			vec3 vec;


			for (size_t i = 2; i < curLine.size(); i++) {
				if (curLine.at(i) == '/') {	
					
					size_t vertIndexX = (stod(num) - 1) * 3;
					size_t vertIndexY = vertIndexX + 1;
					size_t vertIndexZ = vertIndexX + 2;

					vec.x = vertices.at(vertIndexX);
					vec.y = vertices.at(vertIndexY);
					vec.z = vertices.at(vertIndexZ);

					std::cout << num << std::endl;

						
					num = "";

					while (curLine.at(i) != ' ') { 
						if (i + 1 >= curLine.size()) {
							faces.push_back(vec);
							vec = vec3();					
							break;
						}
						i++;
					}
						

				}
				else
					num += curLine.at(i);
			}
		}

	}


	return faces;
}