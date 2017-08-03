#include <map.hpp>
#include <iostream>

using namespace std;
using namespace fabric;


int Map::load(IMap* map) {
	m_mMap = map;
	std::cout << "Loading..." << std::endl;
	map->load();

	// Spawn all Behaviors for the gameobjs
	for (unsigned int i = 0; i < Engine::get()->vLoadedGameObjects->size(); i++) {
		Engine::get()->vLoadedGameObjects->at(i)->spawn();
	}

	std::cout << "Loaded ";
	std::cout << Engine::get()->vLoadedGameObjects->size();
	std::cout << " entitie(s)" << std::endl;

	// Call Setup on just loaded gameobjects
	for (unsigned int i = 0; i < Engine::get()->vLoadedGameObjects->size(); i++) {
		Engine::get()->vLoadedGameObjects->at(i)->setup();
	}


	return 0;
}


int Map::unload() {
	std::cout << "Unloading..." << std::endl;
	m_mMap->unload();
	std::cout << "Unloaded..." << std::endl;
	return 0;
}
