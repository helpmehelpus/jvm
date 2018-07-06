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

/*! \class Attribute_info
 *  \brief Classe que contém informações dos atributos da JVM
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
    * Lê os atributos de uma classe.
    * @param fp Ponteiro para o arquivo (.Class).
    * @param cp_vector Vetor para armazenamento de dados do \e Constant \e Pool.
    * @return Retorna um vetor de atributos.
    */
    static vector<Attribute_info> read_attributes(FILE* fp, vector<Cp_info> cp_vector, int length);
    /**
     * Lê um atributo específico de uma classe.
     * @see Read_attributes()
     * @param fp Ponteiro Para o arquivo (.Class)
     * @param cp_vector Vetor que contém dados do \e Constant \e Pool.
     * @return Retorna o atributo lido.
    */
    static Attribute_info read_attribute(FILE* fp, vector<Cp_info> cp_vector);
    /**
     * Descrição
     * @param fp Ponteiro para o arquivo (.Class).
     * @param cp_vector Vetor que contém dados do \e Constant \e Pool.
     * @param index Índice do atributo
     * @param length Tamanho do atributo
     * @return Retorna o atributo lido.
    */
    static T_info read_attribute_info(FILE* fp, vector<Cp_info> cp_vector, U2 index, U2 length);
    /**
     * Lê um tratador de exceções.
     * @param fp Ponteiro para o arquivo (.Class)
     * @return 
    */
    static T_exception_table read_exception_handler(FILE* fp);
    /**
     * Verifica o mnemônico de uma função dado um opcode.
     * @param Opcode Opcode da função
     * @return Retorna o mnemônico a partir do opcode.
    */
    static string get_mnemonic(int opcode);
    /**
     * Calcula o valor correspondente dado um número de \e bytes.
     * @param n Número de \e bytes.
     * @param code Referência para os \e bytes do código.
     * @param index Referência para o endereço do parâmetro do \e opcode.
     * @return Retorna o valor correspondente ao número de \e bytes dado.
    */
    U4 get_n_bytes_value(uint8_t n, vector<unsigned char> code, int* index);
    /** 
     * Provê os parâmetros de um \e opcode.
     * @param code Ponteiro para código e parâmetros.
     * @param index Índice para referência do parâmetro.
     * @return Retorna o valor correspondente.
    */
    void get_opcode_params(vector<unsigned char> code, int* index);
};

#endif