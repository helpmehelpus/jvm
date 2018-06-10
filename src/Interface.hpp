#ifndef INTERFACES
#define INTERFACES

#include "Base_types.hpp"
#include "Constant_pool.hpp"

using namespace std;

class Interface {
    public:
        static vector<U2> read_interfaces(FILE *fp, int length);
};

#endif