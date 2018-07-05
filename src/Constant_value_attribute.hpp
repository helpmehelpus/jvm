#ifndef CONSTANT_VALUE_ATTRIBUTE
#define CONSTANT_VALUE_ATTRIBUTE

#include "Base_types.hpp"

/**
 * 
 * Struct responsável por representar o valor de um campo constante
 */
typedef struct {
    /*@{*/
    U2 constant_value_index; /**< Armazena um valor que deve ser um índice válido na tabela constant_pool */
    /*@}*/
} Constant_value_attribute;

#endif