#ifndef FRAME
#define FRAME

#include "Cp_info.hpp"
#include "Operand_stack.hpp"
#include "Local_variable.hpp"
#include "Method_info.hpp"

typedef struct  {
	unsigned char *pc;
	Cp_info *cp;	
	Operand_stack* operand_stack;
	Local_variable *local_variables;
	Method_info method_info;
} Frame;


#endif