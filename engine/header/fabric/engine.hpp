#ifndef ENGINE_HPP
#define ENGINE_HPP

#define UNIT_CATCH_UNIT_ERRORS
#define LOGFILE_WITH_MACROS
#include <fabric/logfile.hpp>

#include <fabric/gameobjecthandler.hpp>
#include <fabric/singleton.hpp>
#include <vector>
#include <fabric/types.hpp>
#include <fabric/gameobject.hpp>
#include <iostream>
#include <fabric/shaderObj.hpp>
#include <fabric/map.hpp>
#include <fabric/shaderProgramObj.hpp>
#include <memory>
#include <fabric/vertex_buffer_object.hpp>
#include <fabric/vertex_attribute_object.hpp>

#include <SDL.h>
#include <glew\glew.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <fabric/unit_framework.hpp>
#include <fabric/error_handler.hpp>


namespace fabric {

	// The class holding all Engine stuff
	// There will always only be one therfor the Singleton inheritence

	class Engine : public fabric::Singleton<Engine>
	{
	public:

		unsigned long long state = FB_JUST_CREATED;

		int startRoutin();
		void abortRoutin();
		Engine();
		~Engine();
	
	private:
		std::unique_ptr<std::vector<GameObject>> vLoadedGameObjects;
		SDL_Window* m_pWindow;
		std::unique_ptr<SDL_Surface> m_pScreenSurface;
		SDL_Event m_event;
		SDL_GLContext m_gContext;
		GLuint m_gProgramID;

		VertexAttributeObject vao;
		std::unique_ptr<Shader> vs;
		std::unique_ptr<Shader> fs;
		std::unique_ptr<ShaderProgram> shader_programme;

		// Called from the eventloop when the programms exits
		int eventLoop();
		int exitRoutin();
		
	};

}


#endif //!ENGINE_HPP
