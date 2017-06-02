#include "Object.h"


using namespace std::string_literals;

bool KUDE::Object::objectReads(std::ifstream& fin , KUDE::ObjectLinks & objectLinks) {
	
	

	for (auto & i : objectLinks) {
		if (!i.mEntry.isUse()) continue; // entry

		fin.seekg(i.mSection.getDataInt());
		objectRead(fin);
	}
	return true;
}

bool KUDE::Object::objectRead(std::ifstream & fin) {

	// example 
	// binary = 3337 20 
	// string = 37 0
	KUDE::Buffer<512> buffer;
	std::string objetNumStr = buffer.getStringFileSeq(fin, KUDE::SEQUENCE::SP);
	int objectNum; 
	if (!KUDE::stoi(objetNumStr, objectNum)) return false;
	KUDE::DEBUG::LOG(objectNum);
	exit(1);
	//fstream.read(KUDE::Object)










}
