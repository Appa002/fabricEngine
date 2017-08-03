#include <map.hpp>
#include <gameobject.hpp>
#include <engine.hpp>
#include "../game/scripts/header/Player.hpp"

#ifndef BADWATER_HPP
#define BADWATER_HPP

using namespace game;
using namespace std;
using namespace fabric;

namespace game {
	class Badwater : public IMap {
	public:
		void load() {
			Engine::get()->vLoadedGameObjects->push_back(new Player);
		}
	};
}
#endif