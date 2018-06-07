#ifndef T_EXECEPTION_TABLE
#define T_EXECEPTION_TABLE


#include "Base_types.hpp"

class T_execption_table {
	U2 start_pc;
	U2 end_pc;
	U2 handler_pc;
	U2 catch_type;
};
#endif