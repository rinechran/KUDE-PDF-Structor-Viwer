#include "PDFDocument.h"

KUDE::PDFDocument::PDFDocument(std::string & othFileName) 
	: mFstream(std::move(othFileName),std::ios::binary) {


}

void KUDE::PDFDocument::open(std::string & othFileName) {
	mFstream.open(std::move(othFileName), std::ios::binary);
}
