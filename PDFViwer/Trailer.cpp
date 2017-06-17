#include "Trailer.h"
using namespace std::string_literals;


bool KUDE::Trailer::read(std::ifstream & obj) {
	if (!findTrailer(obj)) {
		//throw std::runtime_error("trailer");
	}
	if (!findStartxref(mTrailer)) {
		//throw std::runtime_error("not find startxref offset");
	}
	if (!mXrefTable.tableRead(obj, this->mStartRefPos)) {
		//throw std::runtime_error("mXrefTable read Error");
	}
	return true;
}


// freand class XrefTable data geter

KUDE::ObjectLinks& KUDE::Trailer::getObjectLinks() {
	return mXrefTable.mTable;
}

bool KUDE::Trailer::findStartxref(std::string str) {

	auto iter = findFIrstStringNext(str, "startxref"s);
	if (iter == std::string::npos)
		return false;

	std::stringstream stream;
	stream.str(str);

	if (!(stream >> mStartRefPos))
		throw std::runtime_error("not find startxref offset");

	KUDE::DEBUG::LOG(mStartRefPos);

	return true;
}

bool KUDE::Trailer::findTrailer(std::ifstream & obj) {
	std::string temp;
	KUDE::TYPE::Buffer buf;
	obj.seekg(0, std::ios::end);
	std::size_t filesize = obj.tellg();
	std::size_t seek = filesize;


	seek -= sizeof(KUDE::TYPE::Buffer) - 1; // 1023 find 
	obj.seekg(seek);
	obj.read(reinterpret_cast<char*>(&buf), sizeof(buf) - 1);
	buf[sizeof(buf) - 1] = NULL;

	temp = buf;
	auto iter = findFIrstString(temp, "trailer"s);
	if (iter == std::string::npos)
		return false;

	this->mTrailer = std::move(temp);

	KUDE::DEBUG::LOG(mTrailer);


	return true;


}


KUDE::XrefTable::XrefTable() : mCount(0) {

}

bool KUDE::XrefTable::tableRead(std::ifstream & obj, KUDE::TYPE::offset & offest) {
	obj.seekg(offest);
	KUDE::FileBuffer<12> buffer;

	std::string xref = buffer.getStringFindSeq(obj,KUDE::SEQUENCE::LF);
	if (xref != "xref"s) return false;

	std::string startIndex = buffer.getStringFindSeq(obj, KUDE::SEQUENCE::SP);
	std::string endIndex = buffer.getStringFindSeq(obj, KUDE::SEQUENCE::LF);

	int start, end;

	if (!(KUDE::stoi(startIndex, start) && KUDE::stoi(endIndex, end)))
		return false;

	size_t size = end - start;


	mTable.resize(size);
	obj.read(reinterpret_cast<char*>(&mTable[0]),
		sizeof(KUDE::ObjectLInk)*size);


	return true;
}

