#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include "Trailer.h"
#include "KUDEType.h"
#include "KUDEDebug.h"

#pragma once

namespace KUDE {
	class Parser {

	};

	class Object
	{
		// ObjectNumber;
		// ObjectKey ObjectValue
		using ObjectNumBer = int;
		using ObjectKey = std::string;
		using ObjectValue = std::string;
		using ObjectHeader = std::unordered_map<ObjectKey, ObjectValue>;

	public:
		Object() {}
		bool read(std::ifstream& fin,KUDE::ObjectLinks &objectLinks);
		bool objectRead(std::ifstream& fin);
		bool getObjectNum(std::ifstream& fin, ObjectNumBer &objectNum);
		bool getBodyObject(std::ifstream& in, ObjectHeader & objectHeader) {
			KUDE::FileBuffer<128> buffer;
			auto context = std::move(buffer.getStringUtilFind(in, "endobj"s));
			return false;
		}


	private:
		std::unordered_map<ObjectNumBer, ObjectHeader> mObjecter;
	};
}

