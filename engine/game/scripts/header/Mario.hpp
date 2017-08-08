#ifndef MARIO_HPP
#define MARIO_HPP

#include <engine.hpp> 
#include <gameobject.hpp>
#include <behavior.hpp>

using namespace fabric;

namespace game{
	class Mario : public GameObject{
	public:
		void setup();
		void update ();
	};
}
#endif