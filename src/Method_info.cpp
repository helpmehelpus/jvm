#include <vector>

#include "Attribute_info.hpp"
#include "Displayer.hpp"
#include "Method_info.hpp"
#include "Reader.hpp"

vector<Method_info> Method_info::read_methods(FILE* fp,  vector<Cp_info> cp_vector, int length) {
	vector<Method_info> ret;

	for (int i = 0; i < length; i++)
		ret.push_back(read_method(fp,cp_vector));
	
	return ret;
}

Method_info Method_info::read_method(FILE* fp, vector<Cp_info> cp_vector) {
	Method_info method;

	method.access_flags = Reader::read_U2(fp) & 0xFFF;
	method.name_index = Reader::read_U2(fp);
	method.descriptor_index = Reader::read_U2(fp);
	method.attributes_count = Reader::read_U2(fp);
	for(int i = 0; i < method.attributes_count; i++)
		method.attributes.push_back(Attribute_info::read_attribute(fp,cp_vector));

	return method;
}

string Method_info::get_method_flags(unsigned short flags) {
	string ret = "";

	if (flags & 0x01)
		ret += "ACC_PUBLIC ";

	if (flags & 0x02)
		ret += "ACC_PRIVATE ";

	if (flags & 0x04)
		ret +=  "ACC_PROTECTED ";

	if (flags & 0x08)
		ret +=  "ACC_STATIC ";

	if (flags & 0x010)
		ret +=  "ACC_FINAL ";

	if (flags & 0x020)
		ret +=  "ACC_SYNCHRONIZED ";

	if (flags & 0x0100)
		ret +=  "ACC_NATIVE ";

	if (flags & 0x0400)
		ret += "ACC_ABSTRACT ";

	if (flags & 0x0800)
		ret +=  "ACC_STRICT ";

	return ret;
}
