#ifndef ATTRIBUTE_INFO
#define ATTRIBUTE_INFO

#include "Base_types.hpp"
#include "T_exception_table.hpp"
#include "Constant_value_attribute.hpp"
#include "Exception_attribute.hpp"
#include "T_info.hpp"
#include "Constant_pool.hpp"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Attribute_info;

/*! \brief Classe que contém informações dos atributos da JVM
 *         
 *
 *  Essa classe contém todos os dados dos atributos da JVM
 */
class Attribute_info {
public:
    U2 name_index;
    U4 length;
    T_info info;

    /*!
    * Descrição
    * @param fp Ponteiro para o arquivo (.Class).
    * @param cp_vector Vetor para armazenamento de dados do ConstantPool.
    * @return Retorna um vetor de atributos.
    */
    static vector<Attribute_info> read_attributes(FILE* fp, vector<Cp_info> cp_vector, int length);
    /**
     * Descrição
     * @see read_attributes()
     * @param fp Ponteiro para o arquivo (.Class)
     * @param cp_vector Vetor que contém dados do ConstantPool.
     * @return Retorna o atributo lido.
    */
    static Attribute_info read_attribute(FILE* fp, vector<Cp_info> cp_vector);
    /**
     * Descrição
     * @param fp Ponteiro para o arquivo (.Class).
     * @param cp_vector Vetor que contém dados do ConstantPool.
     * @param index Índice do atributo
     * @param length Tamanho do atributo
     * @return Retorna o atributo lido.
    */
    static T_info read_attribute_info(FILE* fp, vector<Cp_info> cp_vector, U2 index, U2 length);
    /**
     * Descrição
     * @param fp Ponteiro para o arquivo (.Class)
     * @return 
    */
    static T_exception_table read_exception_handler(FILE* fp);
    /**
     * Descrição
     * @param opcode Opcode da função
     * @return Retorna o mnemônico a partir do opcode.
    */
    static string get_mnemonic(int opcode);
    /**
     * Descrição
     * @param n 
     * @param code
     * @param index    
     * @return Retorna .
    */
    U4 get_n_bytes_value(uint8_t n, vector<unsigned char> code, int* index);
    /**
     * Descrição
     * @param n 
     * @param code 
     * @return Retorna .
    */
    void get_opcode_params(vector<unsigned char> code, int* index);
};

#endif