#include "fields.h"

void display_field(Field_info f, Cp_info *cp, int index) {
	printf("\tField %d : \n", index);
    	printf("\t\tFlags: %s \n", get_field_flags(f.accessFlags));
	printf("\t\tName: %s\n" , display_dereference_index(cp, f.name_index)) ;
    	printf("\t\tDescription: %s \n" , display_dereference_index(cp, f.descriptor_index)) ;
    	printf("\t\tAmount of Attributes: %d \n",(int) f.attributes_count) ;
    	for (int i = 0; i < f.attributes_count; i++) {
		printf("Attribute %d: ", i);
		display_attribute(f.attributes[i], cp);
	}
}

void display_fields (Field_info *f, Cp_info *cp, int length) {
	printf("Amount of fields : %d\n\n", length);

	for (int i = 0; i < length; i++) {
		display_field(f[i], cp, i);
	}
}

Field_info read_field (FILE* fp,Cp_info* cp) {
	Field_info fi;

	fi.accessFlags = reader_read_u2(fp) & 0X0df;
	fi.name_index = reader_read_u2(fp);
	fi.descriptor_index = reader_read_u2(fp);
	fi.attributes_count = reader_read_u2(fp);
	fi.attributes = (Attribute_info *) malloc(sizeof(Attribute_info) * fi.attributes_count);
	for (int i = 0; i < fi.attributes_count; i++) {
		fi.attributes[i] = read_attribute(fp,cp);
		
	}

	return fi;
}

char* get_field_flags (unsigned short flags) {
	char* fi = (char*)malloc(sizeof(char)*255);

	if (flags & 0x01) 
        	strcat(fi, "ACC_PUBLIC ");
	if (flags & 0x02)
        	strcat(fi, "ACC_PRIVATE ");
	if (flags & 0x04)
        	strcat(fi, "ACC_PROTECTED ");
	if (flags & 0x08)
        	strcat(fi, "ACC_STATIC ");
	if (flags & 0x010)
        	strcat(fi, "ACC_FINAL");
	if (flags & 0x040)
        	strcat(fi, "ACC_VOLATILE ");
	if (flags & 0x080)
        	strcat(fi, "ACC_TRANSIENT ");

	return fi;
}

Field_info *read_fields (FILE* fp, Cp_info* cp, int length) {
	Field_info *fi = (Field_info *) malloc(sizeof(Field_info) * length);

	for (int i = 0; i < length; i++) {
		fi[i] = read_field(fp,cp);
		
	}
	return fi;
}