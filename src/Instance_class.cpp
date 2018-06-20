#include "Instance_class.hpp"

Instance_class::Instance_class(Static_class* c) {
	this->classe = c;

	int count = classe->get_def()->fields_count;
	vector<Field_info> fields = classe->get_def()->fields;
	for (int i = 0; i < count; i++) {
		if ((fields[i].access_flags & 0x08) == 0) {
			Typed_element *auxValue = new Typed_element();
			auxValue->value.l = 0;
			string desc = Displayer::dereference_index(classe->get_def()->cp->cp_vector, fields[i].descriptor_index);

			switch (desc[0]) {
				case 'B':
					auxValue->type = TYPE_BOOL;
					break;
				case 'C':
					auxValue->type = TYPE_INT;
					break;
				case 'D':
					auxValue->type = TYPE_DOUBLE;
					break;
				case 'F':
					auxValue->type = TYPE_FLOAT;
					break;
				case 'I':
					auxValue->type = TYPE_INT;
					break;
				case 'J':
					auxValue->type = TYPE_LONG;
					break;
				case 'L':
					auxValue->type = TYPE_REFERENCE;
					break;
				case 'S':
					auxValue->type = TYPE_INT;
					break;
				case 'Z':
					auxValue->type = TYPE_BOOL;
					break;
				case '[':
					auxValue->type = TYPE_REFERENCE;
					break;
			}
			string auxName = Displayer::dereference_index(classe->get_def()->cp->cp_vector, fields[i].name_index);
			local_fields.insert(pair<string, Typed_element*>(auxName, auxValue));
		}
	}	
}

Typed_element Instance_class::getField(string s) {
	Typed_element ret;
	ret.type = TYPE_NOT_SET;

	for (map<string, Typed_element*>::const_iterator i = local_fields.begin(); i != local_fields.end(); i++) {
	   if (i->first == s) {
	   		return *(i->second);
	   }
	}

	return ret;
}

Static_class *Instance_class::getStatic() {
	return classe;
}

bool Instance_class::set_field(string s, Typed_element e) {
	for (map<string, Typed_element*>::const_iterator i = local_fields.begin(); i != local_fields.end(); i++) {
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

bool Instance_class::set_finals(string s, Typed_element e) {
	for (map<string, Typed_element*>::const_iterator i = local_fields.begin(); i != local_fields.end(); i++) {
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

void Instance_class::show() {
	for (map<string, Typed_element*>::const_iterator i = local_fields.begin(); i != local_fields.end(); i++) {
	   cout << i->first << endl;
	}
}
