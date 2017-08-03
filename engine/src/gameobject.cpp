#include <gameobject.hpp>
#include <types.hpp>
#include <behavior.hpp>
#include <iostream>

using namespace std;
using namespace fabric;

void GameObject::update() {

	for (unsigned int i = 0; i < vLinkNet->size(); i++) {
		// Get the type the Link connects by casting the void pointer
		// to the class ILink wich all Links implement
		string sType = static_cast<ILink *>(vLinkNet->at(i))->sType;

		// Check what type it is, and cast into the List class with that type
		// update is called on the list class
		if (sType == "string")
			static_cast<Link<string> *>(vLinkNet->at(i))->update();

		else if (sType == "int")
			static_cast<Link<int> *>(vLinkNet->at(i))->update();

		else if (sType == "char")
			static_cast<Link<char> *>(vLinkNet->at(i))->update();

		else if (sType == "long")
			static_cast<Link<long> *>(vLinkNet->at(i))->update();

		else if (sType == "double")
			static_cast<Link<double> *>(vLinkNet->at(i))->update();

		else if (sType == "behavior")
			static_cast<Link<Behavior> *>(vLinkNet->at(i))->update();

		else if (sType == "gameobject")
			static_cast<Link<GameObject> *>(vLinkNet->at(i))->update();
		else
			cout << "ERROR ' " << sType.c_str() << " ' is not a registered type! " << endl;
	}
}

int GameObject::spawn() {
	return 0;
}

template <class T>
int GameObject::link(T* link) {
	return 0;
}