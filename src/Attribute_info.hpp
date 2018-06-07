
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
    T_info info;

    static T_exception_table read_exception_handler(FILE* fp);

    static T_info read_attribute_info(FILE* fp, vector<Cp_info> cp_vector, U2 index, U2 length);

    static Attribute_info read_attribute(FILE* fp, vector<Cp_info> cp_vector);

    static vector<Attribute_info> read_attributes(FILE* fp, vector<Cp_info> cp_vector, int length);

    void display_attribute(Attribute_info a, vector<Cp_info> cp_vector);

    void display_attributes(Attribute_info* attributes, vector<Cp_info> cp_vector, int length);

    string getMnemonic(int opcode);

    U4 getNBytesValue(uint8_t n, U2* code, int* index);

    void getOpcodeParams(U2* code, int* index);
};

#endif