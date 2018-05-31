#ifndef CONSTANTPOOL
#define CONSTANTPOOL

#include <vector>
#include <stdio.h>
#include "Cp_info.hpp"

#define CLASS 7
#define FIELDREF 9
#define METHODREF 10
#define INTERFACEMETHODREF 11
#define STRING 8
#define INTEGER 3
#define FLOAT 4
#define LONG 5
#define DOUBLE 6
#define NAMEANDTYPE 12
#define UTF8 1
#define INVALID 99

using namespace std;
class Constant_pool{
	public:
		vector<Cp_info> cp_vector;
		Constant_pool(int cp_length, FILE* fp);
		
	
};


#endif