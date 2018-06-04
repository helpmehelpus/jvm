#ifndef INTERFACES
#define INTERFACES


#include "Base_types.hpp"
#include "Constant_pool.hpp"

using namespace std;

class Interface {
    public:
        int length;
        vector<U2> read(FILE *fp, int length);

};



#endif