#include "Interface.hpp"
#include <stdlib.h>

#include "Reader.hpp"
#include <vector>

using namespace std;

Interface::Interface(FILE* fp, int length) {
	Reader reader;
	vector<U2> interfaces;

	for (int i = 0; i < length; i++) {
		interfaces.push_back(reader.read_U2(fp));
	}

	this->length = length;
}
