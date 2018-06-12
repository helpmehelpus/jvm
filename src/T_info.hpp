#ifndef T_INFO
#define T_INFO

#include "Code_attribute.hpp"
#include "Constant_value_attribute.hpp"
#include "Exception_attribute.hpp"

typedef struct {
        Constant_value_attribute constant_value;
        Code_attribute code;
        Exception_attribute exception;
    } T_info;
#endif