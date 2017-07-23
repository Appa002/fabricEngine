#ifndef BEHAVIOUR_HPP
#define BEHAVIOUR_HPP

namespace fabric {
	class Behavior {
	public:
		// Inherited by all Scripts for Objects
		void update(); // Suposed to be overwritten
		void setup(); // Suposed to be overwritten
	};
}

#endif // !BEHAVIOUR_HPP
