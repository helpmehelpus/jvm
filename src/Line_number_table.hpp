#ifndef LINE_NUMBER_TABLE
#define LINE_NUMBER_TABLE

#include "Base_types.hpp"

typedef struct {
    U2 start_pc;
    U2 line_number;
} Line_number_table;

#endif