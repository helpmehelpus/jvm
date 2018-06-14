#ifndef LOCAL_VARIABLE_TABLE_ATTRIBUTE
#define LOCAL_VARIABLE_TABLE_ATTRIBUTE

#include<vector>
#include "Base_types.hpp"
#include "T_local_variable_table.hpp"

using namespace std;

typedef struct {
    U2 length;
    vector<T_local_variables_table> local_variable_vector;
} Local_variable_table_attribute;

#endif