
#ifndef ATTRIBUTE_INFO
#define ATTRIBUTE_INFO

#include "Base_types.hpp"
#include "Cp_info.hpp"
#include "T_exception_table.hpp"
#include "T_info.hpp"

class Attribute_info {
public:
    U2 name_index;
    U4 length;
    T_info* info;

    T_exception_table* read_execption_handler(FILE* fp);

    T_info* read_attribute_info(FILE* fp, Cp_info* cp, U2 index, U2 length);

    Attribute_info read_attribute(FILE* fp, Cp_info* cp);

    Attribute_info* read_attributes(FILE* fp, Cp_info* cp, int length);

    void display_attribute(Attribute_info a, Cp_info* cp);

    void display_attributes(Attribute_info* attributes, Cp_info* cp, int length);

    char* getMnemonic(int opcode);

    U4 getNBytesValue(uint8_t n, U2* code, int* index);

    void getOpcodeParams(U2* code, int* index);
};

#endif