#ifndef CONSTANTPOOL
#define CONSTANTPOOL

#include <stdio.h>
#include <vector>

#include "Cp_info.hpp"

/*! \def CLASS
    \brief Definindo o valor de CLASS para a \e Constant Pool.
*/
#define CLASS 7

/*! \def FIELDREF
    \brief Definindo o valor de FIELDREF para a \e Constant Pool.
*/
#define FIELDREF 9

/*! \def METHODREF
    \brief Definindo o valor de METHODREF para a \e Constant Pool.
*/
#define METHODREF 10

/*! \def INTERFACEMETHODREF
    \brief Definindo o valor de INTERFACEMETHODREF para a \e Constant Pool.
*/
#define INTERFACEMETHODREF 11

/*! \def STRING
    \brief Definindo o valor de STRING para a \e Constant Pool.
*/
#define STRING 8

/*! \def INTEGER
    \brief Definindo o valor de INTEGER para a \e Constant Pool.
*/
#define INTEGER 3

/*! \def FLOAT
    \brief Definindo o valor de FLOAT para a \e Constant Pool.
*/
#define FLOAT 4

/*! \def LONG
    \brief Definindo o valor de LONG para a \e Constant Pool.
*/
#define LONG 5

/*! \def DOUBLE
    \brief Definindo o valor de DOUBLE para a \e Constant Pool.
*/
#define DOUBLE 6

/*! \def NAMEANDTYPE
    \brief Definindo o valor de NAMEANDTYPE para a \e Constant Pool.
*/
#define NAMEANDTYPE 12

/*! \def UTF8
    \brief Definindo o valor de UTF8 para a \e Constant Pool.
*/
#define UTF8 1

/*! \def INVALID
    \brief Definindo o valor de INVALID para a \e Constant Pool.
*/
#define INVALID 99

using namespace std;

/*! \brief Classe responsável por armazenar as constantes definidas da classe.
 *        
 */
class Constant_pool{
	public:
        /**
         * Construtor da classe
         * @param cp_length Tamanho da constant pool
         * @param fp Ponteiro para o arquivo (.Class)
        */
		Constant_pool(int cp_length, FILE* fp);
        /**
         * Vetor de informações do Constant Pool
        */
		vector<Cp_info> cp_vector;
};

#endif