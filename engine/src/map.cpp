#include <map.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;
using namespace fabric;

typedef vector<GameObject *>*(*f_loadmap)();

///TODO: Linux and Mac compatibility

int Map::load(char* path) {
	// Load the map dll into memory
	HINSTANCE hGetProcIDLL = LoadLibrary(path);

	cout << path << endl;

	if (!hGetProcIDLL) {
		cout << "Could not load DLL at " << path << endl;
		return EXIT_FAILURE;
	}

	// Get adress to the loadmap function defied in the DLL
	f_loadmap loadmap = (f_loadmap)GetProcAddress(hGetProcIDLL, "loadmap");

	if (!loadmap) {
		cout << "Could not get loadmap function" << endl;
		return EXIT_FAILURE;
	}

	// For safety delete the vLoadedGameObjects Pointer
	delete Engine::get()->vLoadedGameObjects;

	// Execute load and overwrite the vLoadedGameopjects pointer
	Engine::get()->vLoadedGameObjects = loadmap();

	// Spawn all Behaviors for the gameobjs
	for (unsigned int i = 0; i < Engine::get()->vLoadedGameObjects->size(); i++) {
		Engine::get()->vLoadedGameObjects->at(i)->spawn();
	}

	std::cout << "Loaded ";
	std::cout << Engine::get()->vLoadedGameObjects->size();
	std::cout << " entitie(s)" << std::endl;

	m_mMap = &hGetProcIDLL;

	// Call Setup on just loaded gameobjects
	for (unsigned int i = 0; i < Engine::get()->vLoadedGameObjects->size(); i++) {
		Engine::get()->vLoadedGameObjects->at(i)->setup();
	}

	return 0;

}


int Map::unload() {
	std::cout << "Unloading..." << std::endl;
	
	if (m_mMap) {
		FreeLibrary(*m_mMap);
		delete m_mMap;
		m_mMap = 0;
	}


	std::cout << "Unloaded..." << std::endl;
	return 0;
}
