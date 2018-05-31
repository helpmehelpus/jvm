#ifndef METHOD
#define METHOD

#include "basetypes.h"
#include "constantpool.h"
#include "attributes.h"



char* get_method_flag (uint16_t flags);
Method_info read_method (FILE* fp,Cp_info *cp);
Method_info * read_methods (FILE* fp, int length, Cp_info *cp);


void display_method (Method_info f, Cp_info *cp);
void display_method_index (Method_info f, Cp_info *cp, int index);
void display_methods (Method_info *f, Cp_info *cp, int methods_length);

#endif 