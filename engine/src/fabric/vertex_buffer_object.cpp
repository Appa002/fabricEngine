#include <fabric/vertex_buffer_object.hpp>

fabric::VertexBufferObject::VertexBufferObject(bool glContext, GLenum target, GLenum usage) {
	VertexBufferObject::handle = 0;
	if (glContext == true)
		glGenBuffers(1, &(VertexBufferObject::handle));
	VertexBufferObject::target = target;
	VertexBufferObject::usage = usage;
}


void fabric::VertexBufferObject::generate()
{
	if (VertexBufferObject::handle != 0)
	{
		throw std::runtime_error("Handle allrady declared!");
	}
	glGenBuffers(1, &(VertexBufferObject::handle));
}

void fabric::VertexBufferObject::bind() {
	if (VertexBufferObject::handle == 0)
		glGenBuffers(1, &(VertexBufferObject::handle));
	glBindBuffer(VertexBufferObject::target, VertexBufferObject::handle);
}

