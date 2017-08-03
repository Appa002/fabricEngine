#ifndef MAP_HPP
#define MAP_HPP

#include <singleton.hpp>
#include <vector>
#include <string>
#include <engine.hpp>
#include <iostream>

using namespace std;


namespace fabric {
	
	class IMap {
	public:
		virtual void load() {}
		
		void unload() {
			for (unsigned int i = 0; i < Engine::get()->vLoadedGameObjects->size(); i++) {
				delete Engine::get()->vLoadedGameObjects->at(i);
			}
		}
	};

	class Map: public Singleton<Map> {
	public:
		IMap* m_mMap;
		int load(IMap* map);
		int unload();
	};




}

#endif