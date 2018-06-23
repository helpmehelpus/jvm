#include "Local_variable.hpp"

// Local_variable::Local_variable (U2 max_size) : max(max_size), two_slots(false), real_max(2*max_size) {
	
// }


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