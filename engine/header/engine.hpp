#include <singleton.hpp>
#include <vector>
#include <types.hpp>
#include <gameobject.hpp>

#ifndef ENGINE_HPP
#define ENGINE_HPP

namespace fabric {
	// The class holding all Engine stuff
	// There will always only be one therfor the Singleton inheritence
	class Engine : public fabric::Singleton<Engine>
	{
	public:
		// Main Eventloop
		// Calls it self till programm exits
		int eventLoop();

		Engine() {
			vLoadedGameObjects = new vector<GameObject*>;
		}

		~Engine() {
			delete vLoadedGameObjects;
			vLoadedGameObjects = 0;
		}
	
	private:

		vector<GameObject*>* vLoadedGameObjects;

		// Called from the eventloop when the programms exits
		int exitRoutin();

		
	};

}

#endif // !ENGINE_HPP
