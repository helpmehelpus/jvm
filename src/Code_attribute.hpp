#ifndef CODE_ATTRIBUTE
#define CODE_ATTRIBUTE

#include "Attribute_info.hpp"
#include "Base_types.hpp"
#include "T_exception_table.hpp"
#include "Line_number_table.hpp"

#include <vector>

using namespace std;

class Attribute_info;

typedef struct {
    U2 max_stack;
    U2 max_locals;
    U4 code_length;
    vector<U2> code;
    U2 exception_table_length;
    vector <T_exception_table> exception_table;

    U2 line_number_table_length;
    vector <Line_number_table> line_number_table;

    U2 attribute_count;
    vector <Attribute_info> attributes;
} Code_attribute;
#endif