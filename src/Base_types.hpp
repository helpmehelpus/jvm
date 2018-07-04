#ifndef BASETYPES
#define BASETYPES

#include<stdint.h>

typedef uint8_t U1;
typedef uint16_t U2;
typedef uint32_t U4;

/*! \def RT_BYTE
    \brief A macro that returns the maximum of \a a and \a b.

*/
#define RT_BYTE 1
#define RT_BOOL 2
#define RT_CHAR 3
#define RT_SHORT 4
#define RT_INT 5
#define RT_FLOAT 6
#define RT_DOUBLE 7
#define RT_REFERENCE 8
#define RT_LONG 9

#define Float_NaN 0x7f800001
#define Double_NaN 0x7ff0000000000001L


#endif



