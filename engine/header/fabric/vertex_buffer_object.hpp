#ifndef VERTEX_BUFFER_OBJECT_HPP
#define VERTEX_BUFFER_OBJECT_HPP

#include <SDL.h>
#include <glew\glew.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <fabric/logfile.hpp>
#include <typeinfo>

namespace fabric {

	class VertexBufferObject;

	class VertexBufferObject : EngineObject{
	public:

		
		VertexBufferObject(const VertexBufferObject &) = default;
		VertexBufferObject(bool glContext, GLenum target, GLenum usage);
		
		void generate();
		void bind();
		template<typename T> void bufferData(std::vector<T> value){
			VertexBufferObject::typeHash = typeid(T).hash_code();

			if (VertexBufferObject::handle == 0)
				glGenBuffers(1, &(VertexBufferObject::handle));

			glBindBuffer(VertexBufferObject::target, VertexBufferObject::handle);
			glBufferData(VertexBufferObject::target, value.size() * sizeof(T), &value[0], VertexBufferObject::usage);
		}
		template<typename T> int make(std::vector<T> value) {
			VertexBufferObject::typeHash = typeid(T).hash_code();

			if (VertexBufferObject::handle == 0)
				glGenBuffers(1, &(VertexBufferObject::handle));
			glBindBuffer(VertexBufferObject::target, VertexBufferObject::handle);
			glBufferData(VertexBufferObject::target, value.size() * sizeof(T), &value[0], VertexBufferObject::usage);
			return 0;
		}

		GLenum target = 0;
		GLenum usage = 0;
		GLuint handle = 0;
		size_t typeHash = typeid(void).hash_code();
	};
}

#endif // !VERTEX_BUFFER_OBJECT_HPP


