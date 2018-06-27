#include "Static_class.hpp"

using namespace std;
Static_class::Static_class(Reader* reader) {
	this->classe = reader;
	int count = reader->fields_count;
	vector<Field_info> fields = reader->fields;
	for (int i = 0; i < count; i++) {
		if ((fields[i].access_flags & 0x08) && (fields[i].access_flags & 0x010) == 0) {
			Typed_element* typed_element = new Typed_element();
			typed_element->value.l = 0;
			string desc = Displayer::dereference_index(reader->cp->cp_vector, fields[i].descriptor_index);

			switch (desc[0]) {
				case 'B':
                	typed_element->type = TYPE_BOOL;
					break;
				case 'C':
					typed_element->type = TYPE_INT;
					break;
				case 'D':
					typed_element->type = TYPE_DOUBLE;
					break;
				case 'F':
					typed_element->type = TYPE_FLOAT;
					break;
				case 'I':
					typed_element->type = TYPE_INT;
					break;
				case 'J':
					typed_element->type = TYPE_LONG;
					break;
				case 'L':
					typed_element->type = TYPE_REFERENCE;
					break;
				case 'S':
					typed_element->type = TYPE_INT;
					break;
				case 'Z':
					typed_element->type = TYPE_BOOL;
					break;
				case '[':
					typed_element->type = TYPE_REFERENCE;
					break;
			}
			string auxName = Displayer::dereference_index(reader->cp->cp_vector, fields[i].name_index);
			static_fields.insert(pair<string, Typed_element*>(auxName, typed_element));
		}
	}
}

Typed_element Static_class::get_field(string s) {
	Typed_element ret;
	ret.type = TYPE_NOT_SET;

	for (map<string, Typed_element*>::const_iterator i = static_fields.begin(); i != static_fields.end(); i++) {
	   if (i->first == s) {
	   		return *(i->second);
	   }
	}

	return ret;
}

bool Static_class::set_field(string s, Typed_element e) {
	for (map<string, Typed_element*>::const_iterator i = static_fields.begin(); i != static_fields.end(); i++) {
	   	if (i->first == s) {
	   		if (i->second->type == e.type) {
		   		*(i->second) = e;
		   		return true;
	   		} else {
	   			break;
	   		}
	   	}
	}

	return false;
}

bool Static_class::set_finals(string s, Typed_element e) {
	for (map<string, Typed_element*>::const_iterator i = static_fields.begin(); i != static_fields.end(); i++) {
	   	if (i->first == s) {
	   		if (i->second->type == e.type) {
		   		*(i->second) = e;
		   		return true;
	   		} else {
	   			break;
	   		}
	   	}
	}

	return false;
}


Instance_class *Static_class::get_instance() {
	Instance_class *ret = new Instance_class(this);
	Heap::add_object(ret);
	return ret;
}

Reader *Static_class::get_def() {
	return classe;
}