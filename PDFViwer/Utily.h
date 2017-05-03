#pragma once
#include <string>
#include <iostream>
#include <fstream>


#define KOUD_LOG(log) \
std::cout<<"LINE : "<<__LINE__ <<"\t"<< "LOG:" <<log<<std::endl;


using BYTE = char;
using BUFESIZE = BYTE[1024];
using PDFVersion = BYTE[9];


//Not find return std::string::npos 
//find return string index
std::string::size_type findStr(std::string& str, std::string& find);
//Not find return std::string::npos 
//find return string index

std::string::size_type findFIrstStringNext(std::string& str, std::string& find);

std::string::size_type findFIrstString(std::string & str, std::string & find);
auto getFileStringLine(std::ifstream& in);