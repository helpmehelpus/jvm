#ifndef CODE_ATTRIBUTE
#define CODE_ATTRIBUTE

#include <vector>

#include "Attribute_info.hpp"
#include "Base_types.hpp"
#include "T_exception_table.hpp"

using namespace std;

class Attribute_info;

/*! \struct Struct responsável por armazenar todos os tamanhos de variáveis da JVM
*/
typedef struct {
    U2 max_stack;
    U2 max_locals;
    U2 exception_table_length;
    U2 attribute_count;
    U4 code_length;
    vector<U2> code;
    vector <T_exception_table> exception_table;
    vector <Attribute_info> attributes;
} Code_attribute;

#endif