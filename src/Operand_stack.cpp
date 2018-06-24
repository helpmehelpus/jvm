#include "Operand_stack.hpp"


Operand_stack::Operand_stack(int maximum_size) : max_size(maximum_size), real_max_size(2*maximum_size) {
    typed_element_pushed = false;
};

void Operand_stack::push(int *x) {
	//caso nao tenha a quantidade necessaria de slots disponiveis, nao empilha nada
	if (this->size()+bits64 >= max) {
		throw std::out_of_range("Excedeu o limite maximo da pilha!");
	}	    

	Element aux;
	aux.pi = x;
	this->types.push(TYPE_REFERENCE);
	if (!typed_element_pushed)
		this->real_types.push(RT_REFERENCE);	
	this->elements.push(aux.i);
	if (bits64) {
		aux.l >>= 32;
		this->elements.push(aux.i);
	}

	typed_element_pushed = false;
}


void Operand_stack::push(int x) {
	//caso ja tenha atingido o tamanho maximo, nao empilha nada
	if (this->size() == max) {
		throw std::out_of_range("Excedeu o limite maximo da pilha!");
	}
	this->types.push(TYPE_INT);
	if (!typed_element_pushed)
		this->real_types.push(RT_INT);
	this->elements.push(x);

	typed_element_pushed = false;
}


//acrescenta um float ao topo da pilha
void Operand_stack::push(float x) {
	//caso ja tenha atingido o tamanho maximo, nao empilha nada
	if (this->size() == max) {
		throw std::out_of_range("Excedeu o limite maximo da pilha!");
	}

	Element aux;
	aux.f = x;
	this->types.push(TYPE_FLOAT);
	if (!typed_element_pushed)
		this->real_types.push(RT_FLOAT);
	this->elements.push(aux.i);

	typed_element_pushed = false;
}

//acrescenta um long ao topo da pilha, utilizando 2 slots
void Operand_stack::push(long x) {
	//caso nao tenha 2 slots disponiveis, nao empilha nada
	if (this->size()+1 >= max) {
		throw std::out_of_range("Excedeu o limite maximo da pilha!");
	}

	this->types.push(TYPE_LONG);
	if (!typed_element_pushed)
		this->real_types.push(RT_LONG);
	this->elements.push(x);
	x >>= 32;
	this->elements.push(x);

	typed_element_pushed = false;
}

//acrescenta um double ao topo da pilha, utilizando 2 slots
void Operand_stack::push(double x) {
	//caso nao tenha 2 slots disponiveis, nao empilha nada
	if (this->size()+1 >= max) {
		throw std::out_of_range("Excedeu o limite maximo da pilha!");
	}

	Element aux;
	aux.d = x;
	this->types.push(TYPE_DOUBLE);
	if (!typed_element_pushed)
		this->real_types.push(RT_DOUBLE);
	this->elements.push(aux.i);
	aux.l >>= 32;
	this->elements.push(aux.i);

	typed_element_pushed = false;
}

//acrescenta um int ao topo da pilha
void Operand_stack::push(bool x) {
	//caso ja tenha atingido o tamanho maximo, nao empilha nada
	if (this->size() == max) {
		throw std::out_of_range("Excedeu o limite maximo da pilha!");
	}	

	Element aux;
	aux.b = x;
	this->types.push(TYPE_BOOL);
	if (!typed_element_pushed)
		this->real_types.push(RT_BOOL);
	this->elements.push(aux.i);

	typed_element_pushed = false;
}



//recebe um elemento tipado e chama a funcao adequada para tratar o tipo
void Operand_stack::push(Typed_element te) {
	this->real_types.push(te.real_type);
	typed_element_pushed = true;
	this->push(te.value, te.type);
}

//checa o tipo do elemento que deve ser adicionado e chama a funcao adequada
void Operand_stack::push(Element x, uint8_t tipo) {
	switch (tipo) {
		case TYPE_DOUBLE:
			this->push(x.d);
			break;
		case TYPE_LONG:
			this->push(long(x.l));
			break;
		case TYPE_FLOAT:
			this->push(x.f);
			break;
		case TYPE_INT:
			this->push(int(x.i));
			break;
		case TYPE_REFERENCE:
			this->push((int*)(x.pi));
			break;
		case TYPE_BOOL:
			this->push(x.b);
			break;
		default:
			break;
	}
}

//retorna o tamanho da pilha
int Operand_stack::size() {
	return this->elements.size();
}

int Operand_stack::getMaxSize() {
	return this->real_max_size;
}

//retorna 1 se a pilha esta vazia e 0 caso nao esteja
bool Operand_stack::empty() {
	return this->elements.empty();
}

void Operand_stack::printALL() {
	Operand_stack aux(this->max);

	while (!this->empty()) {
		cout << this->get_string() << endl;
		aux.push(this->pop_typed_element());
	}

	while (!aux.empty()) {
		this->push(aux.pop_typed_element());
	}
}