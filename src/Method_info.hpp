#ifndef METHOD_INFO
#define METHOD_INFO

#include "Attribute_info.hpp"

class Method_info {
public:
    uint16_t access_flags;
    uint16_t name_index;
    uint16_t descriptor_index;
    uint16_t attributes_count;
    vector<Attribute_info> attributes;

    static string get_method_flag(uint16_t flags);
    static Method_info read_method(FILE* , vector<Cp_info> );
    static vector <Method_info> read_methods(FILE* , int , vector<Cp_info> );

    // void display_method(Method_info f, vector<Cp_info> cp_vector);
    // void display_method_index(Method_info f, vector<Cp_info> cp_vector, int index);
    // void display_methods(Method_info* f, vector<Cp_info> cp_vector, int methods_length);
};

#endif