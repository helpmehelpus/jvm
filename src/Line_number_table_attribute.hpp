#ifndef LINE_NUMBER_TABLE_ATTRIBUTE
#define LINE_NUMBER_TABLE_ATTRIBUTE

#include <vector>

#include "Base_types.hpp"
#include "T_line_number_table.hpp"

using namespace std;

/**
 * 
 * Struct que tem a função de ser usada por depuradores para determinar qual parte do vetor de código da JVM corresponde a uma determinada linha no arquivo de origem original
 */
typedef struct {
    /*@{*/
    U2 length; /**< Indica o comprimento do atributo. */ 
    vector<T_line_number_table> line_number_table_vector; /**< Cada entrada neste vetor indica que o número da linha no arquivo de origem original foi alterado em um determinado ponto no vetor de códigos */ 
    /*@}*/
} Line_number_table_attribute;

#endif