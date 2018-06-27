#ifndef STATIC_CLASSE
#define STATIC_CLASSE

#include <map>

#include "Instance_class.hpp"
#include "Reader.hpp"
#include "Typed_element.hpp"
#include "Displayer.hpp"
#include "Operand_stack.hpp"
#include "Heap.hpp"

class Instance_class;

using namespace std;

class Static_class {
public:
	map<string, Typed_element*> static_fields;
	Reader *classe;
	Static_class(Reader*);
	Typed_element get_field(string);
	bool set_field(string, Typed_element);
	bool set_finals(string, Typed_element);
	Instance_class *get_instance();
	Reader *get_def();
};

#endif