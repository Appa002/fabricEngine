#ifndef ENGINEOBJ_HPP
#define ENGINEOBJ_HPP

#include <vector>

namespace fabric {
	class EngineObject {
	public:
		
		EngineObject();
		virtual ~EngineObject();
		static void deleteAll();
		static size_t getAmount();
		static std::vector<fabric::EngineObject*> getInstance();

	private:
		static size_t amount;
		static std::vector<EngineObject*> instances;
	};

	

}

#endif