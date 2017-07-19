#include <singleton.hpp>
#include <vector>

#ifndef ENGINE_HPP
#define ENGINE_HPP

namespace fabric {
	

	// Struct holding the two Variables to be Linked
	// T must be the same for both Variables
	struct Link
	{
		template<class T>
		T* pSender;

		template<class T>
		T* pReciver;
	};


	// The class holding all Engine stuff
	// There will always only be one therfor the Singleton inheritence
	class Engine : public fabric::Singleton<Engine>
	{
	public:
		std::vector<Link> vWeb;

		// Main Eventloop
		// Calls it self till programm exits
		int eventLoop();

		// Called from the eventloop when the programms exits
		int exitRoutin();
	};

}

#endif // !ENGINE_HPP
