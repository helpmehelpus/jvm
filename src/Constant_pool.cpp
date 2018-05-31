#include "Constant_pool.hpp"
#include "Cp_info.hpp"
#include "Reader.hpp"
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

Constant_pool::Constant_pool(int cp_length, FILE *fp)
{
	
	cp_vector.push_back(Cp_info());
	Reader reader;
	int i = 1;

	for (i = 1; i < cp_length; i++)
	{

		cp_vector.push_back(Cp_info());
		cp_vector[i].info.push_back(Class_loader_type());
		
		cp_vector[i].tag = reader.read_U1(fp);
		// if (!(cp_vector[i].tag >= 0) && !(cp_vector[i].tag <= 12) && !(cp_vector[i].tag != 2)){
		// 	// tag invalida faz alguma coisa que nao sei como tratar ainda pois nao da pra dar return aqui
		// }

		switch (cp_vector[i].tag)
		{
		case UTF8:
			cp_vector[i].info[0].u2 = reader.read_U2(fp);
			cp_vector[i].info[0].array = reader.read_UTF8(fp, cp_vector[i].info[0].u2);
			break;
		case INTEGER:
		case FLOAT:
			cp_vector[i].info[0].u4 = reader.read_U4(fp);
			break;
		case LONG:
		case DOUBLE:
			cp_vector[i].info[0].u4 = reader.read_U4(fp);
			
			i++;
			
			cp_vector.push_back(Cp_info());
			cp_vector[i].info.push_back(Class_loader_type());

			cp_vector[i].tag = INVALID;
			cp_vector[i].info[0].u4 = reader.read_U4(fp);
			
			break;
		case CLASS:
		case STRING:
			cp_vector[i].info[0].u2 = reader.read_U2(fp);
			break;
		case FIELDREF:
		case METHODREF:
		case INTERFACEMETHODREF:
		case NAMEANDTYPE:
			cp_vector[i].info.push_back(Class_loader_type());
			cp_vector[i].info[0].u2 = reader.read_U2(fp);
			cp_vector[i].info[1].u2 = reader.read_U2(fp);
			break;
		}
	}

	if(i == cp_length)
		std::cout<< "Reading CP Succesfull"<< std::endl;
	else
		std::cout<< "Reading CP Failed"<< std::endl;
	
}
