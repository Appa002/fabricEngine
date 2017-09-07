#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>

namespace fabric {

	template <class T> class Singleton {

	private:
		static std::unique_ptr<T> m_pSingleton;

	public:

		// Example: Engine::get()->stuff()
		// Safe from everywhere
		static	T* get() {
			if (!m_pSingleton.get())
				m_pSingleton = std::unique_ptr<T> (new T);
			
			return m_pSingleton.get();
		}

	};

	template <class T>
	std::unique_ptr<T> Singleton<T>::m_pSingleton = 0;

}//fabric

#endif