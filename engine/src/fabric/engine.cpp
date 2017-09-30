#include <fabric/engine.hpp>

fabric::Engine::Engine()
{
}

fabric::Engine::~Engine()
{
}

int fabric::Engine::startRoutin() {

	fabric::Logfile::get()->open("../log");


	LOG_OUT("Initializing Fabric Engine", "[INFO]");
	LOG_OUT("Loading default Map", "[INFO]");
	LOG_OUT("Initializing SDL", "[INFO]");

	SDL_Init(SDL_INIT_VIDEO);

	LOG_OUT("Creating Window", "[INFO]");

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	m_pWindow = SDL_CreateWindow("Fabric Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	m_gContext = SDL_GL_CreateContext(m_pWindow);

	SDL_GL_MakeCurrent(fabric::Engine::m_pWindow, fabric::Engine::m_gContext);

	glewExperimental = GL_TRUE;
	glewInit();
	SDL_GL_SetSwapInterval(1);

	LOG_OUT("Build: 0  ", "[INFO]");
	LOG_OUT("Start Map: Badwater", "[INFO]");

	LOG_ASSERT(const int*, reinterpret_cast<const int*>(glGetString(GL_VERSION)), 0, "glGetString(GL_VERSION) is not a nullpointer", "!=");
	LOG_OUT("OpenGL Version Supported: " + std::string(reinterpret_cast<const char*>(glGetString(GL_VERSION))), "[INFO]");

	LOG_ASSERT(const int*, reinterpret_cast<const int*>(glGetString(GL_RENDERER)), 0, "glGetString(GL_RENDERER) is not a nullpointer", "!=");
	LOG_OUT("Renderer: " + std::string(reinterpret_cast<const char*>(glGetString(GL_RENDERER))), "[INFO]");
	
	
	Engine::state = FB_CONTEXT_CREATED;

	
	
	vs = std::unique_ptr<Shader>( new Shader(GL_VERTEX_SHADER, "./__game/vertex.glsl") );
	LOG_OUT("Vertex Shader compile info: " + vs->getLog(), "[INFO]");

	fs = std::unique_ptr<Shader>( new Shader(GL_FRAGMENT_SHADER, "./__game/fragment.glsl") );
	LOG_OUT("Fragment Shader compile info: " + vs->getLog(), "[INFO]");

	shader_programme = std::unique_ptr<fabric::ShaderProgram> (new ShaderProgram());
	shader_programme->attach(fs);
	shader_programme->attach(vs);
	shader_programme->link();
	
	shader_programme->validate();
	

	map.open("./__game/badwater.lua");


	UNIT_PUSH(new int((int)m_pWindow));

	UNIT_PUSH(new int(SDL_GL_SetSwapInterval(1)));
	UNIT_PUSH(new int(shader_programme->validate()));
	UNIT_PUSH(new std::string(fs->getLog().c_str()));
	UNIT_PUSH(new std::string(vs->getLog().c_str()));

	UNIT_TEST("Engine::startRoutin()",

		int out = 0;
		if (UNIT_POP(std::string) != "") //vs->getLog()
			out = out | 1;
		if (UNIT_POP(std::string) != "") //fs->getLog()
			out = out | 2;
		if (UNIT_POP(int) != 0) //shader_programme->validate()
			out = out | 4;
		if (UNIT_POP(int) != 0) //SDL_GL_SetSwapInterval(1)
			out = out | 8;
		if (UNIT_POP(int) == 0) // m_pWindow
			out = out | 16;

		return out;
	);


	Engine::state = FB_STARTUP_COMPLETE;

	Engine::eventLoop();
	Engine::exitRoutin();
	return 0;
}

void fabric::Engine::abortRoutin() {
	LOG_OUT("Aborted see last logs", "[ABORT]");
	Engine::exitRoutin();
}

int fabric::Engine::eventLoop() {
	bool bQuit = false;
	
	while (!bQuit)
	{
		
		while (SDL_PollEvent(&m_event) != 0) {
			if (m_event.type == SDL_QUIT) {
				bQuit = true;
				return 0;
			}
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		DataCore::get()->camPos.x -= 0.1;
		std::cout << DataCore::get()->camPos.x << std::endl;
		if (DataCore::get()->camPos.x < -16){
			DataCore::get()->camPos.x = -0;
		}


		shader_programme->use();
		GameObjectHandler::get()->renderAll();
		SDL_GL_SwapWindow(m_pWindow);
	} 


	return 0;
}

int fabric::Engine::exitRoutin() {
	std::cout << "Good bye!" << std::endl;

	SDL_DestroyWindow(m_pWindow);

	SDL_Quit();

	Logfile::get()->close();
	return 0;
}