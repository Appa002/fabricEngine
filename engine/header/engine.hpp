#include <singleton.hpp>
#include <vector>
#include <types.hpp>
#include <gameobject.hpp>
#include <SDL.h>

#ifndef ENGINE_HPP
#define ENGINE_HPP

namespace fabric {
	// The class holding all Engine stuff
	// There will always only be one therfor the Singleton inheritence
	class Engine : public fabric::Singleton<Engine>
	{
	public:

		vector<GameObject*>* vLoadedGameObjects = 0;

		// Main Eventloop
		// Calls it self till programm exits
		int startRoutin();

		Engine() {
			vLoadedGameObjects = new vector<GameObject*>;
		}

		~Engine() {
			delete vLoadedGameObjects;
			vLoadedGameObjects = 0;
		}
	
	private:

		SDL_Window* m_pWindow = 0;
		SDL_Surface* m_pScreenSurface = 0;
		SDL_Event m_event;

		// Called from the eventloop when the programms exits
		int exitRoutin();
		int eventLoop();

		
	};

}

#endif // !ENGINE_HPP
