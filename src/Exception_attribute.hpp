#ifndef EXECEPTION_ATTRIBUTE
#define EXECEPTION_ATTRIBUTE

#include <vector>

#include "Base_types.hpp"

using namespace std;
/** \brief Struct que verifica quais exceções um método pode lançar
 */
typedef struct {
    /*@{*/
    U2 number_of_exceptions; /**< Indica o número de entradas na exception_index_table. */
    vector<U2> exception_index_table; /**< Cada valor no vetor exception_index_table deve ser um índice válido na tabela constant_pool */
    /*@}*/
} Exception_attribute;

#endif