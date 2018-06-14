#include "Frame_stack.hpp"
#include "Operations.hpp"
#include "Method_area.hpp"

Frame_stack::Frame_stack(Reader *reader) {
	
    Frame frame;
	
	frame.method_info = reader->get_main();
	frame.cp_vector = reader->cp->cp_vector;
	frame.operand_stack = new Operand_stack(frame.method_info.attributes[0].info.code.max_stack);
	frame.local_variables = new Local_variable(frame.method_info.attributes[0].info.code.max_stack);
	set_start_PC(frame);

	threads.push(frame);
	//atualiza os ponteiros da pilha de operandos e vetor de variaveis
	//locais utilizados nas operacoes para o metodo corrente
	Operations::set_frame(threads.top());
	Operations::set_threads(threads);
	Operations::set_frame_stack(this);

	//inclui uma referencia para a pilha de frames na area de metodos
	//para ser possivel a inclusao do <clinit> quando necessario
	Method_area::set_frame_stack(this);

	//seta o nop como instrucao padrao
	opcode = 0;
}

void Frame_stack::execute() {
	while (next_instruction()) {
		//chama a funcao do vetor de funcoes
		//cout << "Opcode: " << opcode << "\tMnemonico: " << getMnemonic(opcode) << flush << endl;
		Operations::run(opcode);
		//threads.top()->operandos->printALL();
		//getchar();
	}
}

void Frame_stack::set_start_PC(Frame frame) {
    frame.pc = frame.method_info.attributes[0].info.code.code;
    current_PC = 0;
}

// TODO: check whether this works
bool Frame_stack::next_instruction() {
	//checa se a pilha esta vazia
	if (threads.empty()) {
		return false;
	}
	//checa se nao esgotamos as operacoes do metodo corrente
	if (current_PC < threads.top().method_info.attributes[0].info.code.code.size()) {
		//pega o proximo opcode a ser executado
		opcode = threads.top().pc[current_PC];
		//anda com pc em uma instrucao
		//caso existam argumentos, a funcao chamada os utilizara
		//e anda com pc as posicoes correspondentes
		current_PC++;
		return true;
	}

	//retira do topo caso nao tenham mais instrucoes no metodo corrente
	this->pop();

	//checa se apos o pop ainda restam elementos
	if (threads.empty()) {
		return false;
	}

	return true;
}

void Frame_stack::pop() {
	if (!threads.empty()) {
		delete threads.top()->operandos;
		delete threads.top()->locals;
		threads.pop();
	}
	if (threads.empty()) {
		Operations::setFrame(nullptr);
		Operations::setThreads(nullptr);
		exit(0);
	}
	Operations::setFrame(threads.top());
	Operations::setThreads(&threads);
}

void Frame_stack::startPC(frame *f) {
	//colocar o PC na posicao inicial do metodo no topo
	f->pc = f->m.attributes->info->code.code;
}

void Frame_stack::addFrame(method_info m, cp_info *cp) {
	frame *aux = (frame*) malloc(sizeof(frame));

	aux->m = m;
	aux->cp = cp;
	aux->operandos = new PilhaOperandos(aux->m.attributes->info->code.max_stack);
	aux->locals = new LocalVariables(aux->m.attributes->info->code.max_locals);
	startPC(aux);
	
	//atualiza os ponteiros da pilha de operandos e vetor de variaveis
	//locais utilizados nas operacoes para o metodo corrente
	Operations::setFrame(aux);
	Operations::setThreads(&threads);
	Operations::setFrameStack(this);

	//inclui uma referencia para a pilha de frames na area de metodos
	//para ser possivel a inclusao do <clinit> quando necessario
	MethodArea::setFrameStack(this);
	threads.push(aux);
}

void Frame_stack::addFrame(method_info *m, cp_info *cp) {
	this->addFrame(*m, cp);
}

void Frame_stack::setArguments(std::vector<typedElement> param) {
	for (int i = 0, j=0; i < param.size(); i++, j++) {
		threads.top()->locals->set(j, param[i]);
		
		//testa se o i-esimo argumento ocupou dois slots
		if (threads.top()->locals->get(j).type == TYPE_LONG || threads.top()->locals->get(j).type == TYPE_DOUBLE || (threads.top()->locals->get(j).type == TYPE_REFERENCE && BITS)) {
			j++;
		}
	}
}
