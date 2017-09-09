#ifndef  GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <string>
#include <fabric/types.hpp>
#include <typeinfo>
#include <exception>
#include <memory>
#include <iostream>
#include <bitset>
#include <Windows.h>

namespace fabric {
	class Attribute
	{
	public:

		int isValid() {
			int out = true;
			if (name == "")
				out = false;
			if (content == 0)
				out = false;
			if (hash == 0)
				out = false;
			return out;
		}

		void* content = 0;
		size_t hash = 0;
		std::string name = "";
	};

	class  GameObject 
	{
	public:

		HINSTANCE dllHandle;
		
		void(*updatePointer)();
		void(*setupPointer)();

		GameObject();
		~GameObject();

		void free();
		std::vector<Attribute> getAttributeVector();
		Attribute getAttribute(std::string name);
		template<typename T> void addAttribute(std::string name, T* content);
		template<typename T> void setAttribute(std::string name, T content);
		template<typename T> void removeAttribute(std::string name);
		template<typename T> Attribute findAttribute(std::string name);
		template<typename T> Attribute findAttribute(std::string name, unsigned int* idx);

	private:
		std::vector<Attribute> attributes;
		
	};
}

template<typename T>
inline fabric::Attribute fabric::GameObject::findAttribute(std::string name)
{
	return GameObject::findAttribute<T>(name, 0);
}

template<typename T> fabric::Attribute fabric::GameObject::findAttribute(std::string name, unsigned int* idx)
{
	for (unsigned int i = 0; i < GameObject::attributes.size(); i++) {
		if (GameObject::attributes.at(i).name == name) {

			if (GameObject::attributes.at(i).hash != typeid(T).hash_code()) {
				throw std::runtime_error("Type dont match!");
			}
			if(idx != 0)
				*idx = i;
			return GameObject::attributes.at(i);
		}
	}
	throw std::runtime_error("No such attribute");
}

template<typename T>
inline void fabric::GameObject::setAttribute(std::string name, T content)
{
	Attribute attr = findAttribute<T>(name);
	*reinterpret_cast<T*>(attr.content) = content;
}

template<typename T>
inline void fabric::GameObject::removeAttribute(std::string name)
{
	unsigned int i = 0;
	Attribute attr = findAttribute<T>(name, &i);
	delete reinterpret_cast<T*>(attr.content);
	GameObject::attributes.erase(GameObject::attributes.begin() + i);
	
}

template<typename T>
inline void fabric::GameObject::addAttribute(std::string name, T* content)
{

	for (unsigned int i = 0; i < GameObject::attributes.size(); i++) {
		if (GameObject::attributes.at(i).name == name) {
			throw std::runtime_error("Such element allrady exists");
		}
	}

	Attribute attrib;
	attrib.name = name;
	attrib.content = content;
	attrib.hash = typeid(T).hash_code();

	GameObject::attributes.push_back(attrib);

}

#endif // ! GAMEOBJECT_HPP