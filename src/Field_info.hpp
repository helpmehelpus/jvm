#ifndef FIELD_INFO
#define FIELD_INFO

#include "Attribute_info.hpp"

class Field_info {
    public:
        unsigned char accessFlags;
        unsigned char name_index;
        unsigned char descriptor_index;
        unsigned char attributes_count;
        Attribute_info *attributes;
};

#endif