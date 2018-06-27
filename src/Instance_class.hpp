#ifndef INSTANCE_CLASS
#define INSTANCE_CLASS

#include <map>

#include "Heap.hpp"
#include "Static_class.hpp"
#include "Typed_element.hpp"

using namespace std;

class Static_class; // solve cross referencing


class Instance_class {

public:
	map<string, Typed_element*> local_fields;
	Static_class *static_class;
	Instance_class(Static_class*);
	Typed_element getField(string);
	bool set_field(string, Typed_element);
	bool set_finals(string, Typed_element);
	void show();
};

#endif