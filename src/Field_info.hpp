#ifndef FIELD_INFO
#define FIELD_INFO

#include <stdio.h>
#include <string>
#include <vector>

#include "Attribute_info.hpp"
#include "Constant_pool.hpp"
#include "Cp_info.hpp"

using namespace std;
class Field_info {
    public:
        unsigned char access_flags;
        unsigned char name_index;
        unsigned char descriptor_index;
        unsigned char attributes_count;
        vector <Attribute_info> attributes;

        static vector <Field_info> read_fields(FILE*, vector<Cp_info>, int);
        static Field_info read_field(FILE*, vector<Cp_info>);
        static string get_field_flags(unsigned short flags);
};

#endif