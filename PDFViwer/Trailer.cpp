#include "Trailer.h"

void Trailer::read(std::ifstream & obj) {
	findTrailer(obj);
	findStartxref(mTrailer);

}

void Trailer::findStartxref(std::string str) {
	std::string temp = mTrailer;
	auto startpos = mTrailer.find("startxref");
	temp = temp.substr(startpos + sizeof("startxref"));
	std::stringstream stream;
	stream.str(temp);

	if (!(stream >> mStartRefPos))
		throw std::runtime_error("not find startxref offset");
}

void Trailer::findTrailer(std::ifstream & obj) {
	BUFESIZE buf;
	obj.seekg(0, std::ios::end);
	std::size_t filesize = obj.tellg();
	std::size_t seek = filesize;
	while (seek > 0) {
		seek -= sizeof(BUFESIZE) - 1;
		obj.seekg(seek);
		obj.read(reinterpret_cast<char*>(&buf), sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = NULL;
		mTrailer = buf + mTrailer;
		std::size_t found;
		found = mTrailer.find("trailer");
		if (found != std::string::npos) {
			mTrailer.erase(0, found);
			return;
		}
	}

	throw std::runtime_error("not find trailer offset");


}

int Trailer::getMstartRefPos() {
	return mStartRefPos;
}
