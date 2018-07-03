#ifndef DISPLAYER
#define DISPLAYER

#include<stdio.h>
#include<stdlib.h>
#include <string>

#include "Base_types.hpp"
#include "Constant_pool.hpp"
#include "Field_info.hpp"
#include "Method_info.hpp"

using namespace std;

const string name_types[] = {"-", "UTF-8", "-", "Integer", "Float", "Long", "Double", "Class", "String", "Field", "Method", "Interface", "Name/Type"};
const string flag_names[] = {"ACC_PUBLIC", "ACC_FINAL", "ACC_SUPER", "ACC_INTERFACE", "ACC_ABSTRACT"};

class Displayer {
public:
	static void display_version(U2 min_version, U2 max_version);
	static void display_cp(Constant_pool *cp, U2 cp_length);
	static string display_UTF8(vector<U1> values, U2 size);
	static string display_UTF8(unsigned char* values, U2 size);
	

	static float u4_to_float(U4 value);
	static long u4_to_long(U4 high, U4 low);
	static double u4_to_double(U4 high, U4 low);
	static string dereference_index(vector<Cp_info> cp_vector, U2 index);
	static void display_access_flags(U2 access_flags);
	static void display_class_names(U2 this_class, U2 super_class, vector<Cp_info> cp_vector);
	static void display_interfaces(vector<U2> interfaces, vector<Cp_info> cp_vector);
	static void display_interface_by_index(U2 interfaces, vector<Cp_info> cp_vector, int);
	static void display_fields(vector <Field_info>, vector<Cp_info>, int);
	static void display_field_by_index(Field_info, vector<Cp_info>, int);
	static void display_attribute(Attribute_info, vector<Cp_info>);
	static void display_methods(vector <Method_info>, vector<Cp_info> , int);
	static void display_method_by_index(Method_info , vector<Cp_info>, int);
};

#endif