#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <fabric/types.hpp>
#include <fabric/vertex_buffer_object.hpp>
#include <fabric/vertex_attribute_object.hpp>

namespace fabric {
	class Mesh {
	public:
		Mesh(){};
		int make(std::vector<vec3> data);
		VertexAttributeObject getVertexAttributeObject();

	private:
		VertexAttributeObject vao;
	};
}

#endif // !MESH_HPP
