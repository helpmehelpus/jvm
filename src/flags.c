#include "flags.h"
#include "basetypes.h"
#include "reader.h"
#include <stdlib.h>
#include <stdio.h>

U2 reader_read_flags(FILE* fp){

	U2 flags = reader_read_u2(fp);	
	
	return flags;
}

