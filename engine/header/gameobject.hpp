#ifndef  GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>
#include <behavior.hpp>

using namespace std;
 
namespace fabric {

	class  GameObject : public Behavior {
	public:
		virtual void update();
		int spawn();
		template<class T> int link(T* link);
		
		GameObject() {
			vLinkNet = new vector<void *>;
			vBehaviours = new vector<Behavior *>;
		}

		~GameObject(){
			delete vLinkNet;
			delete vBehaviours;
		}

	private:
		vector<void *>* vLinkNet;
		vector<Behavior *>* vBehaviours;
	};
}

#endif // ! GAMEOBJECT_HPP