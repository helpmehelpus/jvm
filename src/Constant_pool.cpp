#include <iostream>
#include <stdio.h>
#include <vector>

#include "Constant_pool.hpp"
#include "Cp_info.hpp"
#include "Reader.hpp"

using namespace std;

Constant_pool::Constant_pool(int cp_length, FILE *fp) {
	cp_vector.push_back(Cp_info());
	int i = 1;

	for (i = 1; i < cp_length; i++)	{

		cp_vector.push_back(Cp_info());
		cp_vector[i].info.push_back(Class_loader_type());
		cp_vector[i].tag = Reader::read_U1(fp);

		switch (cp_vector[i].tag) {
		case UTF8:
			cp_vector[i].info[0].u2 = Reader::read_U2(fp);
			cp_vector[i].info[0].array = Reader::read_UTF8(fp, cp_vector[i].info[0].u2);
			break;
		case INTEGER:
		case FLOAT:
			cp_vector[i].info[0].u4 = Reader::read_U4(fp);
			break;
		case LONG:
		case DOUBLE:
			cp_vector[i].info[0].u4 = Reader::read_U4(fp);
			i++;
			cp_vector.push_back(Cp_info());
			cp_vector[i].info.push_back(Class_loader_type());
			cp_vector[i].tag = INVALID;
			cp_vector[i].info[0].u4 = Reader::read_U4(fp);
			break;
		case CLASS:
		case STRING:
			cp_vector[i].info[0].u2 = Reader::read_U2(fp);
			break;
		case FIELDREF:
		case METHODREF:
		case INTERFACEMETHODREF:
		case NAMEANDTYPE:
			cp_vector[i].info.push_back(Class_loader_type());
			cp_vector[i].info[0].u2 = Reader::read_U2(fp);
			cp_vector[i].info[1].u2 = Reader::read_U2(fp);
			break;
		}
	}

	if(i == cp_length)
		std::cout<< "Successfully read CP"<< std::endl;
	else
		std::cout<< "Failed reading CP"<< std::endl;
}
