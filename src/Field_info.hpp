#ifndef FIELD_INFO
#define FIELD_INFO

#include "Attribute_info.hpp"
#include "Cp_info.hpp"
#include "Constant_pool.hpp"
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;
class Field_info {
    public:
        unsigned char access_flags;
        unsigned char name_index;
        unsigned char descriptor_index;
        unsigned char attributes_count;
        vector <Attribute_info> attributes;

        static string get_field_flags(unsigned short flags);
        static Field_info read_field(FILE*, vector<Cp_info>);        
        static vector <Field_info> read_fields(FILE*, vector<Cp_info>, int);

        // void display_field(Field_info f, vector<Cp_info> cp, int index);
        // void display_fields(Field_info *f, vector<Cp_info> cp, int length);

};


#endif