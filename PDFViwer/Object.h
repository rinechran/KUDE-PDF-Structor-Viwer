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
		using ObjectNumBer = std::size_t;
		using ObjectKey = std::string;
		using ObjectValue = std::string;
		using ObjectHeader = std::unordered_map<ObjectKey, ObjectValue>;
	
	public:
		Object() {}
		bool objectReads(std::ifstream& fin,KUDE::ObjectLinks &objectLinks);
		bool objectRead(std::ifstream& fin);

	private:
		std::unordered_map<ObjectNumBer, ObjectHeader> mObjecter;
	};
}

