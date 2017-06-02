#include "ObjectLink.h"

KUDE::Isdead::Isdead(char * data) {
	std::memcpy(mIsDead, data, sizeof(mIsDead));
}

bool KUDE::Isdead::isUse() {
	return mIsDead[0] == 'n' ? true : false;
}
KUDE::Section::Section(char * data) {
	std::memcpy(mData, data, sizeof(mData));
}

size_t KUDE::Section::getDataInt() {
	mData[10] = NULL;
	return std::strtoul(mData, nullptr, 10);
}
