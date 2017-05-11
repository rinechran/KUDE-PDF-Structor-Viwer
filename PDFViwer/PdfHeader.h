#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Utily.h"
namespace KUDE {


#pragma pack(push,1)
	class PdfHeader {

	public:
		void read(std::ifstream &obj);
	protected:
		KUDE::TYPE::PDFVersion mVersion;
		friend std::ostream& operator<<(std::ostream & os, PdfHeader &obj);
		static constexpr std::size_t HeadSize = 8;
	};
#pragma pack(pop)


	std::ostream& operator<<(std::ostream & os, PdfHeader &obj);
}