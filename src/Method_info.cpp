#include "Method_info.hpp"
#include "Reader.hpp"

Method_info read_method (FILE* fp,Cp_info *cp) {
	Method_info aux;

	aux.access_flags = Reader::read_U2(fp) & 0xFFF;
	aux.name_index = Reader::read_U2(fp);
	aux.descriptor_index = Reader::read_U2(fp);
	aux.attributes_count = Reader::read_U2(fp);
	aux.attributes = (Attribute_info *) malloc(sizeof(Attribute_info) * aux.attributes_count);
	for (int i = 0; i < aux.attributes_count; i++) {
		aux.attributes[i] = read_attribute(fp,cp);
	}

	return aux;
}

Method_info *read_methods (FILE* fp, int length, Cp_info *cp) {
	Method_info *ret = (Method_info *) malloc(sizeof(Method_info) * length);

	for (int i = 0; i < length; i++) {
		ret[i] = read_method(fp,cp);
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


void display_method_index(Method_info f, Cp_info *cp, int index) {
	printf("\tMethod %d : " ,index);
    printf("\n");

	printf("\tFlags: %s ",  get_method_flag(f.access_flags));
	
	printf("\t\tName:  %s ", display_dereference_index(cp, f.name_index));
    printf("\n");

	printf("\t\tDescription:  %s ", display_dereference_index(cp, f.descriptor_index));
    printf("\n");

	printf("\t\tAttributes Count:  %d ", (int) f.attributes_count);
    printf("\n");
	for (int i = 0; i < f.attributes_count; i++) {
		printf("\t Attribute %d: ", i);
        printf("\n");
		display_attribute(f.attributes[i], cp);
	}
}

void display_method (Method_info f, Cp_info *cp) {
	printf("\tFlags: %s \n" , get_method_flag(f.access_flags));
	printf("\tName: %s \n", display_dereference_index(cp, f.name_index));
    printf("\tDescription: %s \n", display_dereference_index(cp, f.descriptor_index));
    printf("\tAttributes Count: %d  \n", (int) f.attributes_count);
    
	for (int i = 0; i < f.attributes_count; i++) {
		printf("\t\tAttributes  %d : ", i);
        printf("\n");
		display_attribute(f.attributes[i], cp);
	}
}

void display_methods (Method_info *f, Cp_info *cp, int methods_length) {
  	printf("Methods Count : %d\n", methods_length);
    
	for (int i = 0; i < methods_length; i++) {
		display_method_index(f[i], cp, i);
	}
}
