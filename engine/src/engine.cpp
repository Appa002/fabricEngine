#include <engine.hpp>
#include <iostream>
#include <vector>
#include <types.hpp>
#include <gameobject.hpp>
#include <singleton.hpp>
#include <behavior.hpp>
#include <map.hpp>
#include <SDL.h>


using namespace std;
using namespace fabric;


int Engine::startRoutin() {
	cout << "Initializing Fabric Engine" << endl;
	cout << "Loading default Map" << endl;
	//Map::get()->load(new Badwater);

	cout << " " << endl;

	cout << "Initializing SDL ..." << endl;
	m_pWindow = NULL;
	m_pScreenSurface = NULL;


	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		cout << "    ... failed " << SDL_GetError() << endl; 
		return 1;
	}
	cout << "    ... scucces" << endl;

	
	cout << " " << endl;


	cout << "Creating window..." << endl;
	m_pWindow = SDL_CreateWindow("Fabric Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if (m_pWindow == NULL) {
		cout << " .. failed" << SDL_GetError() << endl;
	}
	cout << "    ... scucces" << endl;

	cout << " " << endl;


	m_pScreenSurface = SDL_GetWindowSurface(m_pWindow);
	SDL_FillRect(m_pScreenSurface, NULL, SDL_MapRGB(m_pScreenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(m_pWindow);

	Engine::get()->eventLoop();
	Engine::get()->exitRoutin();
	return 0;
}


int Engine::eventLoop() {

	for (unsigned int i = 0; i < vLoadedGameObjects->size(); i++) {
		vLoadedGameObjects->at(i)->update();
	}

	SDL_UpdateWindowSurface(m_pWindow);


	m_event = new SDL_Event();

	SDL_PollEvent(m_event);

	if (m_event->type == SDL_QUIT) {

		delete m_event;
		m_event = 0;
		return 0;
	}

	delete m_event;
	m_event = 0;

	Engine::get()->eventLoop();
	return 0;
}

int Engine::exitRoutin() {
	cout << "Good bye!" << endl;

	SDL_DestroyWindow(m_pWindow);

	SDL_Quit();

	Map::get()->unload();
	Engine::get()->del();
	return 0;
}
