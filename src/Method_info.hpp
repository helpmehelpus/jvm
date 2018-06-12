#ifndef METHOD_INFO
#define METHOD_INFO

#include "Attribute_info.hpp"
#include "Cp_info.hpp"
#include "Constant_pool.hpp"
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Method_info {
public:
    unsigned char access_flags;
    unsigned char name_index;
    unsigned char descriptor_index;
    unsigned char attributes_count;
    vector <Attribute_info> attributes;

    static vector <Method_info> read_methods(FILE*, vector<Cp_info>, int);
    static Method_info read_method(FILE*, vector<Cp_info>);
    static string get_method_flags(unsigned short flags);
};

#endif