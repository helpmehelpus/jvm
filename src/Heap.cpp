#include "Heap.hpp"

vector<Instance_class*> Heap::objetos;


void Heap::add_object(Instance_class *ci) {
	objetos.push_back(ci);
}