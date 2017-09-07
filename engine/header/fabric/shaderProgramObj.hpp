#ifndef SHADERPROGRAMOBJ_HPP
#define SHADERPROGRAMOBJ_HPP

#include <SDL.h>
#include <glew\glew.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <string>
#include <fabric/shaderObj.hpp>
#include <memory>
#include <fabric/unit_framework.hpp>

namespace fabric {

	class ShaderProgram {

	public:
		ShaderProgram();
		int attach(std::unique_ptr<Shader>& shader);
		int link();
		int validate();
		void use();
		GLuint handle;

	private:
		int shaderNummber = 0;
	};
}

#endif // !SHADERPROGRAMOBJ_HPP
