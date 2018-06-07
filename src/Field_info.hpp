#ifndef FIELD_INFO
#define FIELD_INFO

#include "Attribute_info.hpp"
#include "Cp_info.hpp"
#include <vector>
using namespace std;
class Field_info {
    public:
        unsigned char accessFlags;
        unsigned char name_index;
        unsigned char descriptor_index;
        unsigned char attributes_count;
        vector<Attribute_info> attributes;

        char* get_field_flags(unsigned short flags);
        static Field_info read_field(FILE* fp, vector<Cp_info> cp);
        static vector<Field_info> read_fields(FILE* fp, vector<Cp_info> cp, int length);
        void display_field(Field_info f, vector<Cp_info> cp, int index);
        void display_fields(Field_info *f, vector<Cp_info> cp, int length);

};

#endif