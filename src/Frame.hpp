#ifndef FRAME
#define FRAME

#include "Cp_info.hpp"
#include "Local_variable.hpp"
#include "Method_info.hpp"
#include "Operand_stack.hpp"

typedef struct  {
	vector<U2> pc;
	int current_pc_index;
	vector<Cp_info> cp_vector;	
	Operand_stack* operand_stack;
	Local_variable *local_variables;
	Method_info method_info;

	U2 get_current_pc() const {
		return pc[current_pc_index];
	};
	
} Frame;

#endif