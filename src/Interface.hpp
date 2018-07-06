#ifndef INTERFACES
#define INTERFACES

#include "Base_types.hpp"
#include "Constant_pool.hpp"

using namespace std;

/*! \class Interface
 *  \brief Classe responsável por ler as interfaces de um .class
 *
 * 
 */
class Interface {
    public:
        /*!
        * Ler as interfaces a partir de um arquivo .class
        * @param fp ponteiro para o arquivo .class
        * @param length número de interfaces para ler
        * @return retorna um vetor com as interfaces
        */
        static vector<U2> read_interfaces(FILE *fp, int length);
};

#endif