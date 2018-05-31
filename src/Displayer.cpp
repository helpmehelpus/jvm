#include "Displayer.hpp"
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

void Displayer::version(U2 min_version, U2 max_version){
	printf("\nCLASS VERSION: (%d.%d)\t (MaxVersion.MinVersion)\n\n",max_version, min_version);
}

void init_name_types(vector <string> &name_types){

	name_types.push_back("-");
	name_types.push_back("UTF-8");
	name_types.push_back("-");
	name_types.push_back("Integer");
	name_types.push_back("Float");
	name_types.push_back("Long");
	name_types.push_back("Double");
	name_types.push_back("Class");
	name_types.push_back("String");
	name_types.push_back("Field");
	name_types.push_back("Method");
	name_types.push_back("Interface");
	name_types.push_back("Name and Type");
}

long u4_to_long(U4 high, U4 low) {
	long ret;
	ret = (unsigned int)high;
	ret<<= 32;
	ret+= (unsigned int)low;
	return ret;
}

double u4_to_double(U4 high, U4 low) {
	double ret;
	long limits = u4_to_long(high, low);
	
	if (limits == 0x7ff0000000000000L) {
		//retornar infinito??
	} else if (limits == 0xfff0000000000000L) {
		//retornar menos infinito??
	} else if ((limits >= 0x7ff0000000000001L) && (limits <= 0x7ffffffffffffL)) {
		//retornar NaN??
	} else if ((limits >= 0xfff0000000000001L) && (limits <= 0xffffffffffffffffL)) {
		//também retornar NaN??
	} else {
		int s = ((limits >> 63) == 0) ? 1 : -1;
		int e = ((limits >> 52) & 0x7ffL);
		long m = (e == 0) ? (limits & 0xfffffffffffffL) << 1 : (limits & 0xfffffffffffffL) | 0x10000000000000L;
		
		ret = s * m * pow(2, (e-1075));
	}
	
	return ret;
}

float u4_to_float(U4 number) {
	float ret;
	
	int sig = ((number >> 31) == 0) ? 1 : -1;
	int exponent = ((number >> 23) & 0xff);
	int mantissa = (exponent == 0) ? (number & 0x7fffff) << 1 : (number & 0x7fffff) | 0x800000;

	ret = sig * mantissa * pow(2, (exponent-150));
		
	return ret;
}

string display_UTF8(vector <U1> v, U2 size){

	int i;

	string ret = "";

	for(i = 0; i < v.size(); i++){
		if (!(v[i] & 0x80)) { //utf8 de apenas 1 byte
			ret += (char)v[i];
		} else {
			unsigned short auxCurrent;
			if (!(v[i+1] & 0x20)) { //utf8 de 2 bytes
				auxCurrent = ((v[i] & 0x1f) << 6) + (v[i+1] & 0x3f);
			} else { //utf8 de 3 bytes
				auxCurrent = ((v[i] & 0xf) << 12) + ((v[i+1] & 0x3f) << 6) + (v[i+2] & 0x3f);
				i++;
			}
			i++;
			ret += (char)auxCurrent;
		}
	}

	return ret;
}


// char* display_dereference_index(Cp_info *cp, U2 index) {
// 	char* aux = (char*)malloc(sizeof(char)*255);
// 	switch (cp[index].tag) {
// 		case UTF8: 
// 			return get_UTF8(cp[index].info[1].array, cp[index].info[0].u2);
// 		case CLASS: 
// 		case STRING:
// 			return display_dereference_index(cp, cp[index].info[0].u2);
// 		case NAMEANDTYPE: 
// 			strcat(aux, display_dereference_index(cp, cp[index].info[0].u2));
// 			strcat(aux, ":");
// 			return strcat(aux, display_dereference_index(cp, cp[index].info[1].u2));
			
			
// 		case METHODREF: 
// 		case INTERFACEMETHODREF:
// 		case FIELDREF:
// 			strcat(aux, display_dereference_index(cp, cp[index].info[0].u2));
// 			strcat(aux, ".");
// 			return strcat(aux, display_dereference_index(cp, cp[index].info[1].u2));
			
// 	}
// 	return "";
// }

string Displayer::dereference_index (vector <Cp_info> cp_vector, U2 index) {
	
	switch (cp_vector[index].tag) {
		case UTF8: 
			return display_UTF8(cp_vector[index].info[0].array, cp_vector[index].info[0].u2);
		case CLASS: 
		case STRING:
			return dereference_index(cp_vector, cp_vector[index].info[0].u2);
		case NAMEANDTYPE: 
			return (dereference_index(cp_vector, cp_vector[index].info[0].u2) + ":" + dereference_index(cp_vector, cp_vector[index].info[1].u2));
		case METHODREF: 
		case INTERFACEMETHODREF:
		case FIELDREF:
			return (dereference_index(cp_vector, cp_vector[index].info[0].u2) + "." + dereference_index(cp_vector, cp_vector[index].info[1].u2));
	}
	
	return "";
}

void Displayer::cp(Constant_pool *constant_pool, U2 cp_length){

	vector<Cp_info> cp = constant_pool->cp_vector;

	int index;

	vector <string> name_types;

	init_name_types(name_types);
   
    printf("______________________________________________Constant__Pool______________________________________________\n\n");

    printf(" Id \t Type \t\t\t Value \t\t\t\tExtra Info\n");
    printf("__________________________________________________________________________________________________________\n\n");
	for (int i = 1; i < cp_length; i++) {

        printf(" %d \t %s ", i, name_types[cp[i].tag].c_str());

		switch (cp[i].tag) {
			case UTF8: 
                cout << "\t\t\t";
				cout <<  display_UTF8(cp[i].info[0].array, cp[i].info[0].u2).c_str();
				break;
			case INTEGER: 
				cout << "\t\t\t";
				cout << cp[i].info[0].u4;
				break;
			case FLOAT: 
				cout << "\t\t\t";
				cout << u4_to_float(cp[i].info[0].u4);
				break;
			case LONG: 
				cout << "\t\t\t";
				
				//cout << u4_to_long(cp[i].info[0].u4, cp[i+1].info[0].u4);
				// printf("%x-%x\t", cp[i].info[0].u4, cp[i+1].info[0].u4);
				
				printf("%ld", u4_to_long(cp[i].info[0].u4, cp[i+1].info[0].u4));
				i++; 
				break;
			case DOUBLE: 
				cout << "\t\t\t";
				cout << u4_to_double(cp[i].info[0].u4, cp[i+1].info[0].u4);
				i++; 
				break;
			case CLASS: 
				
			case STRING:
				cout << "\t\t\t";
				cout << cp[i].info[0].u2;
				cout << "\t\t\t\t//" << dereference_index(cp,i);
				break;
			case NAMEANDTYPE: 
				cout << "\t\t" <<  cp[i].info[0].u2 << ":" << cp[i].info[1].u2;
				cout << "\t\t\t\t//" << dereference_index(cp,i);
				break;
			case METHODREF: 
			case INTERFACEMETHODREF:
			case FIELDREF:
				cout << "\t\t" <<  cp[i].info[0].u2 << "." <<  cp[i].info[1].u2;
				cout << "\t\t\t\t//" << dereference_index(cp,i);
				break;
		}
		printf("\n");
	}
    printf("__________________________________________________________________________________________________________\n\n");


}




// void init_flag_names(){

// 	strcpy(flag_names[0],"ACC_PUBLIC");
// 	strcpy(flag_names[1],"ACC_FINAL");
// 	strcpy(flag_names[2],"ACC_SUPER");
// 	strcpy(flag_names[3],"ACC_INTERFACE");
// 	strcpy(flag_names[4],"ACC_ABSTRACT");
// }



// char* get_UTF8(U1* array, int size){
// 	U1* res = (U1*)malloc(sizeof(U1)* size);
	
// 	int i = 0;

// 	while (i < size) {
// 		if (!(array[i] & 0x80)) { 
// 			res[i] = array[i];
// 		} else {
// 			unsigned short current;
// 			if (!(array[i+1] & 0x20)) { 
// 				current = ((array[i] & 0x1f) << 6) + (array[i+1] & 0x3f);
// 			} else { 
// 				current = ((array[i] & 0xf) << 12) + ((array[i+1] & 0x3f) << 6) + (array[i+2] & 0x3f);
// 				i++;
// 			}
// 			i++;
//             res[i] = current;
// 		}
// 		i++;
// 	}
// 	return (char*)res;

// }


// void display_class_names(U2 this_class, U2 super_class,Cp_info *cp){

// 	printf("This class: %s\n", display_dereference_index(cp, this_class) );
// 	printf("Super class : %s\n", display_dereference_index(cp,super_class) );

// }



// void display_flags(U2 access_flags){
// 	init_flag_names();
// 	printf("flags: ");

// 	if (access_flags & 0x01) 
// 		printf("%s ", flag_names[0] );
// 	if(access_flags & 0x010) 
// 		printf("%s ", flag_names[0] );
// 	if(access_flags & 0x020) 
// 		printf("%s ", flag_names[0] );
// 	if(access_flags & 0x0200) 
// 		printf("%s ", flag_names[0] );
// 	if(access_flags & 0x0400) 	
// 		printf("%s ", flag_names[0] );
	
	
// 	printf(" 0x%x\n", access_flags);

// }


// void display_interfaces(U2 *interfaces, Cp_info *cp, int length) {
// 	int i;
// 	printf("Amount of interfaces %d\n", length);
// 	for (i = 0; i < length; i++) {
// 		display_interface(interfaces[i], cp, i);		
// 	}
// }

// void display_interface(U2 interface, Cp_info *cp, int index) {
// 	printf("\tInterface %d : %s\n", index, display_dereference_index(cp, interface));
// }
