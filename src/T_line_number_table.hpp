#ifndef T_LINE_NUMBER_TABLE
#define T_LINE_NUMBER_TABLE

#include "Base_types.hpp"

/** \brief Struct em que cada entrada nela indica que o número da linha no arquivo de origem original é alterado em um determinado ponto no vetor de códigos
 */
typedef struct {
    /*@{*/
    U2 start_pc; /**< Indica o índice no vetor de códigos na qual o código para uma nova linha no arquivo de origem original é iniciado. */
    U2 line_number; /**< Fornece o número da linha correspondente no arquivo de origem original. */
    /*@}*/
} T_line_number_table;

#endif