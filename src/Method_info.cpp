#include "Method_info.hpp"
#include "Reader.hpp"
#include "Attribute_info.hpp"
#include "Displayer.hpp"
#include <vector>

vector<Method_info> Method_info::read_methods(FILE* fp,  vector<Cp_info> cp_vector, int length) {
	vector<Method_info> ret;

	for (int i = 0; i < length; i++) {
		ret.push_back(read_method(fp,cp_vector));
	}
	return ret;
}

Method_info Method_info::read_method(FILE* fp, vector<Cp_info> cp_vector) {
	Method_info method;
	Reader reader;

	method.access_flags = reader.read_U2(fp) & 0xFFF;
	method.name_index = reader.read_U2(fp);
	method.descriptor_index = reader.read_U2(fp);
	method.attributes_count = reader.read_U2(fp);
	// method.attributes = Attribute_info::read_attributes(fp,cp_vector, method.attributes_count);
	for(int i = 0; i < method.attributes_count; i++)
		method.attributes.push_back(Attribute_info::read_attribute(fp,cp_vector));

	return method;
}

string Method_info::get_method_flags(unsigned short flags) {
	string ret = "";

	if (flags & 0x01) {
		ret += "ACC_PUBLIC ";
	}

	if (flags & 0x02) {
		ret += "ACC_PRIVATE ";
	}

	if (flags & 0x04) {
		ret +=  "ACC_PROTECTED ";
	}

	if (flags & 0x08) {
		ret +=  "ACC_STATIC ";
	}

	if (flags & 0x010) {
		ret +=  "ACC_FINAL ";
	}

	if (flags & 0x020) {
		ret +=  "ACC_SYNCHRONIZED ";
	}

	if (flags & 0x0100) {
		ret +=  "ACC_NATIVE ";
	}

	if (flags & 0x0400) {
		ret += "ACC_ABSTRACT ";
	}

	if (flags & 0x0800) {
		ret +=  "ACC_STRICT ";
	}
	return ret;
}


// void display_method_index(Method_info f,  vector<Cp_info> cp_vector, int index) {
// 	printf("\tMethod %d : " ,index);
//     printf("\n");

// 	printf("\tFlags: %s ",  get_method_flag(f.access_flags));
	
// 	printf("\t\tName:  %s ", Displayer::dereference_index(cp_vector, f.name_index));
//     printf("\n");

// 	printf("\t\tDescription:  %s ", Displayer::dereference_index(cp_vector, f.descriptor_index));
//     printf("\n");

// 	printf("\t\tAttributes Count:  %d ", (int) f.attributes_count);
//     printf("\n");
// 	for (int i = 0; i < f.attributes_count; i++) {
// 		printf("\t Attribute %d: ", i);
//         printf("\n");
// 		display_attribute(f.attributes[i], cp_vector);
// 	}
// }

// void display_method (Method_info f,  vector<Cp_info> cp_vector) {
// 	printf("\tFlags: %s \n" , get_method_flag(f.access_flags));
// 	printf("\tName: %s \n", Displayer::dereference_index(cp_vector, f.name_index));
//     printf("\tDescription: %s \n", Displayer::dereference_index(cp_vector, f.descriptor_index));
//     printf("\tAttributes Count: %d  \n", (int) f.attributes_count);
    
// 	for (int i = 0; i < f.attributes_count; i++) {
// 		printf("\t\tAttributes  %d : ", i);
//         printf("\n");
// 		display_attribute(f.attributes[i], cp_vector);
// 	}
// }

// void display_methods (Method_info *f,  vector<Cp_info> cp_vector, int methods_length) {
//   	printf("Methods Count : %d\n", methods_length);
    
// 	for (int i = 0; i < methods_length; i++) {
// 		display_method_index(f[i], cp_vector, i);
// 	}
// }
