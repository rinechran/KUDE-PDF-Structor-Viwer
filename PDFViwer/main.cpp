#include "kude.h"



int main() {
	std::ifstream in("1.pdf");
	Trailer a;
	a.read(in);
}