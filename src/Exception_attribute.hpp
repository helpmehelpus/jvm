
#ifndef EXECEPTION_ATTRIBUTE
#define EXECEPTION_ATTRIBUTE

#include "Base_types.hpp"

class Exception_attribute {
public:
    U2 number_of_exceptions;
    U2* exception_index_table;
};
#endif