#ifndef HEAP
#define HEAP

#include "Instance_class.hpp"
#include "vector"

class Instance_class;


using namespace std;
class Heap {

public:
	static vector<Instance_class*> objetos;
	static void add_object(Instance_class*);
};
#endif