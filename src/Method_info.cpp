#include "Method_info.hpp"
#include "Reader.hpp"
#include "Attribute_info.hpp"
#include "Displayer.hpp"

Method_info read_method (FILE* fp, vector<Cp_info> cp_vector) {
	Method_info aux;

	aux.access_flags = Reader::read_U2(fp) & 0xFFF;
	aux.name_index = Reader::read_U2(fp);
	aux.descriptor_index = Reader::read_U2(fp);
	aux.attributes_count = Reader::read_U2(fp);
	aux.attributes = Attribute_info::read_attributes(fp,cp_vector, aux.attributes_count);
	

	return aux;
}

Method_info *read_methods (FILE* fp, int length,  vector<Cp_info> cp_vector) {
	Method_info *ret = (Method_info *) malloc(sizeof(Method_info) * length);

	for (int i = 0; i < length; i++) {
		ret[i] = read_method(fp,cp_vector);
	}

	return ret;
}

char*  get_method_flag (uint16_t flags) {
	char* ret = (char*)malloc(sizeof(char)*255);

	if (flags & 0x01) {
		strcat(ret, " ACC_PUBLIC");
	}

	if (flags & 0x02) {
		strcat(ret, "ACC_PRIVATE");
	}

	if (flags & 0x04) {
		strcat(ret, " ACC_PROTECTED");
	}

	if (flags & 0x08) {
		strcat(ret, " ACC_STATIC");
	}

	if (flags & 0x010) {
		strcat(ret, " ACC_FINAL");
	}

	if (flags & 0x020) {
		strcat(ret, " ACC_SYNCHRONIZED");
	}

	if (flags & 0x0100) {
		strcat(ret, " ACC_NATIVE");
	}

	if (flags & 0x0400) {
		strcat(ret, " ACC_ABSTRACT");
	}

	if (flags & 0x0800) {
		strcat(ret, " ACC_STRICT");
	}

	strcat(ret, "\n");

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
