#pragma once
#include <iostream>
namespace KUDE {

	namespace LOG {
		template <class T>
		void DEBUG_LINE_LOG(T &log) {
#ifdef _DEBUG
	std::cout<<"LINE : "<<__LINE__ <<"\t"<< "LOG:" <<log<<std::endl;
#endif
		}



	}
}