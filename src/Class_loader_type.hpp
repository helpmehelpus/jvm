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
        vector<U1> array; /**< vetor de elementos de 1 byte */
        U1 u1; /**< variável que contém 1 byte  */
        U2 u2; /**< variável que contém 2 bytes */
        U4 u4; /**< variável que contém 4 bytes */
        
        /*@}*/
};

#endif
