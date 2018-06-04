#ifndef METHOD_INFO
#define METHOD_INFO

#include "Attribute_info.hpp"

class Method_info {
    public:
        uint16_t access_flags;
        uint16_t name_index;
        uint16_t descriptor_index;
        uint16_t attributes_count;
        Attribute_info *attributes;
};

#endif