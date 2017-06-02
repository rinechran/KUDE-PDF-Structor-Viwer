#pragma once
#include <fstream>
#include <string>
#include "Trailer.h"
#include "Object.h"
#include "PdfHeader.h"

namespace KUDE {
	class PDFDocument
	{
	public:
		PDFDocument() = default;
		PDFDocument(std::string &othFileName);
		void open(std::string &othFileName);
		bool read() {
			if (!mPdfHeader.read(mFstream)) return false;

			if (!mTrailer.read(mFstream)) return false;
			


			if (!mObject.objectReads(mFstream,mTrailer.getObjectLinks())) return false;

			return true;
		}

	private:

		std::string mFilePath; 
		std::ifstream mFstream;

		KUDE::PdfHeader mPdfHeader;
		KUDE::Object mObject;
		KUDE::Trailer mTrailer;
		

		 
	};
}
