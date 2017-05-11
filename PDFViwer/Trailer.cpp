#include "Trailer.h"
using namespace std::string_literals;


void KUDE::Trailer::read(std::ifstream & obj) {
	if(!findTrailer(obj)) throw std::runtime_error("trailer");
	if (!findStartxref(mTrailer)) throw std::runtime_error("not find startxref offset");
	if (!mXrefTable.tableRead(obj,this->mStartRefPos));

}

bool KUDE::Trailer::findStartxref(std::string str) {
	auto iter = findFIrstStringNext(str, "startxref"s);
	if (iter == std::string::npos)
		return false;

	std::stringstream stream;
	stream.str(str);

	if (!(stream >> mStartRefPos))
		throw std::runtime_error("not find startxref offset");

	KUDE::LOG::DEBUG_LINE_LOG(mStartRefPos);

	return true;
}

bool KUDE::Trailer::findTrailer(std::ifstream & obj) {
	std::string temp;
	KUDE::TYPE::BUFESIZE buf;
	obj.seekg(0, std::ios::end);
	std::size_t filesize = obj.tellg();
	std::size_t seek = filesize;


	seek -= sizeof(KUDE::TYPE::BUFESIZE) - 1; // 1023 find 
	obj.seekg(seek);
	obj.read(reinterpret_cast<char*>(&buf), sizeof(buf) - 1);
	buf[sizeof(buf) - 1] = NULL;

	temp = buf;
	auto iter = findFIrstString(temp, "trailer"s);
	if (iter == std::string::npos)
		return false;

	this->mTrailer = std::move(temp);


	KUDE::LOG::DEBUG_LINE_LOG(mTrailer);


	return true;


}

int KUDE::Trailer::getMstartRefPos() {
	return mStartRefPos;
}
