
#ifndef ATTRIBUTE_INFO
#define ATTRIBUTE_INFO

#include "Base_types.hpp"
#include "T_exception_table.hpp"
#include "Constant_value_attribute.hpp"
#include "Exception_attribute.hpp"
#include "Constant_pool.hpp"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Attribute_info {
public:

    typedef struct{
        U2 max_stack;
        U2 max_locals;
        U4 code_length;
        U2* code;
        U2 exception_table_length;
        vector <T_exception_table> exception_table;
        U2 attribute_count;
        vector <Attribute_info> attributes;
    }Code_attribute;

    typedef struct {
        Constant_value_attribute constant_value;
        Code_attribute code;
        Exception_attribute exception;
    }T_info;


    U2 name_index;
    U4 length;
    T_info *info;

    static T_exception_table read_exception_handler(FILE* fp);

    // static T_info* read_attribute_info(FILE* fp, vector<Cp_info> cp_vector, U2 index, U2 length);

    static Attribute_info read_attribute(FILE* fp, vector<Cp_info> cp_vector);

    static vector<Attribute_info> read_attributes(FILE* fp, vector<Cp_info> cp_vector, int length);

    // void display_attribute(Attribute_info a, vector<Cp_info> cp_vector);

    // void display_attributes(Attribute_info* attributes, vector<Cp_info> cp_vector, int length);

    static string getMnemonic(int opcode);

    U4 getNBytesValue(uint8_t n, U2* code, int* index);

    void getOpcodeParams(U2* code, int* index);
};

#endif