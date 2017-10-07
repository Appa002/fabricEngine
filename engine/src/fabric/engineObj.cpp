#include <fabric/engineObj.hpp>

size_t fabric::EngineObject::amount = 0;
std::vector<fabric::EngineObject*> fabric::EngineObject::instances;

std::vector<fabric::EngineObject*> fabric::EngineObject::getInstance() {
	return EngineObject::instances;
}

void fabric::EngineObject::deleteAll() {

	while (instances.size() > 0) {
		delete instances.at(0);
	}

}


size_t fabric::EngineObject::getAmount() {
	return EngineObject::amount;
}

fabric::EngineObject::EngineObject() {
	this->instances.push_back(this);

	EngineObject::amount = EngineObject::instances.size();

}

// Should be here
fabric::EngineObject::~EngineObject() {
	
	for (ptrdiff_t idx = 0; idx < EngineObject::instances.size(); idx++) {
		if(EngineObject::instances.at(idx) == this)
			EngineObject::instances.erase(instances.begin() + idx);
	}
	

	EngineObject::amount = EngineObject::instances.size();
}
