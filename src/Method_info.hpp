#ifndef METHOD_INFO
#define METHOD_INFO

#include <vector>
#include <string>
#include <stdio.h>

#include "Attribute_info.hpp"
#include "Constant_pool.hpp"
#include "Cp_info.hpp"

using namespace std;

/*! \brief Classe responsável por estruturar cada inicialização de interface e classes
 *
 * 
 */
class Method_info {
public:
    unsigned char access_flags;
    unsigned char name_index;
    unsigned char descriptor_index;
    unsigned char attributes_count;
    vector <Attribute_info> attributes;

    /*!
    * Ler os métodos do .class
    * @param fp ponteiro para o arquivo .class
    * @param cp_vector Vetor para armazenamento de dados do ConstantPool.
    * @param lenght Número de métodos a serem lidos
	* @return retorna um vetor de métodos
    */
    static vector <Method_info> read_methods(FILE*, vector<Cp_info>, int);
    
    /*!
    * Ler um método específico
    * @param fp ponteiro para o arquivo .class
    * @param cp_vector Vetor para armazenamento de dados do ConstantPool.
	* @return retorna o método
    */
    static Method_info read_method(FILE*, vector<Cp_info>);

    /*!
    * Pega as flags de um método
    * @param flags flag a ser análisada para retornar o tipo do método
	* @return retorna uma string com as flags
    */
    static string get_method_flags(unsigned short flags);
};

#endif