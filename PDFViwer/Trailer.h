#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include "Utily.h"
#include "Object.h"

using namespace std::string_literals;

namespace KUDE {
	class XrefTable {
	public:
		XrefTable() : mCount(0) {

		}
		bool tableRead(std::ifstream &obj ,KUDE::TYPE::offset& offest) {
			obj.seekg(offest);
			std::string xref = KUDE::getFileStringLine(obj);
			if (xref == "xref"s) return false;
			std::string startIndex = KUDE::getFileStringLine(obj);
			std::string endIndex = KUDE::getFileStringLine(obj);


			std::cout << xref;
			return true;
		}

	private:
		std::vector<KUDE::ObjectLInk> mTable;
		int mCount;

	};
	class Trailer {
	public:
		void read(std::ifstream &obj);
		bool findStartxref(std::string str);
		bool findTrailer(std::ifstream &obj);
		int getMstartRefPos();
	private:

		std::string mTrailer;
		XrefTable mXrefTable;
		KUDE::TYPE::offset mStartRefPos;
	};
}

