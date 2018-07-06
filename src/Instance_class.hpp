#ifndef INSTANCE_CLASS
#define INSTANCE_CLASS

#include <map>

#include "Heap.hpp"
#include "Static_class.hpp"
#include "Typed_element.hpp"

using namespace std;

class Static_class; // solve cross referencing

/*! \brief Classe que serve para instanciar classes que são criadas usando uma nova instrução da JVM
 *
 * 
 */

class Instance_class {

public:
	map<string, Typed_element*> local_fields;
	Static_class *static_class;
	Instance_class(Static_class*);
	Typed_element getField(string);
	/*!
    * Definir um campo (field) na instância da classe
    * @param s
	* @param e
	* @return booleano se foi possível definir um \e field
    */
	bool set_field(string, Typed_element);
	/*!
    * Descrição 
    * @param s
	* @param e
	* @return booleano 
    */
	bool set_finals(string, Typed_element);
	/*!
    * Imprimir na tela o valor da variável \e local_fields 
    */
	void show();
};

#endif