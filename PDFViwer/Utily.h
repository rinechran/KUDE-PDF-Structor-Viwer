#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include "KUDEType.h"
#include "KUDEDebug.h"
namespace KUDE {

	//Not find return std::string::npos 
	//find return string index
	std::string::size_type findStr(std::string& str, std::string& find);
	//Not find return std::string::npos 
	//find return string index

	std::string::size_type findFIrstStringNext(std::string& str, std::string& find);

	std::string::size_type findFIrstString(std::string & str, std::string & find);
	bool stoi(std::string &str, int &num);

	////src Conter dst 
	//template <typename T,int N>
	//bool fileReadUntilSeq(std::string &str, int counter,T N) {

	//}
	//

	std::string operator+(std::string &str, int intger);
	

}