#ifndef INTERFACES
#define INTERFACES


#include "Base_types.hpp"
#include "Constant_pool.hpp"

class Interface {
    public:
        int length;
        Interface(FILE *fp, int length);

};



#endif