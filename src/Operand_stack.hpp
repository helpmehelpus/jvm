#ifndef OPERAND_STACK
#define OPERAND_STACK

#include <cstdint>
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

class Operand_stack {
public:
	Operand_stack(int);
	
	stack<uint32_t> elements;
	stack<uint8_t> types;
	stack<uint8_t> real_types;
	bool typed_element_pushed;
	static const bool bits64 = (sizeof(int*) == 8);
	const int real_max_size;
	uint8_t top_type();
	Element top_value();
	Element pop();
	Typed_element pop_typed_element();
    string get_string();
	void push(int);
    void push(long);
    void push(float);
	void push(double);
	void push(bool);
	void push(int*);
	void push(Typed_element);
	void push(Element, uint8_t);
	int size();

	//Check THIS
	int getMaxSize();

	bool empty();
	void printALL();
	const int max_size;
};

#endif