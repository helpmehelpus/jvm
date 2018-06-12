
#ifndef LINE_NUMBER_TABLE_ATTRIBUTE
#define LINE_NUMBER_TABLE_ATTRIBUTE

#include "Base_types.hpp"
#include "T_line_number_table.hpp"
#include <vector>


using namespace std;
typedef struct {
    U2 length;
    vector<T_line_number_table> line_number_table_vector;
} Line_number_table_attribute;

#endif