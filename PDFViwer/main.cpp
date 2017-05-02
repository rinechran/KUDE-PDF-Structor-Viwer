#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using BYTE = char;
using BUFESIZE = BYTE[21];
using PDFVersion = BYTE[9];

class Fooer {



};
class XrefTable {

};
class Trailer {
public:
	void read(std::ifstream &obj) {
		BUFESIZE buf;
		obj.seekg(0,std::ios::end);
		std::size_t filesize = obj.tellg();
		std::size_t seek = filesize;
		while (true) {
			seek -= sizeof(BUFESIZE)-1;
			obj.seekg(seek);
			obj.read(reinterpret_cast<char*>(&buf), sizeof(buf)-1);
			buf[sizeof(buf)-1] = NULL;
			str = buf + str;
			 
			std::size_t found;
			found = str.find("trailer");
			if (found != std::string::npos ) {
				str.erase(0, found);
				break;
			}
		}
		std::cout << str;
	}
private:
	
	std::string str;
};

#pragma pack(1)
class PdfHeader {

public:
	void read(std::ifstream &obj) {
		obj.read(reinterpret_cast<char*>(&mVersion),HeadSize);
		mVersion[HeadSize] = NULL;
	}
protected:
	PDFVersion mVersion;

	friend std::ostream& operator<<(std::ostream & os, PdfHeader &obj);
	static constexpr std::size_t HeadSize = 8;
};
#pragma pack(pop)

std::ostream& operator<<(std::ostream & os, PdfHeader &obj) {
	 
	return os << obj.mVersion;
}



int main() {
	PdfHeader b;
	Trailer a;
	std::ifstream in("1.pdf");
	b.read(in);
	std::cout << "PDF Version " << b << std::endl;

	a.read(in);
	
	//std::cout << a;

}