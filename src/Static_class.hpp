#ifndef STATIC_CLASSE
#define STATIC_CLASSE

#include <map>

#include "Instance_class.hpp"
#include "Reader.hpp"
#include "Typed_element.hpp"
#include "Displayer.hpp"
#include "Operand_stack.hpp"
#include "Heap.hpp"

class Instance_class;
class Reader;

using namespace std;

/*! \class Static_class
 * \brief Classe que define as classes estáticas.
 *         
 */
class Static_class {
public:
	map<string, Typed_element*> static_fields;
	Reader *reader_class;
	Static_class(Reader*);
	/*!
    * Pega um \e field da \e struct.
    * @param s \e String de comparação com o campo requisitado.
    * @return Retorna o \e field.
    */
	Typed_element get_field(string);
	/*!
    * Define um \e field da \e struct.
    * @param s String a ser comparada.
    * @param e Elemento a ser definido.
    * @return Retorna se o \e field foi definido.
    */
	bool set_field(string, Typed_element);
	/*!
    * Define \e field como \e final.
    * @param s String a ser comparada.
    * @param e Elemento a ser definido.
    * @return Retorna se o \e field foi definido.
    */
	bool set_finals(string, Typed_element);
	/*!
    * Provê uma referência para  uma instância da classe em questão.
	* @return Retorna a instância da classe
    */
	Instance_class *get_instance();
	
};

#endif