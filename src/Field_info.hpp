#ifndef FIELD_INFO
#define FIELD_INFO

#include <stdio.h>
#include <string>
#include <vector>

#include "Attribute_info.hpp"
#include "Constant_pool.hpp"
#include "Cp_info.hpp"

using namespace std;
/*! \class Field_info
 *  \brief Classe responsável por armazenar os campos definidos da classe.
 *        
 */
class Field_info {
    public:
        
        unsigned char access_flags;
        unsigned char name_index;
        unsigned char descriptor_index;
        unsigned char attributes_count;
        vector <Attribute_info> attributes;

        /*!
        * Lê os \e fields do arquivo .class.
        * @param fp ponteiro para o arquivo .class.
        * @param cp_vector referência para o \e Constant \e Pool.
        * @param length tamanho dos \e fields.
        * @return retorna um vetor de \e fields.
        */
        static vector <Field_info> read_fields(FILE*, vector<Cp_info>, int);

        /*!
        * Lê um \e field.
        * @param cp_vector referência para o \e Constant \e Pool. 
        * @retorna uma referẽncia para um \e field. 
        */
        static Field_info read_field(FILE*, vector<Cp_info>);
        
        /*!
        * Retorna as flags de um ze field.
        * @param flags flags de acesso do campo.
        * @return retorna uma \e string com as flags do \e field.
        */
        static string get_field_flags(unsigned short flags);
};

#endif