#include "PdfHeader.h"

void PdfHeader::read(std::ifstream & obj) {
	obj.seekg(0, std::ios::beg);
	obj.read(reinterpret_cast<char*>(&mVersion), HeadSize);
	mVersion[HeadSize] = NULL;
}

std::ostream& operator<<(std::ostream & os, PdfHeader &obj) {

	return os << obj.mVersion;
}

