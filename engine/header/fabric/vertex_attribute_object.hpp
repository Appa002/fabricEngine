#ifndef VERTEX_ATTRIBUTE_OBJECT_HPP
#define VERTEX_ATTRIBUTE_OBJECT_HPP

#include <SDL.h>
#include <glew\glew.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <fabric/vertex_buffer_object.hpp>
#include <typeinfo>

namespace fabric {

	class VertexAttributeObject : public EngineObject {
		
	public:

		VertexAttributeObject();
		VertexAttributeObject(bool glContext);
		int generate();
		int enableAttribArray(unsigned int index);
		int setVertexAtrrib(unsigned int index, unsigned int size, VertexBufferObject vbo);
		int setVertexAtrrib(unsigned int index, unsigned int size, GLenum type, VertexBufferObject vbo);
		int setVertexAtrrib(unsigned int index, unsigned int size, GLenum type, GLboolean normalized, VertexBufferObject vbo);
		int setVertexAtrrib(unsigned int index, unsigned int size, GLenum type, GLboolean normalized, GLsizei stride, VertexBufferObject vbo);
		int setVertexAtrrib(unsigned int index, unsigned int size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer, VertexBufferObject vbo);
		GLuint handle = 0;
	};
}



#endif //!VERTEX_ATTRIBUTE_OBJECT_HPP
