#ifndef CPINFO
#define CPINFO


#include "Base_types.hpp"
#include <vector>
#include "Class_loader_type.hpp"
class Cp_info {
    public:
        U1 tag;
        std::vector<Class_loader_type> info;
};

#endif