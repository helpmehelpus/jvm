#ifndef T_EXCEPTION_TABLE
#define T_EXCEPTION_TABLE


#include "Base_types.hpp"

class T_exception_table {
	U2 start_pc;
	U2 end_pc;
	U2 handler_pc;
	U2 catch_type;
};
#endif