#ifndef  TYPES_HPP
#define TYPES_HPP

namespace fabric {

	class ILink {
	public:
		std::string sType;
	};

	// Struct holding the two Variables to be Linked
	// T must be the same for both Variables
	template<class T>
	class Link : public ILink{
	public:
		T* pSending;
		T* pReceving;

		void update() {
			*pReceving = *pSending;
		}

		~Link() {
			delete pSending;
			pSending = nullptr;
			delete pReceving;
			pReceving = nullptr;
		}

		Link(){}

		Link(T* _sending, T* _reciving, std::string _type) {
			pSending = _sending;
			pReceving = _reciving;
			sType = _type;
		}

	};

}

#endif // ! TYPES_HPP
