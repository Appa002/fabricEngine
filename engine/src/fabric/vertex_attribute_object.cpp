#include <fabric/vertex_attribute_object.hpp>


fabric::VertexAttributeObject::VertexAttributeObject() {
	VertexAttributeObject::handle = 0;
};

fabric::VertexAttributeObject::VertexAttributeObject(bool glContext) {
	VertexAttributeObject::handle = 0;
	if (glContext)
		glGenVertexArrays(1, &(VertexAttributeObject::handle));
}

int fabric::VertexAttributeObject::generate()
{
	if (VertexAttributeObject::handle == 0)
		glGenVertexArrays(1, &(VertexAttributeObject::handle));
	else
		return 1;
	
	return 0;
}

int fabric::VertexAttributeObject::enableAttribArray(unsigned int index, VertexBufferObject vbo)
{
	glBindVertexArray(VertexAttributeObject::handle);
	glEnableVertexAttribArray(index);
	return 0;
}

int fabric::VertexAttributeObject::setVertexAtrrib(unsigned int index, unsigned int size, VertexBufferObject vbo)
{
	GLenum type = 0;

	if (typeid(char).hash_code() == vbo.typeHash)
		type = GL_BYTE;

	else if (typeid(unsigned char).hash_code() == vbo.typeHash)
		type = GL_UNSIGNED_BYTE;

	else if (typeid(short).hash_code() == vbo.typeHash)
		type = GL_SHORT;

	else if (typeid(unsigned short).hash_code() == vbo.typeHash)
		type = GL_UNSIGNED_SHORT;

	else if (typeid(int).hash_code() == vbo.typeHash)
		type = GL_INT;

	else if (typeid(unsigned int).hash_code() == vbo.typeHash)
		type = GL_UNSIGNED_INT;

	else if (typeid(float).hash_code() == vbo.typeHash)
		type = GL_FLOAT;

	else if (typeid(double).hash_code() == vbo.typeHash)
		type = GL_DOUBLE;

	else if (typeid(unsigned char).hash_code() == vbo.typeHash)
		type = GL_UNSIGNED_BYTE;

	else if (typeid(void).hash_code() == vbo.typeHash)
		throw std::runtime_error("The given VertexBufferObject dosent seem to have any data bufferd");
	
	else
		throw std::runtime_error("Type not found please specify");

	VertexAttributeObject::setVertexAtrrib(index, size, type, GL_FALSE, 0, NULL, vbo);
	return 0;
}

int fabric::VertexAttributeObject::setVertexAtrrib(unsigned int index, unsigned int size, GLenum type, VertexBufferObject vbo)
{
	VertexAttributeObject::setVertexAtrrib(index, size, type, GL_FALSE, 0, NULL, vbo);
	return 0;
}

int fabric::VertexAttributeObject::setVertexAtrrib(unsigned int index, unsigned int size, GLenum type, GLboolean normalized, VertexBufferObject vbo)
{
	VertexAttributeObject::setVertexAtrrib(index, size, type, normalized, 0, NULL, vbo);
	return 0;
}

int fabric::VertexAttributeObject::setVertexAtrrib(unsigned int index, unsigned int size, GLenum type, GLboolean normalized, GLsizei stride, VertexBufferObject vbo)
{

	VertexAttributeObject::setVertexAtrrib(index, size, type, normalized, stride, NULL, vbo);
	return 0;
}

int fabric::VertexAttributeObject::setVertexAtrrib(unsigned int index, unsigned int size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer, VertexBufferObject vbo)
{
	if (VertexAttributeObject::handle == 0)
		glGenVertexArrays(1, &(VertexAttributeObject::handle));

	glBindVertexArray(VertexAttributeObject::handle);
	glBindBuffer(vbo.target, vbo.handle);
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);

	return 0;
}

