#pragma once
#include <iostream>
namespace KUDE {
	namespace TYPE {
		using BYTE = char;
		using offset = std::size_t;
		using Buffer = BYTE[512];
	}
	namespace SEQUENCE {
		const char Null = 0;
		const char LF = 10;
		const char FF = 12;
		const char CR = 13;
		const char SP = 32;
	}

}