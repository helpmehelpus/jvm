#ifndef BASETYPES
#define BASETYPES

#include<stdint.h>

typedef uint8_t U1;
typedef uint16_t U2;
typedef uint32_t U4;

/*! \def RT_BYTE
    \brief Definir o código de um elemento BYTE
*/
#define RT_BYTE 1

/*! \def RT_BOOL
    \brief Definir o código de um elemento BOOL
*/
#define RT_BOOL 2

/*! \def RT_CHAR
    \brief Definir o código de um elemento CHAR
*/
#define RT_CHAR 3

/*! \def RT_SHORT
    \brief Definir o código de um elemento SHORT
*/
#define RT_SHORT 4

/*! \def RT_INT
    \brief Definir o código de um elemento INT
*/
#define RT_INT 5

/*! \def RT_FLOAT
    \brief Definir o código de um elemento FLOAT
*/
#define RT_FLOAT 6

/*! \def RT_DOUBLE
    \brief Definir o código de um elemento DOUBLE
*/
#define RT_DOUBLE 7
/*! \def RT_REFERENCE
    \brief Definir o código de um elemento REFERENCE
*/
#define RT_REFERENCE 8

/*! \def RT_LONG
    \brief Definir o código de um elemento LONG
*/
#define RT_LONG 9

/*! \def Float_NaN
    \brief Definindo valor de "Not a Number" para float
*/
#define Float_NaN 0x7f800001

/*! \def Double_NaN
    \brief Definindo valor de "Not a Number" para double
*/
#define Double_NaN 0x7ff0000000000001L


#endif



