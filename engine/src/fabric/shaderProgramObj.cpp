#include <fabric/shaderProgramObj.hpp>

int fabric::ShaderProgram::attach(std::unique_ptr<Shader>& shader)
{
	int openglsShaderNummber = 0;

	glAttachShader(ShaderProgram::handle, shader->handle);
	glGetProgramiv(ShaderProgram::handle, GL_ATTACHED_SHADERS, &openglsShaderNummber);

	ShaderProgram::shaderNummber++;


	UNIT_PUSH(new int(openglsShaderNummber));
	UNIT_PUSH(new int(ShaderProgram::shaderNummber));

	UNIT_TEST("ShaderProgram::attach",
		int out = 0;
		if (UNIT_POP(int) != UNIT_POP(int)) // openglsShaderNummber != ShaderProgram::shaderNummber
			out = out | 1;
		return out;
	);

	if (ShaderProgram::shaderNummber != openglsShaderNummber) {
		ShaderProgram::shaderNummber--;
		return 1;
	}
	return 0;
}

int fabric::ShaderProgram::validate()
{
	int out = 0;
	glValidateProgram(ShaderProgram::handle);
	glGetProgramiv(ShaderProgram::handle, GL_VALIDATE_STATUS, &out);

	UNIT_TEST("ShaderProgram::validate",
		return !out;
	);

	return !out;
}

int fabric::ShaderProgram::link()
{
	glLinkProgram(ShaderProgram::handle);
	
	int out = 0;
	glGetProgramiv(ShaderProgram::handle, GL_LINK_STATUS, &out);
	
	UNIT_TEST("ShaderProgram::link",
		return !out;
	);

	return !out;
}

void fabric::ShaderProgram::use()
{
	glUseProgram(ShaderProgram::handle);
}

fabric::ShaderProgram::ShaderProgram() {
	ShaderProgram::handle = glCreateProgram();
}