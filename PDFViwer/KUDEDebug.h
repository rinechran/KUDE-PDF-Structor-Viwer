#pragma once
#include <iostream>
#include <string>



namespace KUDE {

	namespace DEBUG {
		template <class T>
		void LOG(T &&log) {
#ifdef _DEBUG
	std::cout <<"LOG : " <<log<<std::endl;
#endif
		}
		
	}
}