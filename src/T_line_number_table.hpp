#ifndef T_LINE_NUMBER_TABLE
#define T_LINE_NUMBER_TABLE

#include "Base_types.hpp"

typedef struct {
    U2 start_pc;
    U2 line_number;
} T_line_number_table;

#endif