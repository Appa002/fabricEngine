#ifndef  TYPES_HPP
#define TYPES_HPP

namespace fabric {
	template<class T> struct Vector2D
	{
		T x;
		T y;
	};

	template<class T> struct Vector3D
	{
		T x;
		T y;
		T z;
	};

	template<class T> struct Vector4D
	{
		T x;
		T y;
		T z;
		T w;
	};

	typedef Vector2D<double> vec2;
	typedef Vector3D<double> vec3;
	typedef Vector4D<double> vec4;


	enum fabric_state : unsigned long long {
		FB_JUST_CREATED = 0,
		FB_CONTEXT_CREATED = 1,
		FB_STARTUP_COMPLETE = 2,
		FB_LOOP_RUNNING = 4,
		FB_ENDING = 8,
		FB_ENDED = 16
	};

}

#endif // ! TYPES_HPP
