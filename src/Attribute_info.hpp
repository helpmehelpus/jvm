
#ifndef ATTRIBUTE_INFO
#define ATTRIBUTE_INFO

#include "Base_types.hpp"
#include "Attribute_info.hpp"

class Attribute_info {
    public:
        U2 name_index;
        U4 length;
        T_info* info;
};

#endif