#ifndef INSTANCE_CLASS
#define INSTANCE_CLASS

#include <map>

#include "Heap.hpp"
#include "Static_class.hpp"
#include "Typed_element.hpp"

using namespace std;

class Instance_class {
private:
	map<string, Typed_element*> localFields;
	Static_class *classe;
public:
	Instance_class(Static_class*);
	Static_class *getStatic();
	Typed_element getField(string);
	bool set_field(string, Typed_element);
	bool set_finals(string, Typed_element);
	void show();
};

#endif