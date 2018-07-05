#ifndef CODE_ATTRIBUTE
#define CODE_ATTRIBUTE

#include <vector>

#include "Attribute_info.hpp"
#include "Base_types.hpp"
#include "T_exception_table.hpp"

using namespace std;

class Attribute_info;

/**
 * 
 * Struct responsável por armazenar os as instruções da JVM e informação auxiliares para metodos, etc
 */

typedef struct {
    /*@{*/
    U2 max_stack; /**< Fornece a profundidade máxima da pilha de operandos */
    U2 max_locals; /**< Fornece o número de variáveis locais na matriz da variável local alocada na invocação de um metódo */
    U2 exception_table_length; /**< Cada entrada no vetor exception_table descreve um manipulador de exceção na vetor de código */
    U2 attribute_count; /**< Indica o número de atributos. */
    U4 code_length; /**< Fornece o número de bytes no vetor de atributo "code"  */
    vector<unsigned char> code; /**< Vetor de códigos que fornece os bytes reais do código da JVM. */
    vector <T_exception_table> exception_table; /**< Cada entrada no vetor exception_table descreve um manipulador de exceção na vetor de código */
    vector <Attribute_info> attributes; /**< Cada valor da tabela de atributos é uma estrutura de atributos */
    /*@}*/
} Code_attribute;

#endif