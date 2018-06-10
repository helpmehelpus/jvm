#ifndef ATTRIBUTE_INFO
#define ATTRIBUTE_INFO

#include "Base_types.hpp"
// #include "T_exception_table.hpp"
// #include "Constant_value_attribute.hpp"
// #include "Exception_attribute.hpp"
#include "Constant_pool.hpp"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Attribute_info;

typedef struct {
    U2 constant_value_index;
} Constant_value_attribute;

typedef struct {
    U2 start_pc;
    U2 end_pc;
    U2 handler_pc;
    U2 catch_type;
} T_exception_table;

typedef struct {
    U2 max_stack;
    U2 max_locals;
    U4 code_length;
    vector<U2> code;
    U2 exception_table_length;
    vector <T_exception_table> exception_table;
    U2 attribute_count;
    vector <Attribute_info> attributes;
} Code_attribute;

typedef struct {
    U2 number_of_exceptions;
    vector<U2> exception_index_table;
} Exception_attribute;

typedef union {
        Constant_value_attribute constant_value;
        Code_attribute code;
        Exception_attribute exception;
    } T_info;

class Attribute_info {
public:
    U2 name_index;
    U4 length;
    T_info *info;

    static vector<Attribute_info> read_attributes(FILE* fp, vector<Cp_info> cp_vector, int length);
    static Attribute_info read_attribute(FILE* fp, vector<Cp_info> cp_vector);
    // static T_info read_attribute_info(FILE* fp, vector<Cp_info> cp_vector, U2 index, U2 length);

    static T_exception_table read_exception_handler(FILE* fp);

    // void display_attribute(Attribute_info a, vector<Cp_info> cp_vector);

    // void display_attributes(Attribute_info* attributes, vector<Cp_info> cp_vector, int length);

    static string get_mnemonic(int opcode);

    U4 get_n_bytes_value(uint8_t n, vector<U2> code, int* index);

    void get_opcode_params(vector<U2> code, int* index);
};

#endif