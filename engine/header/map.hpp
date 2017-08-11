#ifndef MAP_HPP
#define MAP_HPP

#include <singleton.hpp>
#include <vector>
#include <string>
#include <engine.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;


namespace fabric {

	class Map: public Singleton<Map> {
	public:
		HINSTANCE* m_mMap = 0;
		int load(char* path);
		int unload();
	};

}

#endif