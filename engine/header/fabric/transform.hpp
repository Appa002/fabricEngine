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

	namespace transform {
		void lookAt(vec3 camPos, vec3 targetPos, vec3 upVec);
		vec3 cross(vec3 a, vec3 b);
	}
}

#endif // !TRANSFORM_HPP
