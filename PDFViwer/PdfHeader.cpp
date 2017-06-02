#include "PdfHeader.h"


using namespace std::string_literals;


bool KUDE::PdfHeader::read(std::ifstream & obj) {
	obj.seekg(0, std::ios::beg);
	obj.read(reinterpret_cast<char*>(&mVersion), HeadSize);
	mVersion[HeadSize] = NULL;

	KUDE::DEBUG::LOG("PDF VERSION "s +mVersion);
	return true;
}

std::ostream& KUDE::operator<<(std::ostream & os, PdfHeader &obj) {

	return os << obj.mVersion;
}

