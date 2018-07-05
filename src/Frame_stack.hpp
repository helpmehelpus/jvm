#ifndef FRAME_STACK
#define FRAME_STACK

#include <stack>
#include <vector>

#include "Frame.hpp"
#include "Reader.hpp"
#include "Typed_element.hpp"
#include "Attribute_info.hpp"


using namespace std;

class Reader;

/*! \brief Classe responsável pela execução das instruções e dos frames da JVM
 *
 * 
 */
class Frame_stack {
public:
	Frame_stack(Reader*);

	int opcode;
	stack<Frame*>* threads;

	/*!
	* Executa as instruções da classe
	*/	
	void execute();

	/*!
	* Inicializa o pc
	* @param frame.
	*/
	void set_start_PC(Frame*);

	/*!
	* Verifica se tem próxima instrução a ser executada
	* @return booleano se existe uma próxima instrução a ser executada	
	*/
	bool next_instruction();
	
	/*!
	* Desempilha um frame
	*/
	void pop();

	/*!
	* Adiciona um novo frame 
	* @param method_info.
	* @param cp_vector.
	*/
	void add_frame(Method_info, vector<Cp_info>);
	
	/*!
	* Define os argumentos
	* @param param.
	*/
	void set_arguments(vector<Typed_element>);
};

#endif