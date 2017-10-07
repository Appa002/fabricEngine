#ifndef SHADEROBJ_HPP
#define SHADEROBJ_HPP

#include <SDL.h>
#include <glew\glew.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <fabric/engineObj.hpp>


namespace fabric {

	class Shader;

	class Shader:public EngineObject {
	public:
		GLuint handle = 0;
		GLenum type;

		std::string getLog();
		int compile();
		Shader(GLenum type, std::string source);
	private:
		std::ifstream::pos_type filesize(std::string filename);
	};

}


#endif // !SHADEROBJ_HPP


