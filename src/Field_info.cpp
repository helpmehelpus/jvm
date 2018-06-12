#include "Field_info.hpp"
#include "Reader.hpp"
#include <vector>

vector<Field_info> Field_info::read_fields(FILE* fp, vector<Cp_info> cp_vector, int length) {
	vector<Field_info> resp;

	for (int i = 0; i < length; i++) {
		resp.push_back(read_field(fp,cp_vector));	
	}
	return resp;
}

Field_info Field_info::read_field(FILE* fp, vector<Cp_info> cp_vector){
	Field_info field;
	Reader reader;

	field.access_flags = Reader::read_U2(fp) & 0X0df;
	field.name_index = Reader::read_U2(fp);
	field.descriptor_index = Reader::read_U2(fp);
	field.attributes_count = Reader::read_U2(fp);

	for(int i = 0; i < field.attributes_count; i++)
		field.attributes.push_back(Attribute_info::read_attribute(fp,cp_vector));

	return field;
}

string Field_info::get_field_flags(unsigned short flags) {
	string fi = "";

	if (flags & 0x01) 
        	fi += "ACC_PUBLIC ";
	if (flags & 0x02)
        	fi += "ACC_PRIVATE ";
	if (flags & 0x04)
        	fi += "ACC_PROTECTED ";
	if (flags & 0x08)
        	fi += "ACC_STATIC ";
	if (flags & 0x010)
        	fi += "ACC_FINAL";
	if (flags & 0x040)
        	fi += "ACC_VOLATILE ";
	if (flags & 0x080)
        	fi += "ACC_TRANSIENT ";

	return fi;
}

