#ifndef T_INFO
#define T_INFO

#include "Constant_value_attribute.hpp"
#include "Code_attribute.hpp"
#include "Exception_attribute.hpp"

// era uma union
class T_info { 
	Constant_value_attribute constantvalue;
	Code_attribute code;
	Exception_attribute exception;
};

#endif