#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <fabric/types.hpp>
#include <fabric/vertex_buffer_object.hpp>
#include <fabric/vertex_attribute_object.hpp>

namespace fabric {
	class Mesh: public EngineObject {
	public:
		Mesh(){};
		int make(std::vector<vec3> data);
		VertexAttributeObject getVertexAttributeObject();
		std::vector<double> getData();


	private:
		VertexAttributeObject vao;
		std::vector<double> data;
	};
}

#endif // !MESH_HPP
