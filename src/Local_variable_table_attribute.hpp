#ifndef LOCAL_VARIABLE_TABLE_ATTRIBUTE
#define LOCAL_VARIABLE_TABLE_ATTRIBUTE

#include<vector>

#include "Base_types.hpp"
#include "T_local_variable_table.hpp"

using namespace std;

/**
 * 
 * Struct que tem a função de ser usada por depuradores para determinar o valor de uma determinada variável local durante a execução de um método.
 */
typedef struct {
    /*@{*/
    U2 length; /**< indica o comprimento do atributo */
    vector<T_local_variables_table> local_variable_vector; /**< indica o índice do vetor de variáveis locais, do \e frame atual, no qual essa variável local pode ser encontrada */ 
    /*@}*/
} Local_variable_table_attribute;

#endif