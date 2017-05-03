#pragma once
using BYTE = char;
using BUFESIZE = BYTE[21];
using PDFVersion = BYTE[9];


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