#ifndef GAMEOBJECTHANDLER_HPP
#define GAMEOBJECTHANDLER_HPP

#include <fabric/singleton.hpp>
#include <fabric/gameobject.hpp>
#include <vector>

namespace fabric {
	class GameObjectHandler: public Singleton<GameObjectHandler>{
	public:
		int updateAll();
		int setupAll();
		int sortVector();
		int renderAll();
		int addGameObject(GameObject* gObj, bool sorted);
		int removeGameObjectByName(std::string name);
		std::vector<GameObject*> gObjs;

	private:
		bool sorted = false;
		
	};
}

#endif