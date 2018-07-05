#ifndef DISPLAYER
#define DISPLAYER

#include<stdio.h>
#include<stdlib.h>
#include <string>

#include "Base_types.hpp"
#include "Constant_pool.hpp"
#include "Field_info.hpp"
#include "Method_info.hpp"

using namespace std;

const string name_types[] = {"-", "UTF-8", "-", "Integer", "Float", "Long", "Double", "Class", "String", "Field", "Method", "Interface", "Name/Type"};
const string flag_names[] = {"ACC_PUBLIC", "ACC_FINAL", "ACC_SUPER", "ACC_INTERFACE", "ACC_ABSTRACT"};
/*! \brief Classe responsável em imprimir informações da classe
 *
 *  Essa classe exibe de forma estruturada as informações alocadas de uma classe.
 */
class Displayer {
public:
 	/*!
    * Imprime a versão máxima e mínima da classe.
    * @param min_version.
    * @param max_version.
    */
    static void display_version(U2 min_version, U2 max_version);

    /*!
    * Imprime o \e Constant \e Pool.
    * @param *cp Ponteiro de referência para a constant pool.
    * @param cp_length tamanho da constant pool.
    */
	static void display_cp(Constant_pool *cp, U2 cp_length);
	
    /*!
    * Imprime \e string na codificação \e UTF8.
    * @param values.
    * @param size.
    */
	static string display_UTF8(vector<U1> values, U2 size);
	
    /*!
    * Imprime UTF8.
    * @param values 
    * @param size.
	* @return string utf8.
    */
	static string display_UTF8(unsigned char* values, U2 size);
	
	/*!
    * Converte U4 para float.
    * @param value.
	* @return float convertido.
    */
	static float u4_to_float(U4 value);
	
    /*!
    * Converte U4 para long.
    * @param high parte superior do long final.
	* @param low  parte inferior do long final.
	* @return long resultante.
    */
	static long u4_to_long(U4 high, U4 low);
	
    /*!
    * Converte U4 para double.
    * @param high parte superior do double final.
	* @param low  parte inferior do double final.
	* @return double resultante.
    */
	static double u4_to_double(U4 high, U4 low);
	
    /*!
    * Encontra o elemento a ser impresso no \e Constant \e Pool.
    * @param cp_vector referência pro \e Constant \e Pool.
	* @param index  indice do elemento do \e Constant \e Pool.
	* @return string elemento relacionado ao indice.
    */
	static string dereference_index(vector<Cp_info> cp_vector, U2 index);
	
    /*!
    * Imprime as flags de acesso da classe.
    * @param access_flags flags de acesso à classe.
	* 
    */
	static void display_access_flags(U2 access_flags);
	
    /*!
    * Imprime ao nome das classes(this e super);
    * @param this_class nome da classe 
    * @param super_class nome da classe super.
    * @param cp_vector referência para o \e Constant \e Pool.
    */
	static void display_class_names(U2 this_class, U2 super_class, vector<Cp_info> cp_vector);
	
    /*!
    * Imprime as interfaces.
    * @param interface vetor de interfaces
    * @param cp_vector referência para o \e Constant \e Pool.
    * @return Retorna um vetor de atributos.
    */
	static void display_interfaces(vector<U2> interfaces, vector<Cp_info> cp_vector);
	
    /*!
    * Imprime uma interface dado um índice.
    * @param interfaces referência para as interfaces.
    * @param cp_vector referência para o \e Constant \e Pool.
    * @param index índice da interface.
    */
	static void display_interface_by_index(U2 interfaces, vector<Cp_info> cp_vector, int);
	
    /*!
    * Imprime os campos.
    * @param fields vetor de campos.
    * @param cp_vector Vetor para armazenamento de dados do ConstantPool.
	* @param length tamanho dos campos.
    */
	static void display_fields(vector <Field_info>, vector<Cp_info>, int);
	
    /*!
    * Imprime os campos dado um índice.
    * @param fields referência para as campos.
    * @param cp_vector referência para o \e Constant \e Pool.
    * @param index índice da interface.
    */
	static void display_field_by_index(Field_info, vector<Cp_info>, int);
	
     /*!
    * Imprime os atributos.
    * @param attribute referência para os atributos.
    * @param cp_vector referência para o \e Constant \e Pool.
    */
	static void display_attribute(Attribute_info, vector<Cp_info>);
	
    /*!
	* Imprime os métodos.
    * @param methods vetor de métodos.
    * @param cp_vector referência para o \e Constant \e Pool.
    * @param length tamanho das interfaces.
    */
	static void display_methods(vector <Method_info>, vector<Cp_info> , int);
	
    /*!
    * Imprime um método dado um índice.
    * @param methods vetor de métodos.
    * @param cp_vector referência para o \e Constant \e Pool.
    * @param index índice do método.
    */
	static void display_method_by_index(Method_info , vector<Cp_info>, int);

};

#endif