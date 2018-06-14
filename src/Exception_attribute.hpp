#ifndef EXECEPTION_ATTRIBUTE
#define EXECEPTION_ATTRIBUTE

#include <vector>

#include "Base_types.hpp"

using namespace std;
typedef struct {
    U2 number_of_exceptions;
    vector<U2> exception_index_table;
} Exception_attribute;

#endif