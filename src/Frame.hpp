#ifndef FRAME
#define FRAME

#include "Cp_info.hpp"
#include "Local_variable.hpp"
#include "Method_info.hpp"
#include "Operand_stack.hpp"

/**
 * 
 * Struct que contém estrutura de um array
 */
typedef struct  {
    /*@{*/
	unsigned char* pc; /**< ponteiro para o pc */
	// int current_pc_index;
	vector<Cp_info> cp_vector; /**< Vetor para armazenamento de dados do ConstantPool. */
	Operand_stack* operand_stack; /**< Ponteiro para a pilha de operandos */
	Local_variable *local_variables; /**< Ponteiro para a variáveis locais */
	Method_info method_info; /**< Referência para a classe method_info */

	// U2 get_current_pc() const {
	// 	return pc[current_pc_index];
	// };

	/*@}*/
	
} Frame;

#endif