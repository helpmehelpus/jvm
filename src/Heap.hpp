#ifndef HEAP
#define HEAP

#include "Instance_class.hpp"
#include "vector"

class Instance_class;


using namespace std;

/*! \brief Classe responsável pela área de dados de tempo de execução a partir da qual a memória para todas as instâncias e matrizes de classe é alocada
 *
 * 
 */
class Heap {

public:
	static vector<Instance_class*> objetos;
	/*!
    * Adiciona um objeto à \e Heap da JVM
    * @param ci
    */
	static void add_object(Instance_class*);
};
#endif