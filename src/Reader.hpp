#ifndef READER
#define READER

#include <iostream>
#include <vector>
#include <stdbool.h>

#include "Attribute_info.hpp"
#include "Base_types.hpp"
#include "Constant_pool.hpp"
#include "Cp_info.hpp"
#include "Field_info.hpp"
#include "Interface.hpp"
#include "Method_info.hpp"

using namespace std;

class Reader{
  public:
    Constant_pool* cp;

    string file_name;

    vector<U2> interfaces;
    vector<Field_info> fields;
    vector<Method_info> methods;
    vector<Attribute_info> attributes;
    int main_index;
    int clinit_index;

    bool has_been_loaded;

    FILE *fp;

    U2 min_version;
    U2 max_version;
    U2 cp_length;
    U2 access_flags;
    U2 this_class;
    U2 super_class;
    U2 interfaces_count;
    U2 fields_count;
    U2 methods_count;
    U2 attributes_count;
    U4 magic_number;

    int run(char *file_name);
    int read(char *file_name);
    static U4 read_U4(FILE *fp);
    int check_magic_number(U4 number);
    static U2 read_U2(FILE *fp);
    static U1 read_U1(FILE *fp);
    static vector<U1> read_UTF8(FILE *fp, int size);

    int show();

    bool has_main();
    bool has_clinit();
    string get_path();
    Method_info get_main();
    Method_info get_clinit();
};
#endif