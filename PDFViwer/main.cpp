﻿#include "kude.h"



auto getFileStringLine(std::ifstream& in) {
	char temp;
	std::string str;
	while (true) {
		in.read(&temp, 1);
		if (temp == '\n') break;
		str += temp;
	}
	return str;
}
int main() {
	std::ifstream in("2.txt");
	std::cout<<getFileStringLine(in);
}