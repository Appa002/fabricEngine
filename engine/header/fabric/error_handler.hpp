#ifndef ERROR_HANDLER_HPP
#define ERROR_HANDLER_HPP

#include <math.h>
#include <iostream>
#include <fabric/engine.hpp>
#include <exception>
#include <string>

namespace fabric {

	class CriticalException : public std::runtime_error {
	public:
		CriticalException() :runtime_error("Critical exception thrown") {}
		CriticalException(std::string msg) :runtime_error(msg.c_str()) {}
	};


	enum fabric_error{
		FB_CONTEXT_CRITICAL = 1,
		FB_STARTUP_CRITICAL = 2,
		FB_LOOP_CRITICAL = 4,
		FB_END_CRITICAL = 8,
		FB_ALLWAYS_CRITICAl = 16,
		FB_NEVER_CRITICAL = 32,

		END_OF_FABRIC_ERROR_ENUM

	} ;

	 void throw_error(unsigned long long err);

}

#endif // !ERROR_HANDLER_HPP