#ifndef ELEMENT
#define ELEMENT

#include<stdint.h>

typedef union {
	double d;
	float f;
	uint32_t i;
	int32_t is;
	uint64_t l;
	int64_t ls;
	uint16_t s;
	int16_t ss;
	uint8_t b;
	int8_t bs;
	int* pi;
} Element;

#endif