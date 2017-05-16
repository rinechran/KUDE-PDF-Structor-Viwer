#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#pragma once

namespace KUDE {
	class Object
	{
	public:
		Object() {}

	private:
		std::unordered_map<int, std::string> mObjecter;
	};
}

