#ifndef T_INFO
#define T_INFO

#include "Code_attribute.hpp"
#include "Constant_value_attribute.hpp"
#include "Exception_attribute.hpp"

// era uma union
class T_info {
public:
    Constant_value_attribute constant_value;
    Code_attribute code;
    Exception_attribute exception;
};

#endif