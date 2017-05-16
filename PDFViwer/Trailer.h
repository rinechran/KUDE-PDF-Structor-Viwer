#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include "Utily.h"
#include "ObjectLInk.h"
#include "KUDEType.h"

using namespace std::string_literals;

using BUFESIZE = KUDE::TYPE::BYTE[1024];

namespace KUDE {
	class XrefTable {
	public:
		XrefTable() : mCount(0) {

		}
		bool tableRead(std::ifstream &obj, KUDE::TYPE::offset& offest);

	private:
		int mCount;
		std::vector<KUDE::ObjectLInk> mTable;

		friend class Trailer;

	};
	class Trailer {
	public: // public  member variable
		bool read(std::ifstream &obj);

	private: // private member variable
		bool findStartxref(std::string str);
		bool findTrailer(std::ifstream &obj);

	private: // private Member variable
		std::string mTrailer;
		XrefTable mXrefTable;
		KUDE::TYPE::offset mStartRefPos;
	};
}

