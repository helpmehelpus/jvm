#ifndef READER
#define READER

#include <iostream>
#include "Base_types.hpp"
#include "Cp_info.hpp"
#include <vector>

class Reader{
  public:
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

    U2 *interfaces;

    U4 magic_number;

    // Field_info *fields;

    // Method_info *methods;

    // Attribute_info *attributes;

    int run(char *file_name);
    int read(char *file_name);
    int show();

    U1 read_U1(FILE *fp);
    U2 read_U2(FILE *fp);
    U4 read_U4(FILE *fp);

    std::vector<U1> read_UTF8(FILE *fp, int size);

    // TODO: mandar para utils
    int check_magic_number(U4 number);
};
#endif