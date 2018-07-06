#ifndef CPINFO
#define CPINFO

#include <vector>

#include "Base_types.hpp"
#include "Class_loader_type.hpp"

using namespace std;

/** \brief Struct que representa uma entrada do \e Constant Pool
 */
struct Cp_info {
    /*@{*/

    public:
        U1 tag; /**< Indica o tipo da entrada */
        vector<Class_loader_type> info; /**< Informação acerca da constante em questão */
    /*@}*/
};

#endif