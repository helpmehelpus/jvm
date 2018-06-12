
#ifndef EXECEPTION_ATTRIBUTE
#define EXECEPTION_ATTRIBUTE

#include "Base_types.hpp"
#include <vector>


using namespace std;
typedef struct {
    U2 number_of_exceptions;
    vector<U2> exception_index_table;
} Exception_attribute;

#endif