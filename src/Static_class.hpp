#ifndef CLASSE_CLASSE
#define CLASSE_CLASSE

class Static_class;

#include "Reader.hpp"
#include "Typed_element.hpp"
// #include "Heap.hpp"
#include "Instance_class.hpp"
#include <map>

using namespace std;

class Static_class {
private:
	map<string, Typed_element*> staticFields;
	Reader *classe;
public:
	Static_class(Reader*);
	Typed_element getField(string);
	bool set_field(string, Typed_element);
	bool set_finals(string, Typed_element);
	Instance_class *getInstance();
	Reader *get_def();
};



#endif