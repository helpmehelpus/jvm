#include "Frame_stack.hpp"
#include "Method_area.hpp"
#include "Operations.hpp"

using namespace std;

Frame_stack::Frame_stack(Reader *reader) {
    Frame* frame = new Frame();

	
	frame->method_info = reader->get_main();
	frame->cp_vector = reader->cp->cp_vector;
	frame->operand_stack = new Operand_stack(frame->method_info.attributes[0].info.code.max_stack);
	frame->local_variables = new Local_variable();
	set_start_PC(frame);
	threads = new stack<Frame*>;
	threads->push(frame);
	
	Operations::set_frame(threads->top());
	Operations::set_threads(threads);
	Operations::set_frame_stack(this);

	
	Method_area::set_frame_stack(this);

	opcode = 0;
}

void Frame_stack::execute() {
	while (next_instruction()) {
		cout << "Opcode: " << opcode << "\tMnemonico: " << Attribute_info::get_mnemonic(opcode) << flush << endl;
		Operations::run(opcode);
		//threads.top()->operandos->printALL();
		//getchar();
	}
}

void Frame_stack::set_start_PC(Frame* frame) {
    frame->pc = frame->method_info.attributes[0].info.code.code;
    frame->current_pc_index = 0;
	
}

// // TODO: check whether this works
bool Frame_stack::next_instruction() {
	// checa se a pilha esta vazia
	if (threads->empty()){
		return false;
	}

		
	//checa se nao esgotamos as Operations do metodo corrente
	if (threads->top()->current_pc_index < threads->top()->method_info.attributes[0].info.code.code.size()) {
		//pega o proximo opcode a ser executado
		opcode = threads->top()->get_current_pc();
		//anda com pc em uma instrucao
		//caso existam argumentos, a funcao chamada os utilizara
		//e anda com pc as posicoes correspondentes
		threads->top()->current_pc_index++;
		return true;
	}

	//retira do topo caso nao tenham mais instrucoes no metodo corrente
	threads->pop();

	//checa se apos o pop ainda restam elementos
	if (threads->empty()) {
		return false;
	}

	return true;
}

// 	//retira do topo caso nao tenham mais instrucoes no metodo corrente
// 	this->pop();

// 	//checa se apos o pop ainda restam elementos
// 	if (threads.empty())
// 		return false;

// 	return true;
// }

// void Frame_stack::pop() {
// 	if (!threads.empty()) {
// 		delete threads.top()->operand_stack;
// 		delete threads.top()->local_variables;
// 		threads.pop();
// 	}
// 	if (threads.empty()) {
// 		exit(0);
// 	}
// 	Operations::set_frame(threads.top());
// 	Operations::set_threads(threads);
// }

void Frame_stack::add_frame(Method_info method_info, vector<Cp_info> cp_vector) {
	Frame* frame = new Frame();

	frame->method_info = method_info;
	frame->cp_vector = cp_vector;
	frame->operand_stack = new Operand_stack(frame->method_info.attributes[0].info.code.max_stack);
	frame->local_variables = new Local_variable();

	set_start_PC(frame);
	
	Operations::set_frame(frame);
	Operations::set_threads(threads);
	Operations::set_frame_stack(this);

	Method_area::set_frame_stack(this);
	threads->push(frame);
}

// void Frame_stack::set_arguments(vector<Typed_element> param) {
// 	for (int i = 0, j=0; i < param.size(); i++, j++) {
// 		threads.top().local_variables.insert_typed_element(param[i], j);
		
// 		//testa se o i-esimo argumento ocupou dois slots
// 		if (threads.top().local_variables.elements[j].type == TYPE_LONG || threads.top()->locals->get(j).type == TYPE_DOUBLE || (threads.top()->locals->get(j).type == TYPE_REFERENCE && BITS)) {
// 			j++;
// 		}
// 	}
// }
