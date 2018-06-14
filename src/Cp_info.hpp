#ifndef CPINFO
#define CPINFO

#include <vector>

#include "Base_types.hpp"
#include "Class_loader_type.hpp"

using namespace std;

struct Cp_info {
    public:
        U1 tag;
        vector<Class_loader_type> info;
};

#endif