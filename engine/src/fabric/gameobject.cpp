#include <fabric/gameobject.hpp>

void defaultUpdate() {
	std::cout << "Default update called, is the gameobject correctly setup?" << std::endl;
}

void defaultSetup() {
	std::cout << "Default setup called, is the gameobject correctly setup?" << std::endl;
}

fabric::GameObject::GameObject() {

	Attribute attr;
	attr.content = new int(0);
	attr.hash = typeid(int).hash_code();		// Initilize placeholder attribute so attributes.size() doesnt crash the code
	attr.name = ""; 

	GameObject::attributes.push_back(attr);
	GameObject::updatePointer = &defaultUpdate;
	GameObject::updatePointer = &defaultSetup;
}

fabric::GameObject::~GameObject() {
	GameObject::removeAttribute<int>("");
	if (GameObject::attributes.size() > 0)
		std::cout << "Not all attributes have been removed" << std::endl;

}

std::vector<fabric::Attribute> fabric::GameObject::getAttributeVector()
{
	return *const_cast<const std::vector<Attribute>*>(&attributes);
}

fabric::Attribute fabric::GameObject::getAttribute(std::string name)
{
	for (unsigned int i = 0; i < GameObject::attributes.size(); i++) {
		if (GameObject::attributes.at(i).name == name) {
			return GameObject::attributes.at(i);
		}
	}


	return GameObject::getAttribute("");
}