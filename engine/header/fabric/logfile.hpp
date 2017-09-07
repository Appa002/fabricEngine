#ifndef LOGFILE_HPP
#define LOGFILE_HPP

#include <fstream>
#include <fabric/singleton.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include <SDL.h>
#include <glew\glew.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>

#ifdef LOGFILE_WITH_MACROS

#define LOG_OUT(message, type) fabric::Logfile::get()->logout(__FILE__, __LINE__, message, type)
#define LOG_ASSERT(type, lhs, rhs, message, sign) fabric::Logfile::get()->assert<type>(__FILE__, __LINE__, lhs, rhs, message, sign)

#endif

namespace fabric {

	class Logfile;

	class Logfile : public Singleton<Logfile> {
	public:

		int open(std::string path);
		int close();

		template<typename T> int assert(T lhs, std::string message);
		template<typename T> int assert(T lhs, T rhs, std::string message);
		template<typename T> int assert(T lhs, T rhs, std::string message, std::string sign);
		template<typename T> int assert(const char* file, int line, T lhs, T rhs, std::string message, std::string sign);

		int logout(std::string message);
		int logout(std::string message, std::string type);
		int logout(const char* file, int line, std::string message, std::string type);
		Logfile();
		~Logfile();
	private:
		int basicLog(std::string message);

		std::fstream file;
	};

	//Define temblate here so the compiler know what to do
	template<typename T> int Logfile::assert(T lhs, std::string message) {
		return Logfile::assert<T>(lhs, true, message, "==");;
	}

	template<typename T> int Logfile::assert(T lhs, T rhs, std::string message) {
		return Logfile::assert<T>(lhs, rhs, message, "==");
	}

	template<typename T> int Logfile::assert(T lhs, T rhs, std::string message, std::string sign) {
		return Logfile::assert<T>("NaN", 00, lhs, rhs, message, sign);
	}

	template<typename T> int Logfile::assert(const char* file, int line, T lhs, T rhs, std::string message, std::string sign) {

		bool correct = false;

		if (sign == "==") {
			if (lhs == rhs)
				correct = true;
		}
		if (sign == "!=") {
			if (lhs != rhs)
				correct = true;
		}
		if (sign == ">") {
			if (lhs > rhs)
				correct = true;
		}
		if (sign == "<") {
			if (lhs < rhs)
				correct = true;
		}
		if (sign == ">=") {
			if (lhs >= rhs)
				correct = true;
		}
		if (sign == "<=") {
			if (lhs <= rhs)
				correct = true;
		}

		if (correct) {
			basicLog(std::string(file) + "  " + std::to_string(line) + "  [TRUE]  " + message);
			return 0;
		}
		else {
			basicLog(std::string(file) + "  " + std::to_string(line) + "  [FALSE]  " + message);
			Engine::get()->abortRoutin();
			return 1;
		}

		return 1;

	}

}

#endif // !LOGFILE_HPP


