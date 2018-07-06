#ifndef LOCAL_VARIABLE_TABLE
#define LOCAL_VARIABLE_TABLE

#include <iostream>
#include "Base_types.hpp"

using namespace std;

/** \brief Struct que indica um intervalo de deslocamentos de vetor de código no qual uma variável local tem um valor
 */
typedef struct {
    /*@{*/
    U2 start_PC; /**< Indica o começo do PC */
    U2 length; /**< Indica o comprimento do atributo */
    U2 name_index; /**< Índice válido na tabela constant_pool denotando uma variável local*/
    U2 descriptor_index; /**< Índice válido na tabela constant_pool denotando o tipo de uma variável local */
    U2 index; /**< A variável local fornecida deve estar no índice na pilha de variáveis locais do quadro atual */
    /*@}*/
} T_local_variables_table;

#endif

