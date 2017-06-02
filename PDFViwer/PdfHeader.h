#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Utily.h"
#include "Buffer.hpp"
namespace KUDE {

	using PDFVersion = KUDE::TYPE::BYTE[9];
#pragma pack(push,1)
	class PdfHeader {

	public:
		bool read(std::ifstream &obj);
	protected:
		PDFVersion mVersion;
		friend std::ostream& operator<<(std::ostream & os, PdfHeader &obj);
		static constexpr std::size_t HeadSize = 8;
		KUDE::Buffer<8> mBuffer;
	};
#pragma pack(pop)


	std::ostream& operator<<(std::ostream & os, PdfHeader &obj);
}