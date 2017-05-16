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
	std::string getFileStringSeq(std::ifstream& in, char ch = KUDE::SEQUENCE::LF);
	bool stoi(std::string &str, int &num);
	

	std::string operator+(std::string &str, int intger);

}