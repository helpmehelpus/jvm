#ifndef FIELDS
#define FIELDS

#include "basetypes.h"
#include "constantpool.h"
#include "attributes.h"
#include "displayer.h"



char* get_field_flags(unsigned short flags);
Field_info read_field(FILE* fp, Cp_info *cp);
Field_info * read_fields(FILE* fp, Cp_info *cp, int length);
void display_field(Field_info f, Cp_info *cp, int index);
void display_fields(Field_info *f, Cp_info *cp, int length);

#endif