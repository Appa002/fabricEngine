#include <fabric/gameobjectHandler.hpp>

int fabric::GameObjectHandler::renderAll() {
	if (!fabric::GameObjectHandler::sorted)
		GameObjectHandler::sortVector();

	for (unsigned int i = 0; i < GameObjectHandler::gObjs.size(); i++) {
		GameObjectHandler::gObjs.at(i)->render();
	}
	
	return 0;
}

int fabric::GameObjectHandler::updateAll(){
	if (!fabric::GameObjectHandler::sorted)
		GameObjectHandler::sortVector();

	for (auto gObj : GameObjectHandler::gObjs) {
		for (auto updateFunc : gObj->updatePointers) {
			updateFunc();
		}
	}

	return 0;
}

int fabric::GameObjectHandler::setupAll()
{
	if (!fabric::GameObjectHandler::sorted)
		GameObjectHandler::sortVector();

	for (auto gObj : GameObjectHandler::gObjs) {
		for (auto setupPointer : gObj->setupPointers) {
			setupPointer();
		}
	}

	return 0;
}

int fabric::GameObjectHandler::sortVector()

{
	std::vector<GameObject*> tmp;

	for (unsigned int i = 0; i < GameObjectHandler::gObjs.size(); i++) {
		GameObject* curGameObject = GameObjectHandler::gObjs.at(i);
		
		if (tmp.size() == 0) 
			tmp.push_back(curGameObject);
		else{
			for (int j = tmp.size(); j > 0; j--) {
				if (curGameObject->priority > tmp.at(j - 1)->priority){
					tmp.insert(tmp.begin() + j, curGameObject);
					break;
				}
				else{
					if (j - 1 == 0) {
						tmp.insert(tmp.begin(), curGameObject);
					}
				}
			}
		}

	}



	return 0;
}

int fabric::GameObjectHandler::addGameObject(GameObject* gObj, bool toSort)
{
	GameObjectHandler::gObjs.push_back(gObj);
	if(toSort)
		GameObjectHandler::sortVector();
	return 0;
}

int fabric::GameObjectHandler::removeGameObjectByName(std::string name)
{
	return 0;
}