#include "Operand_stack.hpp"

using namespace std;

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

uint8_t Operand_stack::top_type() {
	return ((!this->types.empty()) ? (this->types.top()) : (-1));
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

Typed_element Operand_stack::pop_typed_element() {
	Typed_element typed_element;
	if (this->types.empty()) {
		cout << "POP_TYPED_ELEMENT: types vector is empty" << endl;
		return typed_element;
	}

	
	typed_element.type = this->types.top();
	typed_element.real_type = this->real_types.top();
	typed_element.value = this->pop_element();

	return typed_element;
}

Element Operand_stack::pop_element(){
	Element element;
	//caso a pilha esteja vazia, elementorna um elemento vazio
	if (this->elements.empty()) {
		cout << "POP_ELEMENT: elements vector is empty" << endl;
		return element;
	}

	element = this->top_value();

	//faz o pop em um slot
	this->elements.pop();

	//checa se e necessario fazer o pop para mais um slot
	if (this->types.top() == TYPE_LONG || this->types.top() == TYPE_DOUBLE ||
	   (this->types.top() == TYPE_REFERENCE && bits64)) {
		this->elements.pop();
	}

	//tira o tipo do elemento que foi desempilhado da pilha de types
	this->types.pop();
	this->real_types.pop();

	return element;
}

Element Operand_stack::top_value() {
	Element element;

	//caso a pilha esteja vazia, elementorna um elemento vazio
	if (this->elements.empty()) {
		return element;
	}	

	//pega o primeiro slot da pilha
	element.i = this->elements.top();

	//checa se e necessario juntas o segundo slot tambem 
	if (this->types.top() == TYPE_LONG || this->types.top() == TYPE_DOUBLE || (this->types.top() == TYPE_REFERENCE && bits64)) {
		uint32_t aux = element.i;
		this->elements.pop();
		element.l = long((long(element.i)<<32) + this->elements.top());
		this->elements.push(aux);
	}	

	return element;
}