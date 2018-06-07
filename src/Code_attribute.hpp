#ifndef CODE_ATTRIBUTE
#define CODE_ATTRIBUTE

#include "Base_types.hpp"
#include "Attribute_info.hpp"
#include "T_exception_table.hpp"
#include <vector>

using namespace std;
class Code_attribute {
	U2 max_stack;
	U2 max_locals;
	U4 code_length;
	U2* code;
	U2 exception_table_length;
	vector<vector<T_exception_table> > exception_table;
	U2 attribute_count;
	vector<Attribute_info> attributes;
} ;
#endif