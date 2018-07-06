#ifndef TYPED_ELEMENT
#define TYPED_ELEMENT

#include <stdint.h>

#include "Element.hpp"

/** \brief Struct que armazena as informações do tipo da union \e Element
 */
typedef struct {
	/*@{*/
	Element value; 
	uint8_t type; /**< tipo do elemento */
	uint8_t real_type; /**< tipo real do elemento */
	/*@}*/
} Typed_element;

#endif