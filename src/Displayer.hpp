#ifndef DISPLAYER
#define DISPLAYER

#include<stdio.h>
#include<stdlib.h>
#include "Base_types.hpp"
#include "Constant_pool.hpp"
#include <string>
using namespace std;

const string name_types[] = {"-", "UTF-8", "-", "Integer", "Float", "Long", "Double", "Class", "String", "Field", "Method", "Interface", "Name and Type"};

const string flag_names[] = {"ACC_PUBLIC", "ACC_FINAL", "ACC_SUPER", "ACC_INTERFACE", "ACC_ABSTRACT"};
class Displayer
{
public:
	static void version(U2 min_version, U2 max_version);
	static void cp(Constant_pool *cp, U2 cp_length);
	static void access_flags(U2 access_flags);


	static string dereference_index(vector<Cp_info> cp_vector, U2 index);

};

// char flag_names[5][20];


// void display_version(U2 min_version, U2 max_version);

// void display_class_names(U2 this_class, U2 super_class,Cp_info *cp);

// void display_cp(Cp_info *cp, int cp_length);
// void display_UTF8(U1* array, int size);
// char* get_UTF8(U1* array, int size);
// char* display_dereference_index(Cp_info *cp, U2 index);
// void init_name_types();

// void display_interfaces (U2 *interfaces, Cp_info *cp, int length);
// void display_interface (U2 interface, Cp_info *cp, int index);


// void init_flag_names();
// void display_flags(U2 access_flags);

// float u4_to_float (U4 number);
// long u4_to_long(U4 high, U4 low);
// double u4_to_double (U4 high, U4 low); 






#endif