#ifndef T_EXCEPTION_TABLE
#define T_EXCEPTION_TABLE

#include "Base_types.hpp"

/** \brief Struct que lida com tratamento de exceções do .CLASS.
 */
typedef struct  {
    /*@{*/
    U2 start_pc; /**< indica o início da faixa ao qual o \e handler de exceções está ativo.*/
    U2 end_pc; /**< indica o fim da faixa ao qual o \e handler de exceções está ativo.*/
    U2 handler_pc; /**< indica o início do \e handler de exceção.*/
    U2 catch_type; /**< índice válido para o \e Constant \e Pool. */
    /*@}*/
}  T_exception_table;

#endif