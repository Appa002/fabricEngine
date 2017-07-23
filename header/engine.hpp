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
		void loadGameObject(GameObject* gObj);
		void registerGameObject(); // This is not defined engine.cpp, but in the game.cpp

		Engine() {
			vLoadedGameObjects = new vector<GameObject*>;
			vRegisteredGameObjects = new vector<GameObject *>;
		}

		~Engine() {
			delete vLoadedGameObjects;
			vLoadedGameObjects = 0;
		
			delete vRegisteredGameObjects;
			vRegisteredGameObjects = 0;
		}
	
	private:

		vector<GameObject*>* vLoadedGameObjects;
		vector<GameObject *>* vRegisteredGameObjects;

		// Called from the eventloop when the programms exits
		int exitRoutin();

		
	};

}

#endif // !ENGINE_HPP
