#include "ObjectLink.h"

KUDE::Isdead::Isdead(char * data) {
	std::memcpy(mIsDead, data, sizeof(mIsDead));
}

bool KUDE::Isdead::isDead() {
	return mIsDead[0] == 'f' ? true : false;
}
KUDE::Section::Section(char * data) {
	std::memcpy(mData, data, sizeof(mData));
}

int KUDE::Section::getDataInt() {
	mData[10] = NULL;
	return std::atoi(mData);
}
