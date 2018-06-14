#ifndef LOCAL_VARIABLE_TABLE
#define LOCAL_VARIABLE_TABLE

#include <iostream>
#include "Base_types.hpp"

using namespace std;

typedef struct {
    U2 start_PC;
    U2 length;
    U2 name_index;
    U2 descriptor_index;
    U2 index;
} T_local_variables_table;

#endif

