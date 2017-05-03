#include "Trailer.h"
using namespace std::string_literals;


void Trailer::read(std::ifstream & obj) {
	if(!findTrailer(obj)) throw std::runtime_error("trailer");
	if (!findStartxref(mTrailer)) throw std::runtime_error("not find startxref offset");

}

bool Trailer::findStartxref(std::string str) {
	auto iter = findFIrstStringNext(str, "startxref"s);
	if (iter == std::string::npos)
		return false;

	std::stringstream stream;
	stream.str(str);

	if (!(stream >> mStartRefPos))
		throw std::runtime_error("not find startxref offset");

#ifdef _DEBUG
	KOUD_LOG(mStartRefPos);
#endif
	return true;
}

bool Trailer::findTrailer(std::ifstream & obj) {
	std::string temp;
	BUFESIZE buf;
	obj.seekg(0, std::ios::end);
	std::size_t filesize = obj.tellg();
	std::size_t seek = filesize;


	seek -= sizeof(BUFESIZE) - 1; // 1023 find 
	obj.seekg(seek);
	obj.read(reinterpret_cast<char*>(&buf), sizeof(buf) - 1);
	buf[sizeof(buf) - 1] = NULL;

	temp = buf;
	auto iter = findFIrstString(temp, "trailer"s);
	if (iter == std::string::npos)
		return false;

	this->mTrailer = std::move(temp);

#ifdef _DEBUG
	KOUD_LOG(mTrailer);
#endif

	return true;


}

int Trailer::getMstartRefPos() {
	return mStartRefPos;
}
