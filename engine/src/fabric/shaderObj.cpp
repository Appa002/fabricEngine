#include <fabric/shaderObj.hpp>
#include <fabric/unit_framework.hpp>

std::ifstream::pos_type fabric::Shader::filesize(std::string filename) {
	std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
	return in.tellg();
}

int fabric::Shader::compile() {
	int out = 1;
	glCompileShader(Shader::handle);
	glGetShaderiv(Shader::handle, GL_COMPILE_STATUS, &out);
	
	UNIT_TEST("Shader::compile()",
		return !out;
	);
	
	return !out;
}

std::string fabric::Shader::getLog() {
	std::string out;
	int logLength;
	glGetShaderiv(Shader::handle, GL_INFO_LOG_LENGTH, &logLength);
	char* buffer = new char[logLength + 1] {0};

	glGetShaderInfoLog(Shader::handle, logLength, NULL, buffer);

	out = std::string(buffer);
	delete buffer;
	return out;

}

fabric::Shader::Shader(GLenum type,std::string source){
	Shader::handle = glCreateShader(type);

	Shader::type = type;

	if (source.at(0) != '#') {
		// The source is not the shader source as it does not start with #version ...
		std::ifstream file;
		file.open(source);
		
		if (!file.is_open()) {
			throw std::invalid_argument("Could not open shader file at: " + source);
			return;
		}
		
		unsigned int length = static_cast<unsigned int>(Shader::filesize(source.c_str()));

		char* buffer = new char[length+1] {0};

		file.read(buffer, length);
		file.close();

		glShaderSource(Shader::handle, 1, &buffer, NULL);
		delete buffer;
		buffer = 0;
	}
	else{
		glShaderSource(Shader::handle, 1, reinterpret_cast<const char * const *>(source.c_str()), NULL);
	}

	Shader::compile();
}

