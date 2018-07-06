#include "Local_variable.hpp"


Local_variable::Local_variable(U2 size){
	this->elements.resize(size);
	this->types.resize(size);
	
}
Local_variable::Local_variable(){
	
}
Typed_element Local_variable::get_typed_element(int index) const {
	// index *= 2;
	// if (index >= real_max || index < 0)
	// 	throw std::runtime_error("Indice fora dos limites!");


	if (this->types[index] == INVALID)
		throw std::runtime_error("A posicao acessada contem a segunda parte de uma informacao de 2 slots!");


	Typed_element ret;
	ret.type = this->types[index];
	

    
	if (this->types[index] == TYPE_LONG || this->types[index] == TYPE_DOUBLE || (this->types[index] == TYPE_REFERENCE && BITS)) {
		long aux = this->elements[index+1].l << 32;
		ret.value.l = (long(aux + this->elements[index].i));

	} else {
		ret.value.i = this->elements[index].i;
	}

	return ret;
}

void Local_variable::insert_typed_element(Typed_element typed_element, int index) {

	if (index < 0)
		throw std::runtime_error("Indice fora dos limites!");

	if (typed_element.type == TYPE_LONG || typed_element.type == TYPE_DOUBLE || (typed_element.type == TYPE_REFERENCE && BITS)) {
		this->types[index] = typed_element.type;
		this->elements[index].i = typed_element.value.i;
		this->elements[++index].i = int(typed_element.value.l >> 32);
		this->types[index] = INVALID;


	} else {
		this->types[index] = typed_element.type;
		this->elements[index].i = typed_element.value.i;
		
		
	}
}


void Local_variable::debug_local_variables() const{
	for(int i = 0; i < this->elements.size(); i++){
		

		cout << "[" << i << "]TYPE: " << (int)this->types[i];
		printf(" Hex: %x", this->elements[i].i);
		cout << " Valor: " << int(this->elements[i].i) << endl;
		// cout << " Hexa: " << int(this->elements[i].i) << hex << endl;
	}
}

