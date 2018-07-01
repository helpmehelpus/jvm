#include "Local_variable.hpp"



Typed_element Local_variable::get_typed_element(int index)  {
	index *= 2;
	// if (index >= real_max || index < 0)
	// 	throw std::runtime_error("Indice fora dos limites!");


	// if (this->types[index] == INVALID)
	// 	throw std::runtime_error("A posicao acessada contem a segunda parte de uma informacao de 2 slots!");


	Typed_element ret;
	ret.type = this->types[index];

    
	if (this->types[index] == TYPE_LONG || this->types[index] == TYPE_DOUBLE || (this->types[index] == TYPE_REFERENCE && BITS)) {
		ret.value.l = this->elements[index].l;
	} else {
		ret.value.i = this->elements[index].i;
	}

	return ret;
}

void Local_variable::insert_typed_element(Typed_element typed_element, int index) {
	if (index < 0)
		throw std::runtime_error("Indice fora dos limites!");


	// index *= 2;

	this->types.push_back(typed_element.type);

	// this->types[index] = typed_element.type;
	if (this->types[index] == TYPE_LONG || this->types[index] == TYPE_DOUBLE || (this->types[index] == TYPE_REFERENCE && BITS)) {
		this->elements.push_back(Element());
		this->elements.push_back(Element());
		this->elements[index].i = typed_element.value.i;
		this->elements[++index].i = int(typed_element.value.l >> 32);
		
		this->types[index] = INVALID;
	} else {
		this->elements.push_back(Element());
		this->elements[index].i = typed_element.value.i;
	}
}


