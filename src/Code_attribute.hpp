#ifndef CODE_ATTRIBUTE
#define CODE_ATTRIBUTE

#include "Attribute_info.hpp"
#include "Base_types.hpp"
#include "T_exception_table.hpp"
#include <vector>

using namespace std;
class Code_attribute {
public:
    U2 max_stack;
    U2 max_locals;
    U4 code_length;
    U2* code;
    U2 exception_table_length;
    vector <T_exception_table> exception_table;
    U2 attribute_count;
    vector<Attribute_info> attributes;
};
#endif