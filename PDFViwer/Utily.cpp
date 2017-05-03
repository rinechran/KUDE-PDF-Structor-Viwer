#include "Utily.h"

//Not find return std::string::npos 
//find return string index
std::string::size_type KUDE::findStr(std::string & str, std::string & find) {
	return str.find(find);
}

std::string::size_type KUDE::findFIrstStringNext(std::string & str, std::string & find) {
	auto iter = findStr(str, find);
	if (iter == std::string::npos) {
		return std::string::npos;
	}
	str.erase(0,iter+find.size());
	return iter;

}

std::string::size_type KUDE::findFIrstString(std::string & str, std::string & find) {
	auto iter = findStr(str, find);
	if (iter == std::string::npos) {
		return std::string::npos;
	}
	str.erase(0, iter);
	return iter;

}

auto KUDE::getFileStringLine(std::ifstream & in) {
	char temp;
	std::string str;
	while (true) {
		in.read(&temp, 1);
		if (temp == '\n') break;
		str += temp;
	}
	return str;
}
