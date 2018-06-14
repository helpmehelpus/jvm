#ifndef TYPED_ELEMENT
#define TYPED_ELEMENT

#include <stdint.h>

#include "Element.hpp"

typedef struct {
	Element value;
	uint8_t type;
	uint8_t realType;
} Typed_element;

#endif