#include "interfaces.h"
#include <stdlib.h>



U2* read_interfaces (FILE* fp, int length) {
	U2 *interfaces = (U2 *)malloc(sizeof(U2) * length);

	for (int i = 0; i < length; i++) {
		interfaces[i] = reader_read_u2(fp);
	}

	return interfaces;
}
