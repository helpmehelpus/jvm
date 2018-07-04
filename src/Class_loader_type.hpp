#ifndef CLASSLOADER
#define CLASSLOADER

#include <vector>

#include "Base_types.hpp"

using namespace std;

/**
 * 
 * Struct responsável por armazenar todos os tamanhos de variáveis da JVM 
 */
struct Class_loader_type {
        /*@{*/
        vector<U1> array; /**< the x coordinate */
        U1 u1; /**< the y coordinate */
        U2 u2; /**< the z coordinate */
        U4 u4; /**< the k coordinate */
        
        /*@}*/
};

#endif
