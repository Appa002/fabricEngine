#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>
#include <fabric/engineObj.hpp>


namespace fabric {

	template <class T> class Singleton : public EngineObject{

	private:
		static T* m_pSingleton;

	public:

		// Example: Engine::get()->stuff()
		// Safe from everywhere
		static	T* get() {
			if (!m_pSingleton)
				m_pSingleton = new T;
			
			return m_pSingleton;
		}


		static void del() {
			if (!m_pSingleton)
				delete m_pSingleton;
			return;
		}

		~Singleton() {
			this->del();
		}

	};

	template <class T>
	T* Singleton<T>::m_pSingleton = 0;

}//fabric

#endif