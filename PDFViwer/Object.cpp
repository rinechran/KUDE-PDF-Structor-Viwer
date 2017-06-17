#include "Object.h"


using namespace std::string_literals;

bool KUDE::Object::read(std::ifstream& fin , KUDE::ObjectLinks & objectLinks) {
	
	

	for (auto & i : objectLinks) {
		if (i.mEntry.isUse()) fin.seekg(i.mSection.getDataInt());
		else continue;

		objectRead(fin);
	}
	return true;
}

bool KUDE::Object::objectRead(std::ifstream & fin) {
	//KUDE::FileBuffer<128> buffer;
	ObjectNumBer objectNumber;
	if (!getObjectNum(fin, objectNumber)) return false; //Object Num Read

	ObjectHeader objectHeader;
	if (!getBodyObject(fin, objectHeader)) return false;

	return true;

}

bool KUDE::Object::getObjectNum(std::ifstream & fin, ObjectNumBer & objectNum) {
	KUDE::FileBuffer<32> buffer;
	std::string objetNumStr = buffer.getStringFindSeq(fin, KUDE::SEQUENCE::SP);
	if (!KUDE::stoi(objetNumStr, objectNum)) return false;

	KUDE::DEBUG::LOG("Object Number -> "s + objectNum);
	return true;
}
