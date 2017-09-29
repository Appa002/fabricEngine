#include <fabric/mesh.hpp>

std::vector<double> fabric::Mesh::getData()
{
	return Mesh::data;
}

fabric::VertexAttributeObject fabric::Mesh::getVertexAttributeObject()
{
	return Mesh::vao;
}

int fabric::Mesh::make(std::vector<vec3> data) {
		VertexBufferObject vbo = VertexBufferObject(true, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
		std::vector<GLdouble> myPoints;

		for (size_t i = 0; i < data.size(); i++) {
			myPoints.push_back(data.at(i).x);
			myPoints.push_back(data.at(i).y);
			myPoints.push_back(data.at(i).z);
		}

		Mesh::data = myPoints;

		vbo.make<GLdouble>(myPoints);

		vao.generate();
		vao.enableAttribArray(0);
		vao.setVertexAtrrib(0, 3, vbo);
		return 0;
}