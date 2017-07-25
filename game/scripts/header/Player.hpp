#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <engine.hpp> 
#include <gameobject.hpp>
#include <behavior.hpp>

using namespace fabric;

namespace game{
	class Player : public GameObject{
	public:
		void setup();
		void update ();
	};
}
#endif