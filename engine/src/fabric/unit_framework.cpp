#include <fabric/unit_framework.hpp>


void fabric::UnitTestFramework::doTests()
{

	unsigned int succsessfull = 0;
	int result = 0;

	for (unsigned int curTest = 0; curTest < UnitTestFramework::executionStack.size(); curTest++) {
		
		std::cout << "Evaluating: " << UnitTestFramework::names.at(curTest).c_str() << " ... ";
		
#ifdef UNIT_CATCH_UNIT_ERRORS
		try
		{
#endif
			result = UnitTestFramework::executionStack.at(curTest)();
#ifdef UNIT_CATCH_UNIT_ERRORS
		}
		catch (const std::exception& excep)
		{
			std::cerr << excep.what();
			result = -1;
		}
#endif

		if (result == 0) {
			std::cout << "[succsess]";
			succsessfull++;
		}
		else
			std::cout << "[failed] - " << result << " - " << std::bitset<sizeof(int) * 8>(result);
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "Succsessfull:" << succsessfull;
	std::cout << " Failed:" << UnitTestFramework::executionStack.size() - succsessfull;
	std::cout << " ";
	std::cout << ((float)succsessfull / (float)(UnitTestFramework::executionStack.size()) * 100) << "%" << std::endl;


	while (std::cin.get() == 0){}

}

void fabric::UnitTestFramework::addTest(std::string name, std::function<int(void)> myFunc)
{
	UnitTestFramework::executionStack.insert(UnitTestFramework::executionStack.begin(), myFunc);
	UnitTestFramework::names.insert(UnitTestFramework::names.begin(), name);
}

void fabric::UnitTestFramework::pushValue(void * value)
{
	UnitTestFramework::variableStack.insert(UnitTestFramework::variableStack.begin(), value);
}