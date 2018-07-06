#ifndef ARRAY
#define ARRAY

#define T_BOOLEAN 4
#define T_CHAR 5
#define T_FLOAT 6
#define T_DOUBLE 7
#define T_BYTE 8
#define T_SHORT 9
#define T_INT 10
#define T_LONG 11


/** \brief Struct que contém estrutura de um array
 */
struct Array {
  /*@{*/
  int* dimensions; /**< ponteiro de inteiro que contém as dimensões do array */
  int* array; /**< ponteiro de inteiro que armazena os dados do array */
  /*@}*/
};

#endif
