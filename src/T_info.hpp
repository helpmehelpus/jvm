#ifndef T_INFO
#define T_INFO

#include "Code_attribute.hpp"
#include "Constant_value_attribute.hpp"
#include "Exception_attribute.hpp"
#include "Line_number_table_attribute.hpp"
#include "Local_variable_table_attribute.hpp"

/** \brief Struct que armazena os tipos possíveis da \e Constant \e Pool
 */
typedef struct {
        /*@{*/
        Constant_value_attribute constant_value; /**< representa o valor de um campo constante */
        Code_attribute code; /**< armazena as instruções da JVM e informação auxiliares para metodos, etc */
        Exception_attribute exception; /**< verifica quais exceções um método pode lançar */
        Line_number_table_attribute line_number_table; /**< determina qual parte do vetor de código da JVM corresponde a uma determinada linha no arquivo de origem original */
        Local_variable_table_attribute local_variable_table; /**< determina o valor de uma determinada variável local durante a execução de um método. */
        /*@}*/
    } T_info;
#endif