#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "Utily.h"

class XrefTable {


};
class Trailer {
public:
	void read(std::ifstream &obj);
	void findStartxref(std::string str);
	void findTrailer(std::ifstream &obj);
	int getMstartRefPos();
private:

	std::string mTrailer;
	int mStartRefPos;
};

