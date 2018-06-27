#include "Operand_stack.hpp"

Operand_stack::Operand_stack(int maximum_size) : max_size(maximum_size), real_max_size(2*maximum_size) {
    typed_element_pushed = false;
};

void Operand_stack::push_type(Typed_element typed_element) {
	this->real_types.push(typed_element.real_type);
	typed_element_pushed = true;
	// this->push(typed_element.value, typed_element.type);
}

//acrescenta um int ao topo da pilha
void Operand_stack::push_type(int x) {
	this->types.push(TYPE_INT);
	if (!typed_element_pushed)
		this->real_types.push(RT_INT);
	this->elements.push(x);

	typed_element_pushed = false;
}

//acrescenta um float ao topo da pilha
void Operand_stack::push_type(float x) {
	Element element;
	element.f = x;
	this->types.push(TYPE_FLOAT);
	if (!typed_element_pushed)
		this->real_types.push(RT_FLOAT);
	this->elements.push(element.i);

	typed_element_pushed = false;
}

//acrescenta um long ao topo da pilha, utilizando 2 slots
void Operand_stack::push_type(long x) {

	this->types.push(TYPE_LONG);
	if (!typed_element_pushed)
		this->real_types.push(RT_LONG);
	this->elements.push(x);
	x >>= 32;
	this->elements.push(x);

	typed_element_pushed = false;
}

//acrescenta um double ao topo da pilha, utilizando 2 slots
void Operand_stack::push_type(double x) {
	Element element;
	element.d = x;
	this->types.push(TYPE_DOUBLE);
	if (!typed_element_pushed)
		this->real_types.push(RT_DOUBLE);
	this->elements.push(element.i);
	element.l >>= 32;
	this->elements.push(element.i);

	typed_element_pushed = false;
}

//acrescenta um int ao topo da pilha
void Operand_stack::push_type(bool x) {
	
	Element element;
	element.b = x;
	this->types.push(TYPE_BOOL);
	if (!typed_element_pushed)
		this->real_types.push(RT_BOOL);
	this->elements.push(element.i);

	typed_element_pushed = false;
}

void Operand_stack::push_type(int *x) {
	Element element;
	element.pi = x;
	this->types.push(TYPE_REFERENCE);
	if (!typed_element_pushed)
		this->real_types.push(RT_REFERENCE);	
	this->elements.push(element.i);
	if (bits64) {
		element.l >>= 32;
		this->elements.push(element.i);
	}

	typed_element_pushed = false;
}



void Operand_stack::push(Element x, uint8_t tipo) {
	switch (tipo) {
		case TYPE_DOUBLE:
			this->push_type(x.d);
			break;
		case TYPE_LONG:
			this->push_type(long(x.l));
			break;
		case TYPE_FLOAT:
			this->push_type(x.f);
			break;
		case TYPE_INT:
			this->push_type(int(x.i));
			break;
		case TYPE_REFERENCE:
			this->push_type((int*)(x.pi));
			break;
		case TYPE_BOOL:
			this->push_type(x.b);
			break;
		default:
			break;
	}
}
