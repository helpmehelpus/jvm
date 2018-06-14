#ifndef FRAME
#define FRAME

#include "Cp_info.hpp"
#include "Operand_stack.hpp"
#include "Local_variable.hpp"
#include "Method_info.hpp"

typedef struct  {
	vector<U2> pc;
	vector<Cp_info> cp_vector;	
	Operand_stack* operand_stack;
	Local_variable *local_variables;
	Method_info method_info;
} Frame;


#endif