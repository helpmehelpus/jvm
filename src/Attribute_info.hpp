#ifndef ATTRIBUTE_INFO
#define ATTRIBUTE_INFO

#include "Base_types.hpp"
#include "T_exception_table.hpp"
#include "Constant_value_attribute.hpp"
#include "Exception_attribute.hpp"
#include "T_info.hpp"
#include "Constant_pool.hpp"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Attribute_info;

class Attribute_info {
public:
    U2 name_index;
    U4 length;
    T_info info;

    static vector<Attribute_info> read_attributes(FILE* fp, vector<Cp_info> cp_vector, int length);
    static Attribute_info read_attribute(FILE* fp, vector<Cp_info> cp_vector);
    static T_info read_attribute_info(FILE* fp, vector<Cp_info> cp_vector, U2 index, U2 length);

    static T_exception_table read_exception_handler(FILE* fp);

    static string get_mnemonic(int opcode);

    U4 get_n_bytes_value(uint8_t n, vector<U2> code, int* index);

    void get_opcode_params(vector<U2> code, int* index);
};

#endif