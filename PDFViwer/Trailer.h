#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include "Utily.h"

class XrefTable {


};
class Trailer {
public:
	void read(std::ifstream &obj);
	bool findStartxref(std::string str);
	bool findTrailer(std::ifstream &obj);
	int getMstartRefPos();
private:

	

	std::string mTrailer;
	int mStartRefPos;
};

