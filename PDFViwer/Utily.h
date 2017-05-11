#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "KUDEType.h"
#include "KUDELOG.h"
namespace KUDE {

	//Not find return std::string::npos 
	//find return string index
	std::string::size_type findStr(std::string& str, std::string& find);
	//Not find return std::string::npos 
	//find return string index

	std::string::size_type findFIrstStringNext(std::string& str, std::string& find);

	std::string::size_type findFIrstString(std::string & str, std::string & find);
	std::string getFileStringLine(std::ifstream& in);

}