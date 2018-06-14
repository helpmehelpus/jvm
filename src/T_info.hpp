#ifndef T_INFO
#define T_INFO

#include "Code_attribute.hpp"
#include "Constant_value_attribute.hpp"
#include "Exception_attribute.hpp"
#include "Line_number_table_attribute.hpp"
#include "Local_variable_table_attribute.hpp"

typedef struct {
        Constant_value_attribute constant_value;
        Code_attribute code;
        Exception_attribute exception;
        Line_number_table_attribute line_number_table;
        Local_variable_table_attribute local_variable_table;
    } T_info;
#endif