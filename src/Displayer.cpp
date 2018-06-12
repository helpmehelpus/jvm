#include "Displayer.hpp"
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

void Displayer::display_version(U2 min_version, U2 max_version) {
	cout << "\nCLASS VERSION: (" << max_version << "."<<  min_version << ")\t" << endl << endl; 	
}

long u4_to_long(U4 high, U4 low) {
	long ret;
	ret = (unsigned int)high;
	ret<<= 32;
	ret+= (unsigned int)low;
	return ret;
}

double u4_to_double(U4 high, U4 low) {
	double ret;
	long limits = u4_to_long(high, low);
	
	if (limits == 0x7ff0000000000000L) {
		//retornar infinito??
	} else if (limits == 0xfff0000000000000L) {
		//retornar menos infinito??
	} else if ((limits >= 0x7ff0000000000001L) && (limits <= 0x7ffffffffffffL)) {
		//retornar NaN??
	} else if ((limits >= 0xfff0000000000001L) && (limits <= 0xffffffffffffffffL)) {
		//também retornar NaN??
	} else {
		int s = ((limits >> 63) == 0) ? 1 : -1;
		int e = ((limits >> 52) & 0x7ffL);
		long m = (e == 0) ? (limits & 0xfffffffffffffL) << 1 : (limits & 0xfffffffffffffL) | 0x10000000000000L;
		
		ret = s * m * pow(2, (e-1075));
	}	
	return ret;
}

float u4_to_float(U4 number) {
	float ret;
	
	int sig = ((number >> 31) == 0) ? 1 : -1;
	int exponent = ((number >> 23) & 0xff);
	int mantissa = (exponent == 0) ? (number & 0x7fffff) << 1 : (number & 0x7fffff) | 0x800000;

	ret = sig * mantissa * pow(2, (exponent-150));

	return ret;
}

string display_UTF8(vector <U1> v, U2 size) {
	int i;

	string ret = "";

	for(i = 0; i < v.size(); i++) {
		if (!(v[i] & 0x80)) { //Single byte UTF8
			ret += (char)v[i];
		} else {
			unsigned short aux_current;
			if (!(v[i+1] & 0x20)) { //Two byte UTF8
				aux_current = ((v[i] & 0x1f) << 6) + (v[i+1] & 0x3f);
			} else { //Three byte UTF8
				aux_current = ((v[i] & 0xf) << 12) + ((v[i+1] & 0x3f) << 6) + (v[i+2] & 0x3f);
				i++;
			}
			i++;
			ret += (char)aux_current;
		}
	}
	return ret;
}

string Displayer::dereference_index (vector <Cp_info> cp_vector, U2 index) {
	switch (cp_vector[index].tag) {
		case UTF8: 
			return display_UTF8(cp_vector[index].info[0].array, cp_vector[index].info[0].u2);
		case CLASS: 
		case STRING:
			return dereference_index(cp_vector, cp_vector[index].info[0].u2);
		case NAMEANDTYPE: 
			return (dereference_index(cp_vector, cp_vector[index].info[0].u2) + ":" + dereference_index(cp_vector, cp_vector[index].info[1].u2));
		case METHODREF: 
		case INTERFACEMETHODREF:
		case FIELDREF:
			return (dereference_index(cp_vector, cp_vector[index].info[0].u2) + "." + dereference_index(cp_vector, cp_vector[index].info[1].u2));
	}	
	return "";
}

void Displayer::display_cp(Constant_pool *constant_pool, U2 cp_length) {
	vector<Cp_info> cp = constant_pool->cp_vector;
	int index;

    printf("______________________________________________Constant__Pool______________________________________________\n\n");
    printf(" Id \t Type \t\t\t Value \t\t\t\tExtra Info\n");
    printf("__________________________________________________________________________________________________________\n\n");

	for (int i = 1; i < cp_length; i++) {
        printf(" %d:%s ", i, name_types[cp[i].tag].c_str());

		switch (cp[i].tag) {
			case UTF8: 
                cout << "\t\t\t";
				cout <<  display_UTF8(cp[i].info[0].array, cp[i].info[0].u2).c_str();
				break;
			case INTEGER: 
				cout << "\t\t\t";
				cout << cp[i].info[0].u4;
				break;
			case FLOAT: 
				cout << "\t\t\t";
				cout << u4_to_float(cp[i].info[0].u4);
				break;
			case LONG: 
				cout << "\t\t\t";				
				printf("%ld", u4_to_long(cp[i].info[0].u4, cp[i+1].info[0].u4));
				i++; 
				break;
			case DOUBLE: 
				cout << "\t\t\t";
				cout << u4_to_double(cp[i].info[0].u4, cp[i+1].info[0].u4);
				i++; 
				break;
			case CLASS: 
			case STRING:
				cout << "\t\t\t";
				cout << cp[i].info[0].u2;
				cout << "\t\t\t\t//" << dereference_index(cp,i);
				break;
			case NAMEANDTYPE: 
				cout << "\t\t\t" <<  cp[i].info[0].u2 << ":" << cp[i].info[1].u2;
				cout << "\t\t\t\t//" << dereference_index(cp,i);
				break;
			case METHODREF: 
			case INTERFACEMETHODREF:
			case FIELDREF:
				cout << "\t\t\t" <<  cp[i].info[0].u2 << "." <<  cp[i].info[1].u2;
				cout << "\t\t\t\t//" << dereference_index(cp,i);
				break;
		}
		printf("\n");
	}
    printf("__________________________________________________________________________________________________________\n\n");
}

void Displayer::display_access_flags(U2 access_flags) {
	printf("flags: ");
	if (access_flags & 0x01) 
		cout << " " << flag_names[0];
	if(access_flags & 0x010) 
		cout << " " << flag_names[1];
	if(access_flags & 0x020) 
		cout << " " << flag_names[2];
	if(access_flags & 0x0200) 
		cout << " " << flag_names[3];
	if(access_flags & 0x0400) 	
		cout << " " << flag_names[4];
	
	printf(" 0x%x\n", access_flags);
}

void Displayer::display_class_names(U2 this_class, U2 super_class, vector<Cp_info> cp_vector){
	cout << "This class: " << dereference_index(cp_vector, this_class) << endl;
	cout << "Super class: " << dereference_index(cp_vector,super_class) << endl;
}

void Displayer::display_interfaces(vector<U2> interfaces, vector<Cp_info> cp_vector) {
	int i;
	cout << "Interfaces count: " <<  interfaces.size() << endl;
	for (i = 0; i < interfaces.size(); i++) {
		display_interface_by_index(interfaces[i], cp_vector, i);
	}
}

void Displayer::display_interface_by_index(U2 interface, vector<Cp_info> cp_vector, int index) {
	cout << "\tInterface " << index << " : " << dereference_index(cp_vector, interface) << endl;
}

void Displayer::display_fields(vector <Field_info> f, vector <Cp_info> cp_vector, int length){
	cout << "Fields count: " << length << endl;
	for(int i = 0; i < length; i++){
		Displayer::display_field_by_index(f[i],cp_vector,i);
	}
}

void Displayer::display_field_by_index(Field_info f, vector <Cp_info> cp_vector, int index) {
	printf("\tField %d : \n", index);	
	printf("\t\tFlags: %s \n", Field_info::get_field_flags(f.access_flags).c_str());
	printf("\t\tName: %s\n" , Displayer::dereference_index(cp_vector, f.name_index).c_str() ) ;	
	printf("\t\tDescription: %s \n" , Displayer::dereference_index(cp_vector, f.descriptor_index).c_str()) ;
	printf("\t\tAttributes count: %d \n",(int) f.attributes_count) ;

	for (int i = 0; i < f.attributes_count; i++) {
		printf("Attribute %d: ", i);
		Displayer::display_attribute(f.attributes[i], cp_vector);
	}
}

void Displayer::display_attributes(vector<Attribute_info> attr, vector<Cp_info> cp_vector, int length){
	for(int i = 0; i < length; i++)
		display_attribute(attr[i], cp_vector);
}

void Displayer::display_attribute(Attribute_info attr, vector<Cp_info> cp) {

	string attribute_name = Displayer::dereference_index(cp, attr.name_index);
	cout << "\t\tName: " << attribute_name << endl;
	cout << "\t\tSize: " << attr.length << endl;

	if(attribute_name == "ConstantValue") {
		//Caso ignorar em silêncio implique em não mostrar nem nome nem tamanho
		
		cout << "\t\tConstant Value: " << attr.info.constant_value.constant_value_index << endl;
	}
	else if(attribute_name == "Code") {
		cout << "\t\tMax Stack: " << attr.info.code.max_stack << endl;
		cout << "\t\tMax Locals: " << attr.info.code.max_locals << endl;
		cout << "\t\tCode Length: " << attr.info.code.code_length << endl;

		int i = 0;
		
		while(i < attr.info.code.code_length) {
			cout << "\t\tCode #" << i << ":" << attr.get_mnemonic(attr.info.code.code[i]);
			attr.get_opcode_params(attr.info.code.code, &i);
			cout << endl;
		}

		cout << "\t\tException Table Length: " << attr.info.code.exception_table_length << endl;

		for(int i = 0; i < attr.info.code.exception_table_length; i++ ) {
			cout << "\t\tStart PC: " << attr.info.code.exception_table[i].start_pc << endl;
			cout << "\t\tEnd PC: " << attr.info.code.exception_table[i].end_pc << endl;
			cout << "\t\tHandler PC: " << attr.info.code.exception_table[i].handler_pc << endl;
			cout << "\t\tCatch Type: " << attr.info.code.exception_table[i].catch_type << endl;
		}

		cout << "\t\tAttribute Count: " << attr.info.code.attribute_count << endl;

		for(int i = 0; i < attr.info.code.attribute_count; i++ ) 
			display_attribute(attr.info.code.attributes[i],cp);
	}

	else if(attribute_name == "Exceptions") {
		cout << "\t\tNumber of Exceptions: " << attr.info.exception.number_of_exceptions << endl;

		for(int i = 0; i < attr.info.exception.number_of_exceptions; i++ )
			cout << "\t\tException Index: " << attr.info.exception.exception_index_table[i] << endl;
	}
	else if(attribute_name == "LineNumberTable") {
		cout << "\t\tLineNumberTable Length: " << attr.info.line_number_table.length << endl;
		for(int i = 0; i < attr.info.line_number_table.length; i++ ){
			cout << "\t\tStart_PC: " <<  attr.info.line_number_table.line_number_table_vector[i].start_pc;
			cout << "\t\tLine_number: " <<  attr.info.line_number_table.line_number_table_vector[i].line_number << endl;

		}
	}
}

void Displayer::display_methods(vector <Method_info> f,  vector<Cp_info> cp_vector, int length) {
	cout << "Methods count: " << length << endl;
	for (int i = 0; i < length; i++) {
		Displayer::display_method_by_index(f[i], cp_vector, i);
	}
}
void Displayer::display_method_by_index(Method_info m, vector <Cp_info> cp_vector, int index) {
	cout << "\tMethod " << index << ":" << endl;
	printf("\t\tFlags: %s \n" , Method_info::get_method_flags(m.access_flags).c_str());
	printf("\t\tName: %s \n", Displayer::dereference_index(cp_vector, m.name_index).c_str());
    printf("\t\tDescription: %s \n", Displayer::dereference_index(cp_vector, m.descriptor_index).c_str());
    printf("\t\tAttributes Count: %d  \n", (int) m.attributes_count);
    
	for (int i = 0; i < m.attributes_count; i++) {
		printf("\t  Attribute  %d: ", i);
        printf("\n");
		Displayer::display_attribute(m.attributes[i], cp_vector);
	}
}



