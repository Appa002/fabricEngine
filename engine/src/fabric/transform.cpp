#include <fabric/transform.hpp>

void fabric::transform::lookAt(vec3 camPos, vec3 targetPos, vec3 up)
{
	

	vec3 distance;
	distance.x = targetPos.x - camPos.x;
	distance.y = targetPos.y - camPos.y;
	distance.z = targetPos.z - camPos.z;

	vec3 forward;

	double m = sqrt(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);
	forward.x = distance.x / m;
	forward.y = distance.y / m;
	forward.z = distance.z / m;

	vec3 right = cross(forward, up);

	std::vector<double> mat = {
		right.x, right.y, right.z, 0,
		up.x, up.y, up.z, 0,
		-forward.x, -forward.y, -forward.z, 0,
		0, 0, 0, 1
	};
	
}

fabric::vec3 fabric::transform::cross(vec3 a, vec3 b)
{
	vec3 out;
	out.x = a.y * b.z - a.z * b.y;
	out.y = a.z * b.x - a.x * b.z;
	out.z = a.x * b.y - a.y * b.x;

	return out;

}