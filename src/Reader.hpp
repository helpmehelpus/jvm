#ifndef READER
#define READER

#include <iostream>
#include <vector>
#include <stdbool.h>

#include "Attribute_info.hpp"
#include "Base_types.hpp"
#include "Constant_pool.hpp"
#include "Cp_info.hpp"
#include "Field_info.hpp"
#include "Interface.hpp"
#include "Method_area.hpp"
#include "Method_info.hpp"
#include "Static_class.hpp"

using namespace std;

/*! \brief Classe responsável por fazer a leitura do .class
 *
 * 
 */
class Reader{
  public:
    Constant_pool* cp;

    string file_name;

    vector<U2> interfaces;
    vector<Field_info> fields;
    vector<Method_info> methods;
    vector<Attribute_info> attributes;
    int main_index;
    int clinit_index;

    bool has_been_loaded;

    FILE *fp;

    U2 min_version;
    U2 max_version;
    U2 cp_length;
    U2 access_flags;
    U2 this_class;
    U2 super_class;
    U2 interfaces_count;
    U2 fields_count;
    U2 methods_count;
    U2 attributes_count;
    U4 magic_number;

    /*!
    * Começa a leitura do arquivo .class
    * @param file_name nome do arquivo .class
    * @return retorna 0
    */
    int run(char *file_name);
    
    /*!
    * Faz a leitura das classes, flags, versão etc do arquivo
    * @param file_name nome do arquivo .class
    * @return retorna 0
    */
    int read(char *file_name);
    
    /*!
    * Faz a leitura de 32 bits do arquivo
    * @param fp ponteiro para o arquivo .class
    * @return retorna o elemento lido
    */
    static U4 read_U4(FILE *fp);
    
    /*!
    * Checa o \e magic number do arquivo .class
    * @param number valor a ser checado
    * @return retorna se o número é igual ao \e magic number
    */
    int check_magic_number(U4 number);
    
    /*!
    * Faz a leitura de 16 bits do arquivo
    * @param fp ponteiro para o arquivo .class
    * @return retorna o elemento lido
    */
    static U2 read_U2(FILE *fp);
    
    /*!
    * Faz a leitura de 8 bits do arquivo
    * @param fp ponteiro para o arquivo .class
    * @return retorna o elemento lido
    */
    static U1 read_U1(FILE *fp);
    
    /*!
    * Faz uma sequência de leitura de 8 bits em codificação UTF8
    * @param fp ponteiro para o arquivo .
    * @param size tamanho do vetor a ser lido
    * @return retorna o vetor de elementos lidos
    */
    static vector<U1> read_UTF8(FILE *fp, int size);
    
    /*!
    * Extrai o nome do arquivo, removendo o caminho e deixando só o nome do arquivo
    * @param input_path caminho para o arquivo 
    * @return retorna o nome do arquivo
    */
    static string extract_file_name(string&);
    
    int show();

    /*!
    * Verifica se o .class existe um método \e main
    * @return retorna um booleano se o .class existe \e main
    */
    bool has_main();
    
    /*!
    * Verifica se o .class existe um método construtor
    * @return retorna um booleano se o .class existe um construtor
    */
    bool has_clinit();
    
    // string get_path();

    /*!
    * Pega o método main do arquivo .class
    * @return retorna o método main
    */
    Method_info get_main();
    
    /*!
    * Pega o método construtor da classe
    * @return retorna o método construtor
    */
    Method_info get_clinit();

    /*!
    * Pega um método específico
    * @param name nome do método
    * @param descriptor descritor do método
    * @return retorna o método
    */
    Method_info get_method(string name, string descriptor);

    /*!
    * Pega um método específico de uma classe
    * @param name nome do método
    * @param descriptor descritor do método
    * @return retorna a referência do método da classe
    */
    Reader* get_searched_method_class(string name, string descriptor);
    
};
#endif