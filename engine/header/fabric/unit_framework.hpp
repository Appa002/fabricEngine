#ifndef UNIT_FRAMEWORK_HPP
#define UNIT_FRAMEWORK_HPP

#include <fabric/singleton.hpp>
#include <vector>
#include <functional>
#include <iostream>
#include <exception>
#include <bitset>

#define UNIT_CATCH_UNIT_ERRORS
#define UNIT_TEST(name, body) fabric::UnitTestFramework::get()->addTest(name, [=](){body})
#define UNIT_PUSH(value) fabric::UnitTestFramework::get()->pushValue(value)
#define UNIT_POP(type) fabric::UnitTestFramework::get()->popValue<type>()

namespace fabric {
	class UnitTestFramework : public Singleton<UnitTestFramework> {
	public:
		void doTests();
		void addTest(std::string name, std::function<int(void)> myFunc);
		template <typename T> T popValue();
		void pushValue(void* value);
	private:
		std::vector< std::function<int(void)> > executionStack;
		std::vector<void*> variableStack;
		std::vector<std::string> names;
	};
}


template<typename T>
inline T fabric::UnitTestFramework::popValue()
{
	// TODO: unsafe may add typeid(T).hash_code(), if the variableStack members become strucs. 
	
	if (UnitTestFramework::variableStack.size() == 0) {
		throw std::runtime_error("Stack is empty");
	}

	T out = *(static_cast<T*>(UnitTestFramework::variableStack.at( 0 )));
	delete static_cast<T*>(UnitTestFramework::variableStack.at( 0 ));
	
	UnitTestFramework::variableStack.erase( UnitTestFramework::variableStack.begin() );
	return out;
}

#endif // !UNIT_FRAMEWORK_HPP
