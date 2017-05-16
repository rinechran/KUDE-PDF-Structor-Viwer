#pragma once
#include <fstream>
#include <string>
#include "Trailer.h"
#include "PdfHeader.h"

namespace KUDE {
	class PDFDocument
	{
	public:
		PDFDocument() = default;
		PDFDocument(std::string &othFileName);
		void open(std::string &othFileName);
		bool read() {
			if (!mTrailer.read(mFstream)) return false;
		
		}

	private:

		std::string mFilePath;
		std::ifstream mFstream;
		KUDE::Trailer mTrailer;

		 
	};
}
