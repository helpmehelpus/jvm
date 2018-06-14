#ifndef OPERAND_STACK
#define OPERAND_STACK

#include <stack>
#include <cstdint>
#include <string>
#include <sstream>
#include <stdbool.h>
#include "Base_types.hpp"
#include "Typed_element.hpp"
#include "Element.hpp"


#define INVALID 99
#define TYPE_NOT_SET 0
#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_LONG 3
#define TYPE_DOUBLE 4
#define TYPE_BOOL 5
#define TYPE_REFERENCE 6


class Operand_stack {
private:
	std::stack<uint32_t> elements;
	std::stack<uint8_t> types;
	std::stack<uint8_t> real_types;
	bool type_pushed;
	static const bool bits64 = (sizeof(int*) == 8);
	const int realMax;
public:
	Operand_stack(int);
	uint8_t top_type();
	Element top_value();
	Element pop();
	Typed_element popTyped();
    std::string getString();
	void push(int);
    void push(long);
    void push(float);
	void push(double);
	void push(bool);
	void push(int*);
	void push(Typed_element);
	void push(Element, uint8_t);
	int size();
	int getMaxSize();
	bool empty();
	void printALL();
	const int max;
};

#endif