#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include <fabric/engineObj.hpp>
#include <fabric/types.hpp>

namespace fabric {
	class Transform : public EngineObject {
	public:
		vec3 position;
		vec3 rotation;
		vec3 scale;
	};
}

#endif // !TRANSFORM_HPP
