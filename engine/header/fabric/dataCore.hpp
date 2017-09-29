#ifndef DATACORE_HPP
#define DATACORE_HPP

#include <fabric/singleton.hpp>
#include <fabric/types.hpp>

namespace fabric {
	class DataCore : public fabric::Singleton<DataCore> {
	public:

		DataCore();

		vec3 camPos;

	};
}

#endif // !DATACORE_HPP
