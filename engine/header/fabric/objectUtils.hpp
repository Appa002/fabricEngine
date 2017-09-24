#ifndef OBJECTUTILS_HPP
#define OBJECTUTILS_HPP



#ifdef _MSC_VER 
//Microsoft
#define EXPORT extern "C" __declspec(dllexport)
#elif defined __GNUC__
//*nix
#define EXPORT __Atribute((visibility("default")))
#else
#define EXPORT
#endif

#include <iostream>
#include <string>
#include <vector>

namespace utils {
	struct PortableVar
	{
		std::string name = "";
		void* content = 0;
	};

	std::vector<PortableVar> portableVars;

	int registerPortableVar(std::string name, void* content) {
		PortableVar var;
		var.name = name;
		var.content = content;
		portableVars.push_back(var);
		return 0;
	}

	template <class T> int write_T(std::string name, T content) {
		for (size_t i = 0; i < portableVars.size(); i++) {
			if (portableVars.at(i).name == name) {
				*reinterpret_cast<T*>(portableVars.at(i).content) = content;
				return 0;
			}
		}
		return 1;
	}

	extern "C" EXPORT int write_int(std::string name, int content) { return write_T<int>(name, content); }
	extern "C" EXPORT int write_string(std::string name, std::string content) { return write_T<std::string>(name, content); }
	extern "C" EXPORT int write_bool(std::string name, bool content) { return write_T<bool>(name, content); }
	extern "C" EXPORT int write_double(std::string name, double content) { return write_T<double>(name, content); }
}



#endif