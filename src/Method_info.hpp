#ifndef METHOD_INFO
#define METHOD_INFO

#include "Attribute_info.hpp"

class Method_info {
public:
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    Attribute_info* attributes;

    char* get_method_flag(uint16_t flags);
    Method_info read_method(FILE* fp, Cp_info* cp);
    Method_info* read_methods(FILE* fp, int length, Cp_info* cp);

    void display_method(Method_info f, Cp_info* cp);
    void display_method_index(Method_info f, Cp_info* cp, int index);
    void display_methods(Method_info* f, Cp_info* cp, int methods_length);
};

#endif