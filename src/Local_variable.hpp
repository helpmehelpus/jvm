#ifndef LOCAL_VARIABLE
#define LOCAL_VARIABLE

#include <vector>

#include "Base_types.hpp"
#include "Element.hpp"
#include "Typed_element.hpp"
#include "Operand_stack.hpp"

using namespace std;


/*! \brief Classe responsável por armazenar informações das variáveis locais
 *
 * 
 */
class Local_variable {
    public:
        vector<Element> elements;
        vector<U1> types;
        // const U2 max;
        // const U2 real_max;
        // const bool two_slots;

    /*! Construtor da classe
    * @param size tamanho para instanciar do tamanho correto
    */
    Local_variable(U2);
    /*! Construtor da classe
    * 
    */
    Local_variable();

    // Local_variable(U2);
    // Local_variable(U2, bool);
    // ~Local_variable();
    
    void display_all() const;

    /*!
    * Inserir um elemento no vetor de Elementos
    * @param typed_element tipo do elemento
    * @param index indíce do vetor
    */
    void insert_typed_element(Typed_element, int);
    void debug_local_variables() const;
    
    /*!
    * Pegar um elemento do vetor de elementos
    * @param index indíce do vetor que o elemento se encontra
    * @return retorna o elemento a partir do indice enviado
    */
    Typed_element get_typed_element(int) const;
    
};


#endif