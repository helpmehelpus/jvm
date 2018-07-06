#ifndef OPERAND_STACK
#define OPERAND_STACK

#include <cstdint>
#include <iostream>
#include <stack>
#include <stdbool.h>
#include <sstream>
#include <string>

#include "Base_types.hpp"
#include "Element.hpp"
#include "Typed_element.hpp"

#define BITS (sizeof(int*) == 8)

#define INVALID 99
#define TYPE_NOT_SET 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_LONG 3
#define TYPE_DOUBLE 4
#define TYPE_BOOL 5
#define TYPE_REFERENCE 6

using namespace std;

/*! \class Operand_stack
 * 	\brief Classe responsável por garantir que cada frame contenha uma pilha \e LIFO 
 *
 * 
 */
class Operand_stack {
public:
	Operand_stack(int);
	
	stack<uint32_t> elements;
	stack<uint8_t> types;
	stack<uint8_t> real_types;
	bool typed_element_pushed;
	static const bool bits64 = (sizeof(int*) == 8);
	const int real_max_size;
	/*!
    * Pega o tipo da variável que está no topo da pilha
	* @return retorna o elemento
    */
	uint8_t top_type();
	/*!
    * Pega o elemento que está no topo da pilha \e Element
	* @return retorna o elemento
    */
	Element top_value();
	/*!
    * Desempilha o elemento que está na pilha de \e Element
	* @return retorna o elemento desempilhado
    */
	Element pop_element();
	/*!
    * Desempilha o elemento que está na pilha de \e Typed_element
	* @return retorna o elemento desempilhado
    */
	Typed_element pop_typed_element();
	/*!
    * Acrescenta um inteiro ao topo da pilha, utilizando 2 slots
	* @param x inteiro a ser empilhado 
    */
	void push_type(int);
	/*!
    * Acrescenta um inteiro ao topo da pilha
	* @param x inteiro a ser empilhado 
    */
    void push_type(long);
	/*!
    * Acrescenta um long ao topo da pilha, utilizando 2 slots
	* @param x long a ser empilhado 
    */
    void push_type(float);
	/*!
    * Acrescenta um float ao topo da pilha
	* @param x float a ser empilhado 
    */
	void push_type(double);
	/*!
    * Acrescenta um double ao topo da pilha, utilizando 2 slots
	* @param x double a ser empilhado 
    */
	void push_type(bool);
	/*!
    * Acrescenta um bool ao topo da pilha
	* @param x bool a ser empilhado 
    */
	void push_type(int*);
	
	/*!
    * Acrescenta um elemento ao topo da pilha
	* @param typed_element elemento a ser empilhado 
    */
	void push_type(Typed_element);
	
	/*!
    * Acrescenta um elemento ao topo da pilha, utilizando 2 slots
	* @param element elemento a ser empilhado 
    */
	void push_type(Element, uint8_t);
	
	/*!
    * Acrescenta um elemento ao topo da pilha, utilizando 2 slots
	* @param x elemento a ser empilhado 
	* @param tipo tipo do elemento a ser empilhado
    */
	void push(Element x, uint8_t tipo);
	
	int size();

	/*!
    * Retorna a string com os valores da pilha de operandos
	* @return string com os valores da pilha  
    */
    string get_string();
	
	/*!
    * Debuga a pilha de operandos
	* 
    */
	void debug_operand_stack();
	
	/*!
    * Verifica se a pilha de operandos está vazia
	* @return retorna um booleano se a pilha está vazia
	* 
    */
	bool empty();
	
	void printALL();
	const int max_size;
};

#endif