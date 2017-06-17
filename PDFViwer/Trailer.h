#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include "Utily.h"
#include "FileBuffer.hpp"
#include "ObjectLInk.h"
#include "KUDEType.h"

using namespace std::string_literals;

using BUFESIZE = KUDE::TYPE::BYTE[1024];
namespace KUDE {
	using ObjectLinks = std::vector<KUDE::ObjectLInk>;
	
	class XrefTable {
	public:
		XrefTable();
		bool tableRead(std::ifstream &obj, KUDE::TYPE::offset& offest);

	private:
		int mCount;
		ObjectLinks mTable;

		friend class Trailer;

	};
	class Trailer {
	public: // public  member variable
		bool read(std::ifstream &obj);


	public:
		// freand class XrefTable data geter
		ObjectLinks& getObjectLinks();
	private: // private member variable
		bool findStartxref(std::string str);
		bool findTrailer(std::ifstream &obj);

	private: // private Member variable
		std::string mTrailer;
		XrefTable mXrefTable;
		KUDE::TYPE::offset mStartRefPos;
	};
}

