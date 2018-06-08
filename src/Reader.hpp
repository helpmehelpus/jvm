#ifndef READER
#define READER

#include <iostream>
#include "Base_types.hpp"
#include "Cp_info.hpp"
#include <vector>
#include "Constant_pool.hpp"
#include "Interface.hpp"
#include "Attribute_info.hpp"
//#include "Field_info.hpp"

class Reader{
  public:
    Constant_pool* cp;
    vector<U2> interfaces;
    //vector<Field_info> fields;

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


    // Method_info *methods;

    // Attribute_info *attributes;

    int run(char *file_name);
    int read(char *file_name);
    int show();

    static U1 read_U1(FILE *fp);
    static U2 read_U2(FILE *fp);
    static U4 read_U4(FILE *fp);

    static std::vector<U1> read_UTF8(FILE *fp, int size);

    // TODO: mandar para utils
    int check_magic_number(U4 number);
};
#endif