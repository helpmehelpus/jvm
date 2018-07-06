#ifndef METHOD_AREA
#define METHOD_AREA

#include <algorithm>
#include <map>
#include <string>

#include "Base_types.hpp"
#include "Constant_pool.hpp"
#include "Frame_stack.hpp"
#include "Reader.hpp"
#include "Static_class.hpp"
#include "Displayer.hpp"


using namespace std;
class Reader;
class Static_class;
class Frame_stack;

/*! \brief Classe responsável por realizar as operações referentes ao \e Method Area da JVM
 *
 * 
 */
class Method_area {
public:

	static string path;
	static map<string, Static_class*> classes;
	static Frame_stack *frame_stack;
	/*!
    * Pegar uma classe da referência de classes estáticas
    * @param s string para comparar com a classe a ser retornada
	* @return retorna a classe
    */
	static Static_class *get_class(string);
    static bool add_class(string);
	/*!
    * Adicionar uma classe a variável classes
    * @param reader referencia a classe reader que contém as informações lidas
	* @return retorna se conseguiu adicionar a classe
    */
    static bool add_class(Reader*);
	/*!
    * Adicionar uma classe a variável classes
    * @param new_frame_stack novo frame a ser recebido na pilha de frame
    */
    static void set_frame_stack(Frame_stack*);
};

#endif