#include "Operations.hpp"

using namespace std;

Frame* Operations::frame = new Frame();
stack<Frame*>* Operations::threads = nullptr;
Frame_stack* Operations::frame_stack = nullptr;
// bool Operations::is_wide = false;

const func Operations::functions[] = { &Operations::nop, &Operations::aconst_null, &Operations::iconst_m1,
    &Operations::iconst_0, &Operations::iconst_1, &Operations::iconst_2, &Operations::iconst_3, &Operations::iconst_4,
    &Operations::iconst_5, &Operations::lconst_0, &Operations::lconst_1, &Operations::fconst_0, &Operations::fconst_1,
    &Operations::fconst_2, &Operations::dconst_0, &Operations::dconst_1, &Operations::bipush, &Operations::sipush,
    &Operations::ldc, &Operations::ldc_w, &Operations::ldc2_w, &Operations::iload, &Operations::lload, &Operations::fload,
    &Operations::dload, &Operations::aload, &Operations::iload_0, &Operations::iload_1, &Operations::iload_2,
    &Operations::iload_3, &Operations::lload_0, &Operations::lload_1, &Operations::lload_2, &Operations::lload_3,
    &Operations::fload_0, &Operations::fload_1, &Operations::fload_2, &Operations::fload_3, &Operations::dload_0,
    &Operations::dload_1, &Operations::dload_2, &Operations::dload_3, &Operations::aload_0, &Operations::aload_1,
    &Operations::aload_2, &Operations::aload_3, &Operations::iaload, &Operations::laload, &Operations::faload,
    &Operations::daload, &Operations::aaload, &Operations::baload, &Operations::caload, &Operations::saload,
    &Operations::istore, &Operations::lstore, &Operations::fstore, &Operations::dstore, &Operations::astore,
    &Operations::istore_0, &Operations::istore_1, &Operations::istore_2, &Operations::istore_3, &Operations::lstore_0,
    &Operations::lstore_1, &Operations::lstore_2, &Operations::lstore_3, &Operations::fstore_0, &Operations::fstore_1,
    &Operations::fstore_2, &Operations::fstore_3, &Operations::dstore_0, &Operations::dstore_1, &Operations::dstore_2,
    &Operations::dstore_3, &Operations::astore_0, &Operations::astore_1, &Operations::astore_2, &Operations::astore_3,
    &Operations::iastore, &Operations::lastore, &Operations::fastore, &Operations::dastore, &Operations::aastore,
    &Operations::bastore, &Operations::castore, &Operations::sastore, &Operations::pop, &Operations::pop2, &Operations::dup,
    &Operations::dup_x1, &Operations::dup_x2, &Operations::dup2, &Operations::dup2_x1, &Operations::dup2_x2, &Operations::swap, &Operations::iadd,
    &Operations::ladd, &Operations::fadd, &Operations::dadd, &Operations::isub, &Operations::lsub, &Operations::fsub,
    &Operations::dsub, &Operations::imul, &Operations::lmul, &Operations::fmul, &Operations::dmul, &Operations::idiv,
    &Operations::ldiv, &Operations::fdiv, &Operations::ddiv, &Operations::irem, &Operations::lrem, &Operations::frem,
    &Operations::drem, &Operations::ineg, &Operations::lneg, &Operations::fneg, &Operations::dneg, &Operations::ishl,
    &Operations::lshl, &Operations::ishr, &Operations::lshr, &Operations::iushr, &Operations::lushr, &Operations::iand,
    &Operations::land, &Operations::ior, &Operations::lor, &Operations::ixor, &Operations::lxor, &Operations::iinc,
    &Operations::i2l, &Operations::i2f, &Operations::i2d, &Operations::l2i, &Operations::l2f, &Operations::l2d, &Operations::f2i,
    &Operations::f2l, &Operations::f2d, &Operations::d2i, &Operations::d2l, &Operations::d2f, &Operations::i2b, &Operations::i2c,
    &Operations::i2s, &Operations::lcmp, &Operations::fcmpl, &Operations::fcmpg, &Operations::dcmpl, &Operations::dcmpg,
    &Operations::ifeq, &Operations::ifne, &Operations::iflt, &Operations::ifge, &Operations::ifgt, &Operations::ifle,
    &Operations::if_icmpeq, &Operations::if_icmpne, &Operations::if_icmplt, &Operations::if_icmpge, &Operations::if_icmpgt,
    &Operations::if_icmple, &Operations::if_acmpeq, &Operations::if_acmpne, &Operations::funcgoto, &Operations::jsr,
    &Operations::funcret, &Operations::tableswitch, &Operations::lookupswitch, &Operations::ireturn, &Operations::lreturn,
    &Operations::freturn, &Operations::dreturn, &Operations::areturn, &Operations::func_return, &Operations::getstatic,
    &Operations::putstatic, &Operations::getfield, &Operations::putfield, &Operations::invokevirtual, &Operations::invokespecial,
    &Operations::invokestatic, &Operations::invokeinterface, &Operations::nop, &Operations::func_new, &Operations::newarray,
    &Operations::anewarray, &Operations::arraylength, &Operations::athrow, &Operations::nop, &Operations::nop, &Operations::nop,
    &Operations::nop, &Operations::wide, &Operations::multianewarray, &Operations::ifnull, &Operations::ifnonnull,
    &Operations::goto_w, &Operations::jsr_w };

// Operations::Operations(Frame* ref) {
// 	frame = ref;
// }

// U4 Operations::get_n_bytes_value(uint8_t n, vector<U2> pc)
// {
//   U4 value;

//   for(int i = 0; i < n; i++)
//     value = (value << 8) | pc[i];

//   return value;
// }

void Operations::set_frame(Frame* new_frame) {
	frame = new_frame;
}

void Operations::set_threads(stack<Frame*>* t) {
	threads = t;
}

void Operations::set_frame_stack(Frame_stack* new_frame_stack) {
	frame_stack = new_frame_stack;
}

void Operations::run(int opcode) {
	functions[opcode] ();
}

// //Not OPeration, nao faz nada
// void Operations::nop () {
// }

// //empilha nos operandos uma referencia nula, neste caso representada por um 0
// void Operations::aconst_null () {
// 	frame->operand_stack->push_type((int*)(nullptr));
// }

// //empilha o int -1
// void Operations::iconst_m1 () {
// 	frame->operand_stack->push_type(int(-1));
// }

// //empilha o int 0
// void Operations::iconst_0 () {
// 	frame->operand_stack->push_type(int(0));
// }

// //empilha o int 1
// void Operations::iconst_1 () {
// 	frame->operand_stack->push_type(int(1));
// }

// //empilha o int 2
// void Operations::iconst_2 () {
// 	frame->operand_stack->push_type(int(2));
// }

// //empilha o int 3
// void Operations::iconst_3 () {
// 	frame->operand_stack->push_type(int(3));
// }

// //empilha o int 4
// void Operations::iconst_4 () {
// 	frame->operand_stack->push_type(int(4));
// }

// //empilha o int 5
// void Operations::iconst_5 () {
// 	frame->operand_stack->push_type(int(5));
// }

// //empilha o long 0
// void Operations::lconst_0 () {
// 	frame->operand_stack->push_type(long(0));
// }

// //empilha o long 1
// void Operations::lconst_1 () {
// 	frame->operand_stack->push_type(long(1));
// }

// //empilha o float 0.0
// void Operations::fconst_0 () {
// 	frame->operand_stack->push_type(float(0.0));
// }

// //empilha o float 1.0
// void Operations::fconst_1 () {
// 	frame->operand_stack->push_type(float(1.0));
// }

// //empilha o float 2.0
// void Operations::fconst_2 () {
// 	frame->operand_stack->push_type(float(2.0));
// }

// //empilha o double 0.0
// void Operations::dconst_0 () {
// 	frame->operand_stack->push_type(double(0.0));
// }

// //empilha o double 1.0
// void Operations::dconst_1 () {
// 	frame->operand_stack->push_type(double(1.0));
// }

// //Fim linha 0
// //Inicio linha 1

// //empilha um byte com sinal extendido
// void Operations::bipush () {
// 	// int32_t aux;
// 	// int8_t byte = get_n_bytes_value(1, frame->pc);
// 	// aux = (int32_t) (int8_t) byte; // extendendo o sinal
// 	// frame->operand_stack->push_type(int(aux));
// }

// // funcao que insere dois bytes na pilha de operandos
// void Operations::sipush () {
// 	// uint16_t valShort;
// 	// int32_t valPushShort;
// 	// valShort = get_n_bytes_value(2, frame->pc);
// 	// valPushShort = (int32_t) (int16_t) valShort;  // extendendo o sinal
// 	// frame->operand_stack->push_type(int(valPushShort));
// }

// //empilha um valor do constant Pool
// void Operations::ldc () {
// 	// uint8_t index = get_n_bytes_value(1, frame->pc);
// 	// Cp_info cp_vector= frame->cp_vector[index];
// 	// if (cp_vector.tag == STRING){						// se o Elemento for string
// 	// 	frame->operand_stack->push_type((int*)(frame->cp_vector[cp_vector.info[0].u2].info[1].array));
// 	// } else {									   // se o Elemento for int ou float
// 	// 	Element aux;
// 	// 	aux.i = cp_vector.info[0].u4;
// 	// 	if (cp_vector.tag == INTEGER){
// 	// 		frame->operand_stack->push_type(aux, TYPE_INT);
// 	// 	} else {
// 	// 		frame->operand_stack->push_type(aux, TYPE_FLOAT);
// 	// 	}
// 	// }
// }

// //empilha um valor do constant Pool (ldc wide)
// void Operations::ldc_w () {
// 	// uint16_t index = get_n_bytes_value(2, frame->pc);
// 	// Cp_info cp_vector= frame->cp_vector[index];
// 	// if (cp_vector.tag == STRING){					// se o Elemento for string
// 	// 	frame->operand_stack->push_type((int*)(frame->cp_vector[cp_vector.info[0].u2].info[1].array));
// 	// } else									// se o Elemento for int ou float
// 	// 	frame->operand_stack->push_type(int(cp_vector.info[0].u4));
// }

// //empilha valores long e double do Constant Pool
// void Operations::ldc2_w () {
// 	// uint8_t index = get_n_bytes_value(2, frame->pc);
// 	// long valPushLong;
// 	// double valPushDouble;
// 	// if (frame->cp_vector[index].tag == LONG){
// 	// 	valPushLong = u4_to_long(frame->cp_vector[index].info[0], frame->cp_vector[index+1].info[0]);
// 	// 	frame->operand_stack->push_type(long(valPushLong));
// 	// } else {
// 	// 	valPushDouble = u4_to_double(frame->cp_vector[index].info[0], frame->cp_vector[index+1].info[0]);
// 	// 	frame->operand_stack->push_type(double(valPushDouble));
// 	// }
// }

// //le um inteiro do vetor de variaveis locais e empilha
// //pode ser utilizada em conjunto com wide
// void Operations::iload () {
// 	// uint16_t index = 0;

// 	// if (is_wide){
// 	// 	index = get_n_bytes_value(2, frame->pc);
// 	// 	is_wide = false;
// 	// } else {
// 	// 	index = get_n_bytes_value(1, frame->pc);
// 	// }

// 	// Typed_element aux = frame->local_variables->get_typed_element(int(index));
// 	// frame->operand_stack->push_type(int(aux.value.i));
// }

// //le um long do vetor de variaveis locais e empilha
// //pode ser utilizada em conjunto com wide
// void Operations::lload () {
// 	// uint16_t index = 0;
// 	// if (is_wide) {
// 	// 	index = get_n_bytes_value(2, frame->pc);
// 	// 	is_wide = false;
// 	// }else
// 	// 	index = get_n_bytes_value(1, frame->pc);

// 	// Typed_element aux = frame->local_variables->get_typed_element(int(index));
// 	// frame->operand_stack->push_type(long(aux.value.l));
// }

// //le um float do vetor de variaveis locais e empilha
// //pode ser utilizada em conjunto com wide
// void Operations::fload () {
// 	// uint16_t index = 0;

// 	// if (is_wide) {
// 	// 	index = get_n_bytes_value(2, frame->pc);
// 	// 	is_wide = false;
// 	// }else
// 	// 	index = get_n_bytes_value(1, frame->pc);

// 	// Typed_element aux = frame->local_variables->get_typed_element(int(index));
// 	// frame->operand_stack->push_type(float(aux.value.f));
// }

// //le um double do vetor de variaveis locais e empilha
// void Operations::dload () {
// 	// uint16_t index;

// 	// if (is_wide) {
// 	// 	index = get_n_bytes_value(2, frame->pc);
// 	// 	is_wide = false;
// 	// } else
// 	// 	index = get_n_bytes_value(1, frame->pc);

// 	// Typed_element aux = frame->local_variables->get_typed_element(int(index));
// 	// frame->operand_stack->push_type(double(aux.value.d));
// }

// //le uma referencia do vetor de variaveis locais e empilha
// //pode ser utilizada em conjunto com wide
// void Operations::aload () {
// 	// uint16_t index = 0;

// 	// if (is_wide) {
// 	// 	index = get_n_bytes_value(2, frame->pc);
// 	// 	is_wide = false;
// 	// }else
// 	// 	index = get_n_bytes_value(1, frame->pc);

// 	// Typed_element aux = frame->local_variables->get_typed_element(int(index));
// 	// frame->operand_stack->push_type((int*)(aux.value.pi));
// }

// // le um inteiro do vetor de variaveis locais, posicao 0, e empilha
// void Operations::iload_0 () {
// 	Typed_element aux = frame->local_variables->get_typed_element(0);
// 	frame->operand_stack->push_type(int(aux.value.i));
// }

// //le um inteiro do vetor de variaveis locais, posicao 1, e empilha
// void Operations::iload_1 () {
// 	Typed_element aux = frame->local_variables->get_typed_element(1);
// 	frame->operand_stack->push_type(int(aux.value.i));
// }

// //le um inteiro do vetor de variaveis locais, posicao 2, e empilha
// void Operations::iload_2 () {
// 	Typed_element aux = frame->local_variables->get_typed_element(2);
// 	frame->operand_stack->push_type(int(aux.value.i));
// }

// //le um inteiro do vetor de variaveis locais, posicao 3, e empilha
// void Operations::iload_3 () {
// 	Typed_element aux = frame->local_variables->get_typed_element(3);
// 	frame->operand_stack->push_type(int(aux.value.i));
// }

// //le um long do vetor de variaveis locais, posicao 0, e empilha
// void Operations::lload_0 () {
// 	lload_n(0);
// }

// //le um long do vetor de variaveis locais, posicao 1, e empilha
// void Operations::lload_1 () {
// 	lload_n(1);
// }

// //Fim linha 1
// //Inicio linha 2

// // LLOAD_<N>
// void Operations::lload_n(short index)
// {
// 	Typed_element aux = frame->local_variables->get_typed_element(index);
// 	frame->operand_stack->push_type(long(aux.value.l));
// }

// void Operations::lload_2(){
// 	lload_n(2);
// }

// void Operations::lload_3(){
//  	lload_n(3);
// }

// // FLOAD_<N>
// void Operations::fload_n(short index)
// {
// 	Typed_element aux = frame->local_variables->get_typed_element(index);
// 	frame->operand_stack->push_type(aux.value.f);
// }

// void Operations::fload_0(){
// 	fload_n(0);
// }

// void Operations::fload_1(){
// 	fload_n(1);
// }

// void Operations::fload_2(){
// 	fload_n(2);
// }

// void Operations::fload_3(){
// 	fload_n(3);
// }

// // DLOAD_<N>
// void Operations::dload_n(short index)
// {
// 	Typed_element aux = frame->local_variables->get_typed_element(index);
// 	frame->operand_stack->push_type(aux.value.d);
// }

// void Operations::dload_0(){
// 	dload_n(0);
// }

// void Operations::dload_1(){
// 	dload_n(1);
// }

// void Operations::dload_2(){
// 	dload_n(2);
// }

// void Operations::dload_3(){
// 	dload_n(3);
// }

// // ALOAD_<N>
// void Operations::aload_n(short index)
// {
// 	Typed_element aux = frame->local_variables->get_typed_element(index);
// 	frame->operand_stack->push_type(aux.value.pi);
// }

// void Operations::aload_0(){
// 	aload_n(0);
// }

// void Operations::aload_1(){
// 	aload_n(1);
// }

// void Operations::aload_2(){
// 	aload_n(2);
// }

// void Operations::aload_3(){
// 	aload_n(3);
// }

// void Operations::iaload(){
// 	Element value1, value2;

// 	value1 = frame->operand_stack->pop();
//   	value2 = frame->operand_stack->pop();
//   	int *ref = value2.pi;

//   	if (ref == nullptr)
//     	throw runtime_error("Null pointer");
// 	frame->operand_stack->push_type(ref[value1.i]);

// }

// void Operations::laload(){
// 	// Element value1, value2;
// 	// struct Typed_element_s result;

// 	// value1 = frame->operand_stack->pop();
//   	// value2 = frame->operand_stack->pop();
//   	// Local_variable *ref = (Local_variable *) value2.pi;
//   	// if (ref == nullptr)
//     // 	throw runtime_error("Null pointer");

// 	// frame->operand_stack->push_type(reframe->get(value1.i));
// }

// //Fim linha 2
// //Inicio linha 3
// void Operations::lstore_0() {
// 	// Typed_element var = frame->operand_stack->pop_typed_element();
// 	// if(var.type == TYPE_LONG) {
// 	// 	frame->local_variables->insert_typed_element(0, var);
// 	// }
// 	// else
// 	// 	printf("Operando no topo != TYPE_LONG\n");
// }

// //pode ser utilizada em conjunto com wide
// void Operations::lstore() {
// //    uint16_t index = 0;

// //    if (is_wide) {
// // 		index = get_n_bytes_value(2, frame->pc);
// // 		is_wide = false;
// // 	}else
// // 		index = get_n_bytes_value(1, frame->pc);

// // 	if(frame->operand_stack->top_type() == TYPE_LONG) {
// // 		Typed_element aux = frame->operand_stack->pop_typed_element();
// // 		frame->local_variables->insert_typed_element(aux, index);
// // 	}
// // 	else
// // 		printf("Operando no topo != TYPE_LONG\n");
// }

// //pode ser utilizada em conjunto com wide
// void Operations::istore() {
// //    uint16_t index = 0;

// // 	if (is_wide) {
// // 		index = get_n_bytes_value(2, frame->pc);
// // 		is_wide = false;
// // 	}else
// // 		index = get_n_bytes_value(1, frame->pc);

// // 	if(frame->operand_stack->top_type() == TYPE_INT) {
// // 		Typed_element aux = frame->operand_stack->pop_typed_element();
// // 		frame->local_variables->insert_typed_element(aux, index);
// // 	}
// // 	else
// // 		printf("Operando no topo != TYPE_INT\n");
// }

// //pode ser utilizada em conjunto com wide
// void Operations::fstore() {
// 	// uint16_t index = 0;

// 	// if (is_wide) {
// 	// 	index = get_n_bytes_value(2, frame->pc);
// 	// 	is_wide = false;
// 	// }else
// 	// 	index = get_n_bytes_value(1, frame->pc);

// 	// if(frame->operand_stack->top_type() == TYPE_FLOAT) {
// 	// 	Typed_element aux = frame->operand_stack->pop_typed_element();
// 	// 	frame->local_variables->insert_typed_element(aux, index);
// 	// }
// 	// else
// 	// 	printf("Operando no topo != TYPE_FLOAT\n");
// }

// //pode ser utilizada em conjunto com wide
// void Operations::dstore() {
// //    uint16_t index = 0;

// // 	if (is_wide) {
// // 		index = get_n_bytes_value(2, frame->pc);
// // 		is_wide = false;
// // 	} else
// // 		index = get_n_bytes_value(1, frame->pc);

// // 	if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
// // 		Typed_element aux = frame->operand_stack->pop_typed_element();
// // 		frame->local_variables->insert_typed_element(aux,index);
// // 	}
// // 	else
// // 		printf("Operando no topo != TYPE_DOUBLE\n");
// }

// //pode ser utilizada em conjunto com wide
// void Operations::astore() {
// //    uint16_t index = 0;

// //    	if (is_wide) {
// // 		index = get_n_bytes_value(2, frame->pc);
// // 		is_wide = false;
// // 	} else
// // 		index = get_n_bytes_value(1, frame->pc);

// // 	if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
// // 		Typed_element aux = frame->operand_stack->pop_typed_element();
// // 		frame->local_variables->insert_typed_element(aux, index);
// // 	}
// // 	else
// // 		printf("Operando no topo != TYPE_REFERECE\n");
// }

// void Operations::istore_0() {
// 	if(frame->operand_stack->top_type() == TYPE_INT) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 0);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_INT\n");
// }

// void Operations::istore_1() {
// 	if(frame->operand_stack->top_type() == TYPE_INT) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux,1);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_INT\n");
// }

// void Operations::istore_2() {
// 	if(frame->operand_stack->top_type() == TYPE_INT) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 2);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_INT\n");
// }

// void Operations::istore_3() {
// 	if(frame->operand_stack->top_type() == TYPE_INT) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 3);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_INT\n");
// }

// //Pega um valor do tipo float de um array e empilha na pilha de operandos
// void Operations::faload() {
// 	// int index = frame->operand_stack->pop().i;
// 	// Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop().pi;
// 	// if(arrayref == NULL){
// 	// }
// 	// frame->operand_stack->push_type(arrayreframe->get(index));
// }

// //Pega um valor do tipo double de um array e empilha na pilha de operandos
// void Operations::daload() {
// 	// int index = frame->operand_stack->pop().i;
// 	// Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop().pi;
// 	// frame->operand_stack->push_type(arrayreframe->get(index));
// }

// //Pega uma referência de um array e empilha na pilha de operandos
// void Operations::aaload() {
// 	// int index = frame->operand_stack->pop().i;
// 	// Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop().pi;
// 	// frame->operand_stack->push_type(arrayreframe->get(index));
// }

// //Pega um boolean ou byte de um array e empilha na pilha de operandos
// //Como Boolean é representado com um byte, não há necessidade de distinção
// void Operations::baload() {
// 	// int index = frame->operand_stack->pop().i;
// 	// Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop().pi;
// 	// frame->operand_stack->push_type(arrayreframe->get(index));
// }

// //Pega um char de um array e empilha na pilha de operandos
// void Operations::caload() {
// 	// int index = frame->operand_stack->pop().i;
// 	// std::vector<char> *arrayref = (std::vector<char> *) frame->operand_stack->pop().pi;
// 	// frame->operand_stack->push_type(arrayreframe->at(index));
// }

// void Operations::saload() {
// 	// int index = frame->operand_stack->pop().i;
// 	// Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop().pi;
// 	// frame->operand_stack->push_type(arrayreframe->get(index));
// }

// //Fim linha 3
// //Inicio linha 4
// void Operations::lstore_1() {
// 	// if(frame->operand_stack->top_type() == TYPE_LONG) {
// 	// 	Typed_element aux = frame->operand_stack->pop_typed_element();
// 	// 	frame->local_variables->insert_typed_element(1, aux);
// 	// }
// 	// else
// 	// 	printf("Operando no topo != TYPE_LONG\n");
// }

// void Operations::lstore_2() {
// 	if(frame->operand_stack->top_type() == TYPE_LONG) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 2);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_LONG\n");
// }

// void Operations::lstore_3() {
// 	if(frame->operand_stack->top_type() == TYPE_LONG) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 3);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_LONG\n");
// }

// void Operations::fstore_0() {
// 	if(frame->operand_stack->top_type() == TYPE_FLOAT) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 0);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_FLOAT\n");
// }

// void Operations::fstore_1() {
// 	// if(frame->operand_stack->top_type() == TYPE_FLOAT) {
// 	// 	Typed_element aux = frame->operand_stack->pop_typed_element();
// 	// 	frame->local_variables->insert_typed_element(1, aux);
// 	// }
// 	// else
// 	// 	printf("Operando no topo != TYPE_FLOAT\n");
// }

// void Operations::fstore_2() {
// 	if(frame->operand_stack->top_type() == TYPE_FLOAT) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 2);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_FLOAT\n");
// }

// void Operations::fstore_3() {
// 	if(frame->operand_stack->top_type() == TYPE_FLOAT) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 3);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_FLOAT\n");
// }

// void Operations::dstore_0() {
// 	if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 0);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_DOUBLE\n");
// }

// void Operations::dstore_1() {
// 	// if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
// 	// 	Typed_element aux = frame->operand_stack->pop_typed_element();
// 	// 	frame->local_variables->insert_typed_element(1, aux);
// 	// }
// 	// else
// 	// 	printf("Operando no topo != TYPE_DOUBLE\n");
// }

// void Operations::dstore_2() {
// 	if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 2);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_DOUBLE\n");
// }

// void Operations::dstore_3() {
// 	if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 3);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_DOUBLE\n");
// }

// void Operations::astore_0() {
// 	if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 0);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_REFERENCE\n");
// }

// void Operations::astore_1() {
// 	// if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
// 	// 	Typed_element aux = frame->operand_stack->pop_typed_element();
// 	// 	frame->local_variables->insert_typed_element(1, aux);
// 	// }
// 	// else
// 	// 	printf("Operando no topo != TYPE_REFERENCE\n");
// }

// void Operations::astore_2() {
// 	if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 2);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_REFERENCE\n");
// }

// void Operations::astore_3() {
// 	if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		frame->local_variables->insert_typed_element(aux, 3);
// 	}
// 	else
// 		printf("Operando no topo != TYPE_REFERENCE\n");
// }

// void Operations::iastore() {
// 	Element valor = frame->operand_stack->pop();
// 	Element indice = frame->operand_stack->pop();
// 	int *vetor = frame->operand_stack->pop().pi;

// 	// if(vetor.pi == NULL)
// 	// 	throw(NullPointerException);
// 	// if(indice < 0 || indice >= (vetor.pi).capacity())
// 	// 	throw(ArrayIndexOutOfBoundsException);
// 	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
// 		Typed_element aux;
// 		aux.value.i = valor.i;
// 		aux.type = TYPE_INT;
// 		aux.real_type = RT_INT;
// 		vetor[indice.i] = valor.i;
// }

// //Fim linha 4
// //Inicio linha 5

// //Armazena um double na pilha de operandos como um componente de array
// void Operations::lastore() {
// 	Element valor = frame->operand_stack->pop();
// 	Element indice = frame->operand_stack->pop();
// 	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop().pi;

// 	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
// 		Typed_element aux;
// 		aux.value.l = valor.l;
// 		aux.type = TYPE_LONG;
// 		aux.real_type = RT_LONG;
// 		vetor->insert_typed_element(indice.i, aux);	}

// //Armazena um float na pilha de operandos como um componente de array
// void Operations::fastore() {
// 	Element valor = frame->operand_stack->pop();
// 	Element indice = frame->operand_stack->pop();
// 	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop().pi;

// 	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
// 		Typed_element aux;
// 		aux.value.f = valor.f;
// 		aux.type = TYPE_FLOAT;
// 		aux.real_type = RT_FLOAT;
// 		vetor->insert_typed_element(indice.i, aux);	}

// //Armazena um double na pilha de operandos como um componente de array
// void Operations::dastore() {
// 	Element valor = frame->operand_stack->pop();
// 	Element indice = frame->operand_stack->pop();
// 	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop().pi;

// 	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
// 		Typed_element aux;
// 		aux.value.d = valor.d;
// 		aux.type = TYPE_DOUBLE;
// 		aux.real_type = RT_DOUBLE;
// 		vetor->insert_typed_element(indice.i, aux);	}

// //Armazena uma referência na pilha de operandos como um componente de um array
// void Operations::aastore() {
// 	Element valor = frame->operand_stack->pop();
// 	Element indice = frame->operand_stack->pop();
// 	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop().pi;

// 	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
// 		Typed_element aux;
// 		aux.value.pi = valor.pi;
// 		aux.type = TYPE_REFERENCE;
// 		aux.real_type = RT_REFERENCE;
// 		vetor->insert_typed_element(indice.i, aux);	}

// //Armazena um byte na pilha de operandos como um componente de array
// void Operations::bastore() {
// 	Element valor = frame->operand_stack->pop();
// 	Element indice = frame->operand_stack->pop();
// 	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop().pi;

// 	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
// 		Typed_element aux;
// 		aux.value.i = valor.i;
// 		aux.type = TYPE_INT;
// 		aux.real_type = RT_BOOL;
// 		vetor->insert_typed_element(indice.i, aux);	}

// //Armazena um caracter na pilha de operandos como um componente de array
// void Operations::castore() {
// 	Element valor = frame->operand_stack->pop();
// 	Element indice = frame->operand_stack->pop();
// 	std::vector<uint8_t> *vetor = (std::vector<uint8_t> *) frame->operand_stack->pop().pi;

// 	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
// 		vetor->at(indice.i) = valor.bs;
// }

// //Armazena um short na pilha de operandos como componente de array
// void Operations::sastore() {
// 	Element valor = frame->operand_stack->pop();
// 	Element indice = frame->operand_stack->pop();
// 	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop().pi;

// 	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
// 		Typed_element aux;
// 		aux.value.i = valor.i;
// 		aux.type = TYPE_INT;
// 		aux.real_type = RT_SHORT;
// 		vetor->insert_typed_element(indice.i, aux);
// }

// //Fim linha 5
// //Inicio linha 6

// void Operations::iadd()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_INT) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um inteiro!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_INT) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um inteiro!");
//     }

// 	result.type = TYPE_INT;
// 	result.real_type = RT_INT;
// 	result.value.i = value1.i + value2.i;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::ladd()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_LONG) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um long!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_LONG) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um long!");
//     }

// 	result.type = TYPE_LONG;
// 	result.real_type = RT_LONG;
// 	result.value.l = value1.l + value2.l;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::fadd()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_FLOAT) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um float!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_FLOAT) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um float!");
//     }

// 	result.type = TYPE_FLOAT;
// 	result.real_type = RT_FLOAT;
// 	result.value.f = value1.f + value2.f;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::dadd()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um double!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um double!");
//     }

// 	result.type = TYPE_DOUBLE;
// 	result.real_type = RT_DOUBLE;
// 	result.value.d = value1.d + value2.d;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::isub()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_INT) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um inteiro!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_INT) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um inteiro!");
//     }

// 	result.type = TYPE_INT;
// 	result.real_type = RT_INT;
// 	result.value.i = value1.i - value2.i;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::lsub()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_LONG) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um long!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_LONG) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um long!");
//     }

// 	result.type = TYPE_LONG;
// 	result.real_type = RT_LONG;
// 	result.value.l = value1.l - value2.l;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::fsub()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_FLOAT) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um float!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_FLOAT) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um float!");
//     }

// 	result.type = TYPE_FLOAT;
// 	result.real_type = RT_FLOAT;
// 	result.value.f = value1.f - value2.f;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::dsub()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um double!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um double!");
//     }

// 	result.type = TYPE_DOUBLE;
// 	result.real_type = RT_DOUBLE;
// 	result.value.d = value1.d - value2.d;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::imul()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_INT) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um inteiro!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_INT) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um inteiro!");
//     }

// 	result.type = TYPE_INT;
// 	result.real_type = RT_INT;
// 	result.value.i = value1.i * value2.i;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::lmul()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_LONG) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um long!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_LONG) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um long!");
//     }

// 	result.type = TYPE_LONG;
// 	result.real_type = RT_LONG;
// 	result.value.l = value1.l * value2.l;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::fmul()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_FLOAT) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um float!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_FLOAT) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um float!");
//     }

// 	result.type = TYPE_FLOAT;
// 	result.real_type = RT_FLOAT;
// 	result.value.f = value1.f * value2.f;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::dmul()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um double!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um double!");
//     }

// 	result.type = TYPE_DOUBLE;
// 	result.real_type = RT_DOUBLE;
// 	result.value.d = value1.d * value2.d;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::idiv()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_INT) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um inteiro!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_INT) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um inteiro!");
//     }

// 	result.type = TYPE_INT;
// 	result.real_type = RT_INT;
// 	result.value.i = value1.i / value2.i;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::ldiv()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_LONG) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um long!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_LONG) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um long!");
//     }

// 	result.type = TYPE_LONG;
// 	result.real_type = RT_LONG;
// 	result.value.l = value1.l / value2.l;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::fdiv()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_FLOAT) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um float!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_FLOAT) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um float!");
//     }

// 	result.type = TYPE_FLOAT;
// 	result.real_type = RT_FLOAT;
// 	result.value.f = value1.f / value2.f;
// 	frame->operand_stack->push_type(result);
// }

// void Operations::ddiv()
// {
// 	Element value1, value2;
// 	struct Typed_element_s result;

//     if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
//     	value2 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um double!");
//     }

//     if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
// 		value1 = frame->operand_stack->pop();
//     } else {
//     	throw std::runtime_error("Elemento lido nao era um double!");
//     }

// 	result.type = TYPE_DOUBLE;
// 	result.real_type = RT_DOUBLE;
// 	result.value.d = value1.d / value2.d;
// 	frame->operand_stack->push_type(result);
// }

// //Fim linha 6
// //Inicio linha 7

// void Operations::irem () {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     if (value2.i == 0) {
//         throw std::runtime_error("Arithmetic Exeption: divisao por z    ");
//     }

//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_INT;
//     result.real_type = RT_INT;
//     result.value.i = value1.i - int(value1.i/value2.i) * value2.i;
//     frame->operand_stack->push_type(result);
// }

// void Operations::lrem () {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     if (value2.l == 0) {
//         throw std::runtime_error("Arithmetic Exeption: divisao por zero.");
//     }

//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_LONG;
//     result.real_type = RT_LONG;
//     result.value.l = value1.l - int(value1.l/value2.l) * value2.l;
//     frame->operand_stack->push_type(result);
// }

// void Operations::frem () {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     if (checkFloat(value1.f) == 3 || checkFloat(value2.f) == 3) {
//         result.value.i = Float_NaN;
//     } else if (checkFloat(value1.f) == 1 || checkFloat(value1.f) == 2 || value2.f == 0.0) {
//         result.value.i = Float_NaN;
//     } else if (checkFloat(value1.f) == 0 && (checkFloat(value2.f) == 1 || checkFloat(value2.f) == 2)) {
//         result.value.f = value1.f;
//     } else if (value1.f == 0.0 && checkFloat(value2.f) == 0) {
//         result.value.f = 0.0;
//     } else {
//         result.value.f = fmod(value1.f, value2.f);
//     }

//     result.type = TYPE_FLOAT;
//     result.real_type = RT_FLOAT;
//     frame->operand_stack->push_type(result);
// }

// void Operations::drem () {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     if (checkDouble(value1.d) == 3 || checkDouble(value2.d) == 3) {
//         result.value.l = Double_NaN;
//     } else if (checkDouble(value1.d) == 1 || checkDouble(value1.d) == 2 || value2.d == double(0.0)) {
//         result.value.l = Double_NaN;
//     } else if (checkDouble(value1.d) == 0 && (checkDouble(value2.d) == 1 || checkDouble(value2.d) == 2)) {
//         result.value.d = value1.d;
//     } else if (value1.d == 0.0 && checkDouble(value2.d) == 0) {
//         result.value.d = 0.0;
//     } else {
//         result.value.d = fmod(value1.d, value2.d);
//     }

//     result.type = TYPE_DOUBLE;
//     result.real_type = RT_DOUBLE;
//     frame->operand_stack->push_type(result);
// }

// void Operations::ineg () {
//     Element value;
//     struct Typed_element_s result;

//     value = frame->operand_stack->pop();

//     result.type = TYPE_INT;
//     result.real_type = RT_INT;
//     result.value.is = 0 - value.is;
//     frame->operand_stack->push_type(result);
// }

// void Operations::lneg () {
//     Element value;
//     struct Typed_element_s result;

//     value = frame->operand_stack->pop();

//     result.type = TYPE_LONG;
//     result.real_type = RT_LONG;
//     result.value.ls = 0 - value.ls;
//     frame->operand_stack->push_type(result);
// }

// void Operations::fneg () {
//     Element value;
//     struct Typed_element_s result;

//     value = frame->operand_stack->pop();

//     result.type = TYPE_FLOAT;
//     result.real_type = RT_FLOAT;
//     //inverte o bit 31
//     result.value.i = value.i + 0x80000000;
//     frame->operand_stack->push_type(result);
// }

// void Operations::dneg () {
//     Element value;
//     struct Typed_element_s result;

//     value = frame->operand_stack->pop();

//     result.type = TYPE_DOUBLE;
//     result.real_type = RT_DOUBLE;
//     //inverte o bit 63
//     result.value.l = value.l + 0x8000000000000000;
//     frame->operand_stack->push_type(result);
// }

// void Operations::ishl() {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_INT;
//     result.real_type = RT_INT;
//     result.value.i = value1.i << (value2.i & 0b011111);
//     frame->operand_stack->push_type(result);
// }

// void Operations::lshl() {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_LONG;
//     result.real_type = RT_LONG;
//     result.value.l = value1.l << (value2.i & 0b0111111);
//     frame->operand_stack->push_type(result);
// }

// void Operations::ishr () {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_INT;
//     result.real_type = RT_INT;
//     result.value.is = value1.is >> (value2.i & 0b011111);
//     frame->operand_stack->push_type(result);
// }

// void Operations::lshr () {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_LONG;
//     result.real_type = RT_LONG;
//     result.value.ls = value1.ls >> (value2.i & 0b0111111);
//     frame->operand_stack->push_type(result);
// }

// void Operations::iushr () {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_INT;
//     result.real_type = RT_INT;
//     result.value.i = value1.i >> (value2.i & 0b011111);
//     frame->operand_stack->push_type(result);
// }

// void Operations::lushr () {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_LONG;
//     result.real_type = RT_LONG;
//     result.value.l = value1.l >> (value2.i & 0b0111111);
//     frame->operand_stack->push_type(result);
// }

// void Operations::iand() {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_INT;
//     result.real_type = RT_INT;
//     result.value.i = value1.i & value2.i;
//     frame->operand_stack->push_type(result);
// }

// void Operations::land() {
//     Element value1, value2;
//     struct Typed_element_s result;

//     value2 = frame->operand_stack->pop();
//     value1 = frame->operand_stack->pop();

//     result.type = TYPE_LONG;
//     result.real_type = RT_LONG;
//     result.value.l = value1.l & value2.l;
//     frame->operand_stack->push_type(result);
// }

// //Fim linha 7
// //Inicio linha 8

// void Operations::ior(){
// 	Element aux1 = frame->operand_stack->pop();
// 	Element aux2 = frame->operand_stack->pop();
// 	aux1.i |= aux2.i;
// 	frame->operand_stack->push_type(aux1, TYPE_INT);
// }

// void Operations::lor(){
// 	Element aux1 = frame->operand_stack->pop();
// 	Element aux2 = frame->operand_stack->pop();
// 	aux1.l |= aux2.l;
// 	frame->operand_stack->push_type(aux1, TYPE_LONG);
// }

// void Operations::ixor(){
// 	Element aux1 = frame->operand_stack->pop();
// 	Element aux2 = frame->operand_stack->pop();
// 	aux1.i ^= aux2.i;
// 	frame->operand_stack->push_type(aux1, TYPE_INT);
// }

// void Operations::lxor(){
// 	Element aux1 = frame->operand_stack->pop();
// 	Element aux2 = frame->operand_stack->pop();
// 	aux1.l ^= aux2.l;
// 	frame->operand_stack->push_type(aux1, TYPE_LONG);
// }

// //pode ser utilizada em conjunto com o wide
// void Operations::iinc(){
// 	uint16_t var;
// 	int16_t n;
// 	if(is_wide){
// 		 var = get_n_bytes_value(2, frame->pc);
// 		 n = int16_t(get_n_bytes_value(2, frame->pc));
// 	}
// 	else {
// 		 var = get_n_bytes_value(1, frame->pc);
// 		 n = int8_t(get_n_bytes_value(1, frame->pc));
// 	}

// 	Typed_element aux = frame->local_variables->get_typed_element(var);
// 	if(aux.type == TYPE_INT)
// 		aux.value.i += (int32_t)n;
// 	frame->local_variables->insert_typed_element(var, aux);
// }

// void Operations::i2l(){
// 	frame->operand_stack->push_type(frame->operand_stack->pop(), TYPE_LONG);
// }

// void Operations::i2f(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.f = (float)aux.is;
// 	frame->operand_stack->push_type(aux.f);
// }

// void Operations::i2d(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.d = (double)aux.is;
// 	frame->operand_stack->push_type(aux.d);
// }

// void Operations::l2i(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.i = (uint32_t)aux.l;
// 	frame->operand_stack->push_type(aux, TYPE_INT);
// }

// void Operations::l2f(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.f = (float)aux.l;
// 	frame->operand_stack->push_type(aux, TYPE_FLOAT);
// }

// void Operations::l2d(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.d = (double)aux.l;
// 	frame->operand_stack->push_type(aux.d);
// }

// void Operations::f2i(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.is = (int32_t)aux.f;
// 	frame->operand_stack->push_type(aux.is);
// }

// void Operations::f2l(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.l = (int64_t)aux.f;
// 	frame->operand_stack->push_type(aux, TYPE_LONG);
// }

// void Operations::f2d(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.d = (double)aux.f;
// 	frame->operand_stack->push_type(aux.d);
// }

// void Operations::d2i(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.is = (int32_t)aux.d;
// 	frame->operand_stack->push_type(aux.is);
// }

// void Operations::d2l(){
// 	Element aux = frame->operand_stack->pop();
// 	aux.l = (int64_t)aux.d;
// 	frame->operand_stack->push_type(aux, TYPE_LONG);
// }

// //Fim linha 8
// //Inicio linha 9

// void Operations::d2f () {
// 	Element aux = frame->operand_stack->pop();
// 	aux.f = (float)aux.d;
// 	frame->operand_stack->push_type(aux.f);
// }

// //le um int do topo da pilha (truncado para byte), extende com sinal para um int e reinsere na pilha de operandos
// void Operations::i2b() {
// 	int8_t value = frame->operand_stack->pop().bs;

// 	frame->operand_stack->push_type(int(value));
// }

// //le um int do topo da pilha (truncado para char), extende com 0 para um int  e reinsere na pilha de operandos
// void Operations::i2c() {
// 	Typed_element value;
// 	value.type = TYPE_INT;
// 	value.real_type = RT_CHAR;
// 	value.value.b = frame->operand_stack->pop().b;
// 	frame->operand_stack->push_type(value);
// }

// //le um int do topo da pilha (truncado para short), extende com sinal para um int e reinsere na pilha de operandos
// void Operations::i2s() {
// 	Typed_element value;
// 	value.type = TYPE_INT;
// 	value.real_type = RT_SHORT;
// 	value.value.ss = frame->operand_stack->pop().ss;

// 	frame->operand_stack->push_type(value);
// }

// //le os dois primeiros Elementos da pilha de operandos (dois Elementos do tipo long) e os compara
// void Operations::lcmp(){
// 	int64_t value2 = frame->operand_stack->pop().ls;
// 	int64_t value1 = frame->operand_stack->pop().ls;

// 	if (value1 > value2)
// 		frame->operand_stack->push_type(int(1));
// 	if (value1 == value2)
// 		frame->operand_stack->push_type(int(0));
// 	if (value1 < value2)
// 		frame->operand_stack->push_type(int(-1));
// }

// //le os dois primeiros Elementos da pilha de operandos (dois Elementos do tipo float) e os compara
// void Operations::fcmpl() {
// 	float value2 = frame->operand_stack->pop().f;
// 	float value1 = frame->operand_stack->pop().f;
// 	int res1, res2;

// 	res1 = checkFloat(value1);
// 	res2 = checkFloat(value2);
// 	//se value1 ou value2 for NaN entao adiciona -1 na pilha de operandos
// 	if (res1 == 3 || res2 == 3){
// 		frame->operand_stack->push_type(int(-1));
// 	} else {
// 		if (value1 > value2)
// 			frame->operand_stack->push_type(int(1));
// 		if (value1 == value2)
// 			frame->operand_stack->push_type(int(0));
// 		if (value1 < value2)
// 			frame->operand_stack->push_type(int(-1));
// 	}
// }

// //le os dois primeiros Elementos da pilha de operandos (dois Elementos do tipo float) e os compara
// void Operations::fcmpg() {
// 	float value2 = frame->operand_stack->pop().f;
// 	float value1 = frame->operand_stack->pop().f;
// 	int res1, res2;

// 	res1 = checkFloat(value1);
// 	res2 = checkFloat(value2);
// 	//se value1 ou value2 for NaN entao adiciona 1 na pilha de operandos
// 	if (res1 == 3 || res2 == 3){
// 		frame->operand_stack->push_type(int(1));
// 	} else {
// 		if (value1 > value2)
// 			frame->operand_stack->push_type(int(1));
// 		if (value1 == value2)
// 			frame->operand_stack->push_type(int(0));
// 		if (value1 < value2)
// 			frame->operand_stack->push_type(int(-1));
// 	}
// }

// //le os dois primeiros Elementos da pilha de operandos (dois Elementos do tipo double) e os compara
// void Operations::dcmpl() {
// 	double value2 = frame->operand_stack->pop().d;
// 	double value1 = frame->operand_stack->pop().d;
// 	int res1, res2;

// 	res1 = checkDouble(value1);
// 	res2 = checkDouble(value2);
// 	//se value1 ou value2 for NaN entao adiciona 1 na pilha de operandos
// 	if (res1 == 3 || res2 == 3){
// 		frame->operand_stack->push_type(int(1));
// 	} else {
// 		if (value1 > value2)
// 			frame->operand_stack->push_type(int(1));
// 		if (value1 == value2)
// 			frame->operand_stack->push_type(int(0));
// 		if (value1 < value2)
// 			frame->operand_stack->push_type(int(-1));
// 	}
// }

// //le os dois primeiros Elementos da pilha de operandos (dois Elementos do tipo double) e os compara
// void Operations::dcmpg() {
// 	double value2 = frame->operand_stack->pop().d;
// 	double value1 = frame->operand_stack->pop().d;
// 	int res1, res2;

// 	res1 = checkDouble(value1);
// 	res2 = checkDouble(value2);
// 	//se value1 ou value2 for NaN entao adiciona 1 na pilha de operandos
// 	if (res1 == 3 || res2 == 3){
// 		frame->operand_stack->push_type(int(1));
// 	} else {
// 		if (value1 > value2)
// 			frame->operand_stack->push_type(int(1));
// 		if (value1 == value2)
// 			frame->operand_stack->push_type(int(0));
// 		if (value1 < value2)
// 			frame->operand_stack->push_type(int(-1));
// 	}
// }

// //le o valor do topo da pilha, se for igual a 0 salta
// void Operations::ifeq() {
// 	int value = frame->operand_stack->pop().i;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	if (value == 0)
// 		frame->pc += branchbyte - 3;

// }

// //le o valor do topo da pilha, se for diferente de 0 salta
// void Operations::ifne() {
// 	int value = frame->operand_stack->pop().i;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	if (value != 0)
// 		frame->pc += branchbyte - 3;

// }

// //le o valor do topo da pilha, se for menor que 0 salta
// void Operations::iflt() {
// 	int value = frame->operand_stack->pop().i;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	if (value < 0)
// 		frame->pc += branchbyte - 3;

// }

// //le o valor do topo da pilha, se for maior ou igual a 0 salta
// void Operations::ifge() {
// 	int value = frame->operand_stack->pop().i;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	if (value >= 0)
// 		frame->pc += branchbyte - 3;

// }

// //le o valor do topo da pilha, se for maior que 0 salta
// void Operations::ifgt() {
// 	int value = frame->operand_stack->pop().i;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	if (value > 0)
// 		frame->pc += branchbyte - 3;
// }

// //le o valor do topo da pilha, se for menor ou igual a 0 salta
// void Operations::ifle() {
// 	int value = frame->operand_stack->pop().i;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	if (value <= 0)
// 		frame->pc += branchbyte - 3;
// }

// //le dois valores da pilha, se forem iguais salta
// void Operations::if_icmpeq () {
// 	int value1, value2;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	value2 = frame->operand_stack->pop().i;
// 	value1 = frame->operand_stack->pop().i;

// 	if (value1 == value2) {
// 		frame->pc += branchbyte - 3;
// 	}
// }

// //Fim linha 9
// //Inicio linha 10

// void Operations::if_icmpne () {
// 	int value1, value2;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	value2 = frame->operand_stack->pop().i;
// 	value1 = frame->operand_stack->pop().i;

// 	if (value1 != value2) {
// 		frame->pc += branchbyte - 3;
// 	}
// }

// void Operations::if_icmplt() {
// 	int value1, value2;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	value2 = frame->operand_stack->pop().i;
// 	value1 = frame->operand_stack->pop().i;

// 	if (value1 < value2) {
// 		frame->pc += branchbyte - 3;
// 	}
// }

// void Operations::if_icmpge() {
// 	int value1, value2;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	value2 = frame->operand_stack->pop().is;
// 	value1 = frame->operand_stack->pop().is;

// 	if (value1 >= value2) {
// 		frame->pc += branchbyte - 3;
// 	}
// }

// void Operations::if_icmpgt() {
// 	int value1, value2;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	value2 = frame->operand_stack->pop().i;
// 	value1 = frame->operand_stack->pop().i;

// 	if (value1 > value2) {
// 		frame->pc += branchbyte - 3;
// 	}
// }

// void Operations::if_icmple() {
// 	int value1, value2;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	value2 = frame->operand_stack->pop().i;
// 	value1 = frame->operand_stack->pop().i;

// 	if (value1 <= value2) {
// 		frame->pc += branchbyte - 3;
// 	}
// }

// void Operations::if_acmpeq() {
// 	int *value1, *value2;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	value2 = frame->operand_stack->pop().pi;
// 	value1 = frame->operand_stack->pop().pi;

// 	if (value1 == value2) {
// 		frame->pc += branchbyte - 3;
// 	}
// }

// void Operations::if_acmpne() {
// 	int *value1, *value2;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	value2 = frame->operand_stack->pop().pi;
// 	value1 = frame->operand_stack->pop().pi;

// 	if (value1 != value2) {
// 		frame->pc += branchbyte - 3;
// 	}
// }

// void Operations::funcgoto() {
// 	int16_t offset;

// 	offset = int16_t(get_n_bytes_value(2, frame->pc));

// 	frame->pc += offset - 3;
// }

// void Operations::jsr() {
// 	int16_t offset;

// 	offset = int16_t(get_n_bytes_value(2, frame->pc));

// 	frame->operand_stack->push_type((int*)frame->pc);

// 	frame->pc += offset - 3;
// }

// //pode ser utilizada em conjunto com wide
// void Operations::funcret() {
// 	if (is_wide){
// 		frame->pc = (unsigned char *) frame->local_variables->get_typed_element(get_n_bytes_value(2, frame->pc)).value.pi;
// 		is_wide = false;
// 	}
// 	else
// 		frame->pc = (unsigned char *) frame->local_variables->get_typed_element(get_n_bytes_value(1, frame->pc)).value.pi;
// }

// void Operations::tableswitch() {
// 	//guarda o valor inicial do pc
// 	unsigned char *bkpPC = (frame->pc) - 1;
// 	uint8_t mod = (frame->pc - frame->m.attributes->info->code.code) % 4;
// 	frame->pc += mod;

// 	int32_t defaults, low, high, offset;
// 	defaults = int32_t(get_n_bytes_value(4, frame->pc));
// 	low = int32_t(get_n_bytes_value(4, frame->pc));
// 	high = int32_t(get_n_bytes_value(4, frame->pc));

// 	int32_t index = frame->operand_stack->pop_typed_element().value.is;

// 	//salto padrão caso index não esteja no range correto
// 	if (index < low || index > high) {
// 		frame->pc = bkpPC;
// 		frame->pc += defaults;
// 		return;
// 	}

// 	for (; low < high+1; low++) {
// 		offset = int32_t(get_n_bytes_value(4,frame->pc));
// 		if (index == low) {
// 			break;
// 		}

// 	}
// 	frame->pc = bkpPC;
// 	frame->pc += offset;
// }

// void Operations::lookupswitch() {
// 	unsigned char *aux = (frame->pc) - 1;
// 	int diff = (frame->pc - frame->m.attributes->info->code.code) % 4;

// 	frame->pc += diff;

//     int32_t defaultValue = get_n_bytes_value(4,frame->pc);
// 	int32_t npairs = get_n_bytes_value(4,frame->pc);
//     int32_t match, offset, key = frame->operand_stack->pop().is;
//     int i;

//     for(i = 0; i < npairs; i++) {
//     	match = get_n_bytes_value(4,frame->pc);
//     	offset = get_n_bytes_value(4,frame->pc);

//     	if (match == key) {
//     		frame->pc = aux + offset;
//     		break;
//     	}
//     }

//     if (i == npairs) {
//     	frame->pc = aux + defaultValue;
//     }
// }

// void Operations::ireturn() {
// 	int value = frame->operand_stack->pop().i;

// 	while (!frame->operand_stack->empty()) {
// 		frame->operand_stack->pop();
// 	}

// 	threads->pop();
// 	f = threads->top();
// 	frame->operand_stack->push_type(value);
// }

// void Operations::lreturn() {
// 	long value = frame->operand_stack->pop().l;

// 	while (!frame->operand_stack->empty()) {
// 		frame->operand_stack->pop();
// 	}

// 	threads->pop();
// 	f = threads->top();
// 	frame->operand_stack->push_type(value);
// }

// void Operations::freturn() {
// 	float value = frame->operand_stack->pop().f;

// 	while (!frame->operand_stack->empty()) {
// 		frame->operand_stack->pop();
// 	}

// 	threads->pop();
// 	f = threads->top();
// 	frame->operand_stack->push_type(value);
// }

// void Operations::dreturn() {
// 	double value = frame->operand_stack->pop().d;

// 	while (!frame->operand_stack->empty()) {
// 		frame->operand_stack->pop();
// 	}

// 	threads->pop();
// 	f = threads->top();
// 	frame->operand_stack->push_type(value);
// }

// //Fim linha 10
// //Inicio linha 11

// void Operations::areturn()
// {
//     Element value;

//     if (frame->operand_stack->top_type() == TYPE_REFERENCE) {
//         value = frame->operand_stack->pop();

//         while (!frame->operand_stack->empty()) {
//             frame->operand_stack->pop();
//         }

//     } else {
//         throw std::runtime_error("Elemento lido nao era uma referencia!");
//     }

//     threads->pop();
//     f = threads->top();

//     frame->operand_stack->push_type(value.pi);
// }

// void Operations::func_return()
// {
//     while (!frame->operand_stack->empty()) {
//         frame->operand_stack->pop();
//     }

//     fs->pop();
// }

// Static_class* Operations::getStaticClassThatHasField(Static_class* base, string field_name)
// {
//     Typed_element ret = base->getField(field_name);
//     if(ret.type != TYPE_NOT_SET) {
//         return base;
//     }

//     int cp_index = base->getDef()->getSuper_class();
//     if( cp_index == 0 ) {
//         return NULL;
//     }

//     Static_class* child = Method_area::get_class(Displayer::dereference_index(base->getDef()->getCP(), cp_index));
//     return getStaticClassThatHasField(child, field_name);
// }

// void Operations::getstatic()
// {
//     uint16_t indexByte = get_n_bytes_value(2, frame->pc);

//     //volta pc para o inicio da instrucao, para caso ela tenha que ser executada novamente
//     frame->pc -= 3;

//     frame *aux = f;
//     Cp_info cp_Element = frame->cp_vector[indexByte];
//     if(cp_Element.tag != FIELD_REF) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para FIELD_REF!");
//     }

//     string class_name = Displayer::dereference_index(frame->cp_vector, cp_Element.info[0].u2);

//     Cp_info name_and_type_Element = frame->cp_vector[cp_Element.info[1].u2];
//     if(name_and_type_Element.tag != NAME_AND_TYPE) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para NAME_AND_TYPE!");
//     }

//     string name = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[0].u2);
//     string descriptor = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[1].u2);

//     // JAVA LANG
//     if (class_name == "java/lang/System" && descriptor == "Ljava/io/PrintStream;" ) {
//         frame->pc+=3;
//         return;
//     }

//     Static_class* static_class = getStaticClassThatHasField( Method_area::get_class(class_name), name);

//     if(static_class == NULL) throw std::runtime_error("Field nao existe na classe definida!");

//     // Caso <clinit> seja empilhado.
//     if (threads->top() != aux) {
//         return;
//     }

//     Typed_element Element = static_class->getField(name);

//     if(Element.type == TYPE_BOOL)
//     {
//         Element.type = TYPE_INT;
//     }

//     frame->operand_stack->push_type(Element);

//     //anda com o pc para a proxima instrucao
//     frame->pc += 3;
// }

// void Operations::putstatic()
// {
//     frame *aux = f;

//     uint16_t indexByte = get_n_bytes_value(2, frame->pc);
//     Cp_info cp_Element = frame->cp_vector[indexByte];
//     if(cp_Element.tag != FIELD_REF) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para FIELD_REF!");
//     }

//     string class_name = Displayer::dereference_index(frame->cp_vector, cp_Element.info[0].u2);

//     Cp_info name_and_type_Element = frame->cp_vector[cp_Element.info[1].u2];
//     if(name_and_type_Element.tag != NAME_AND_TYPE) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para NAME_AND_TYPE!");
//     }

//     string name = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[0].u2);
//     string descriptor = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[1].u2);

//     // JAVA LANG
//     if (class_name == "java/lang/System" && descriptor == "Ljava/io/PrintStream;" ) {
//         return;
//     }

//     Static_class* static_class = getStaticClassThatHasField( Method_area::get_class(class_name), name);

//     if(static_class == NULL) throw std::runtime_error("Field nao existe na classe definida!");

//     // Caso <clinit> seja empilhado.
//     if (threads->top() != aux) {
//         return;
//     }

//     Typed_element stack_Element = frame->operand_stack->pop_typed_element();

//     if(descriptor[0] == 'B')
//     {
//         stack_Element.type = TYPE_BOOL;
//     }

//     static_class->setField(name,stack_Element);
// }

// void Operations::getfield() {
//     uint16_t indexbyte = get_n_bytes_value(2, frame->pc);

//     Instance_class *ci = (Instance_class *) frame->operand_stack->pop().pi;

//     if (ci == nullptr) {
//         throw std::runtime_error("Null Pointer Exception");
//     }

//     int index = frame->cp_vector[indexbyte].info[1].u2;
//     index = frame->cp_vector[index].info[0].u2;
//     Typed_element ret = ci->getField(Displayer::dereference_index(frame->cp_vector, index));
//     frame->operand_stack->push_type(ret);
// }

// void Operations::putfield() {
//     Typed_element value = frame->operand_stack->pop_typed_element();
//     Instance_class *ci = (Instance_class *) frame->operand_stack->pop().pi;
//     uint16_t indexbyte = get_n_bytes_value(2, frame->pc);

//     if (ci == nullptr) {
//         throw std::runtime_error("Null Pointer Exception");
//     }

//     int index = frame->cp_vector[indexbyte].info[1].u2;
//     index = frame->cp_vector[index].info[0].u2;

//     if (Displayer::dereference_index(frame->cp_vector, frame->m.name_index) == "<init>") {
//         ci->setFinals(Displayer::dereference_index(frame->cp_vector, index), value);
//     } else {
//         ci->setField(Displayer::dereference_index(frame->cp_vector, index), value);
//     }
// }

// void Operations::invokevirtual()
// {
//     Frame *aux = new Frame();

//     uint16_t indexByte = get_n_bytes_value(2, frame->pc);

//     Cp_info cp_Element = frame->cp_vector[indexByte];
//     if(cp_Element.tag != METHODREF) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para METHOD_REF!");
//     }

//     string class_name = Displayer::dereference_index(frame->cp_vector, cp_Element.info[0].u2);

//     Cp_info name_and_type_Element = frame->cp_vector[cp_Element.info[1].u2];
//     if(name_and_type_Element.tag != NAMEANDTYPE) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para NAME_AND_TYPE!");
//     }

//     string name = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[0].u2);
//     string descriptor = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[1].u2);

//     if (class_name.find("java/") != string::npos) {
//         // simulando println ou print
//         if (class_name == "java/io/PrintStream" && (name == "print" || name == "println")) {
//             if (descriptor != "()V") {
//                 Typed_element typed_element = frame->operand_stack->pop_typed_element();
//                 switch (typed_element.real_type) {
//                     case RT_DOUBLE:
//                         printf("%f", typed_element.value.d);
//                         break;
//                     case RT_FLOAT:
//                         printf("%f", typed_element.value.f);
//                         break;
//                     case RT_LONG:
//                         printf("%lld", typed_element.value.ls);
//                         break;
//                     case RT_REFERENCE:
//                         cout << Displayer::display_UTF8((unsigned char *)typed_element.value.pi, 0);
//                         break;
//                     case RT_BOOL:
//                         printf("%s", typed_element.value.b == 0 ? "false" : "true");
//                         break;
//                     case RT_BYTE:
//                         printf("%d", typed_element.value.b);
//                         break;
//                     case RT_CHAR:
//                         printf("%c", typed_element.value.bs);
//                         break;
//                     case RT_SHORT:
//                         printf("%d", typed_element.value.ss);
//                         break;
//                     case RT_INT:
//                         printf("%d", typed_element.value.is);
//                         break;
//                     default:
//                         // PRECISA ?
//                     	//cout << "" << endl;
//                         //throw std::runtime_error("Dado Invalido.");
//                         printf("%d", typed_element.value.is);
//                         break;
//                 }
//             }

//             if (name == "println") printf("\n");

//         } else if (class_name == "java/lang/String" && name == "length") {

//             Typed_element typed_element = frame->operand_stack->pop_typed_element();
// 			if(typed_element.real_type == RT_REFERENCE) {
//                 Typed_element ret;
//                 ret.type = TYPE_INT;
//                 ret.real_type = RT_INT;

//                 ret.value.i = Displayer::display_UTF8((unsigned char *)typed_element.value.pi, 0).size();

//                 frame->operand_stack->push_type(ret);
//             }
//             else
//             {
//             	throw std::runtime_error("Dado Invalido.");
//             }

//         } else if (class_name == "java/lang/String" && name == "equals") {

//             Typed_element Element_1 = frame->operand_stack->pop_typed_element();
//             Typed_element Element_2 = frame->operand_stack->pop_typed_element();

//             if(Element_1.real_type == RT_REFERENCE && Element_2.real_type == RT_REFERENCE) {
//                 Typed_element ret;
//                 ret.type = TYPE_INT;
//                 ret.real_type = RT_INT;

//                 if (Displayer::display_UTF8((unsigned char *)Element_1.value.pi, 0) == Displayer::display_UTF8((unsigned char *)Element_2.value.pi, 0)) {
//                     ret.value.b = 1;
//                 } else {
//                     ret.value.b = 0;
//                 }

//                 frame->operand_stack->push_type(ret);
//             }
//             else
//             {
//             	throw std::runtime_error("Dados Invalidos.");
//             }

//         } else {
//             throw std::runtime_error("Metodo Invalido.");
//         }
//     } else {

//         uint16_t num_args = 0; // numero de argumentos contidos na pilha de operandos
//         uint16_t i = 1; // pulando o primeiro '('
//         while (descriptor[i] != ')')
//         {
//             char baseType = descriptor[i];
//             if (baseType == 'D' || baseType == 'J') {
//                 num_args += 2;
//             } else if (baseType == 'L') {
//                 num_args++;
//                 while (descriptor[++i] != ';');
//             } else if (baseType == '[') {
//                 num_args++;
//                 while (descriptor[++i] == '[');
//                 if (descriptor[i] == 'L') while (descriptor[++i] != ';');
//             } else {
//                 num_args++;
//             }
//             i++;
//         }

//         vector<Typed_element> args;
//         for (int i = 0; i < num_args; i++)
//         {
//             Typed_element Element = frame->operand_stack->pop_typed_element();
//             args.insert(args.begin(), Element);
//         }

//         Typed_element typed_element = frame->operand_stack->pop_typed_element();
//         if(typed_element.type == TYPE_REFERENCE)
//         {
//             throw std::runtime_error("Elemento não é uma referencia para REFERENCE!");
//         }
//         args.insert(args.begin(), typed_element);

//         Instance_class* instance = (Instance_class *) typed_element.value.pi;

//         Static_class *class_runtime = Method_area::get_class(class_name);

//         // Caso <clinit> seja empilhado.
//         if (threads->top() != aux) {
//         	frame->pc = frame->pc - 3;
//         	return;
//     	}

//         fs->addFrame(
//             instance->getStatic()->getDef()->getMethod(name,descriptor),
//             instance->getStatic()->getDef()->get_classThatHasSerachedMethod(name,descriptor)->getCP()
//         );
//         fs->setArguments(args);
//     }
// }

// void Operations::invokespecial() {
//     frame *auxFrame = threads->top();
//     uint16_t indexByte = get_n_bytes_value(2, frame->pc);

//     Cp_info cp_Element = frame->cp_vector[indexByte];
//     if(cp_Element.tag != METHOD_REF) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para METHOD_REF!");
//     }

//     string classe = Displayer::dereference_index(frame->cp_vector, cp_Element.info[0].u2);

//     Cp_info metodo = frame->cp_vector[cp_Element.info[1].u2];
//     if(metodo.tag != NAME_AND_TYPE) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para NAME_AND_TYPE!");
//     }

//     string name = Displayer::dereference_index(frame->cp_vector, metodo.info[0].u2);
//     string desc = Displayer::dereference_index(frame->cp_vector, metodo.info[1].u2);

//     //checa se é uma das classes simuladas
//     if ((classe == "java/lang/Object" || classe == "java/lang/String") && name == "<init>") {
//         if (classe == "java/lang/String") {
//             frame->operand_stack->pop();
//         }
//         return;
//     }

//     //checa se o metodo que irá executar é válido
//     if (classe.find("java/") != string::npos) {
//         cerr << "ERRO: \"" << name << "\" nao definido." << endl;
//         exit(1);
//     } else {
//         uint16_t count = 0; // numero de argumentos contidos na pilha de operandos
//         uint16_t i = 1; //variavel para andar pelo descritor

//         while (desc[i] != ')') {
//             char baseType = desc[i];
//             if (baseType == 'D' || baseType == 'J') {
//                 (++count)++;
//             } else if (baseType == 'L') {
//                 count++;
//                 //para pular o nome da classe
//                 while (desc[++i] != ';');
//             } else if (baseType == '[') {
//                 count++;
//                 //para pegar todas as dimensões mais rapidamente
//                 while (desc[++i] == '[');
//                 if (desc[i] == 'L') {
//                     //para pular o nome da classe
//                     while (desc[++i] != ';');
//                 }
//             } else {
//                 count++;
//             }
//             i++;
//         }

//         //desempilha a quantidade de parametros calculada acima
//         vector<Typed_element> parametros;
//         for (int i = 0; i < count; i++) {
//             Typed_element prox = frame->operand_stack->pop_typed_element();
//             parametros.insert(parametros.begin(), prox);
//         }

//         Typed_element typed_element = frame->operand_stack->pop_typed_element();

//         parametros.insert(parametros.begin(), typed_element);

//         Instance_class* instance = (Instance_class *) object_typed_element.value.pi;

//         Static_class *class_runtime = Method_area::get_class(classe);

//         //checa se houve uma mudança no método corrente, caso tenha, deixa o novo método executar
//         if (threads->top() != auxFrame) {
//             //empilha de volta os operandos desempilhados na ordem contrária que saíram
//             frame->operand_stack->push_type(parametros[0]);
//             while (count-- > 0) {
//                 frame->operand_stack->push_type(parametros[count]);
//             }
//             //volta com o pc para o opcode que vai ser executado novamente
//             //ele já havia sido deslocado para o próximo opcode pela função getNBytes
//             frame->pc -= 3;
//             return;
//         }

//         //cria o frame no topo da pilha
//         fs->addFrame(
//             instance->getStatic()->getDef()->getMethod(name,desc),
//             instance->getStatic()->getDef()->get_classThatHasSerachedMethod(name,desc)->getCP()
//         );
//         //adiciona os parâmetros ao vetor de variáveis locais
//         fs->setArguments(parametros);
//     }
// }

// void Operations::invokestatic() {
//     frame *auxFrame = threads->top();
//     uint16_t indexbyte = get_n_bytes_value(2, frame->pc);
//     Cp_info cp_Element = frame->cp_vector[indexbyte];

//     if(cp_Element.tag != METHOD_REF)
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para METHOD_REF!");

//     string class_name = Displayer::dereference_index(frame->cp_vector, cp_Element.info[0].u2);
//     Cp_info name_and_type_Element = frame->cp_vector[cp_Element.info[1].u2];

//     if(name_and_type_Element.tag != NAME_AND_TYPE) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para NAME_AND_TYPE!");
//     }

//     string name = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[0].u2);
//     string descriptor = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[1].u2);

//     if (class_name == "java/lang/Object" && name == "registerNatives") {
//         frame->pc += 3;
//         return;
//     }

//     if (class_name.find("java/") != string::npos) {
//         cerr << "Tentando invocar metodo estatico invalido: " << name << endl;
//     }
//     else {
//         uint16_t nargs = 0; // numero de argumentos contidos na pilha de operandos
//         uint16_t i = 1; // pulando o primeiro '('
//         while (descriptor[i] != ')') {
//             char baseType = descriptor[i];
//             if (baseType == 'D' || baseType == 'J') {
//                 nargs += 2;
//             } else if (baseType == 'L') {
//                 nargs++;
//                 while (descriptor[++i] != ';');
//             } else if (baseType == '[') {
//                 nargs++;
//                 while (descriptor[++i] == '[');
//                 if (descriptor[i] == 'L') while (descriptor[++i] != ';');
//             } else {
//                 nargs++;
//             }
//             i++;
//         }

//         vector<Typed_element> args;
//         for (int i = 0; i < nargs; i++) {
//             Typed_element Elemento = frame->operand_stack->pop_typed_element();
//             args.insert(args.begin(), Elemento);
//         }

//         Static_class *ce = Method_area::get_class(class_name);

//         // Caso <clinit> seja empilhado.
//         if (threads->top() != auxFrame) {
//             //empilha de volta os operandos desempilhados na ordem contrária que saíram
//             while (nargs-- > 0) {
//                 frame->operand_stack->push_type(args[nargs]);
//             }
//             //volta com o pc para o opcode que vai ser executado novamente
//             //ele já havia sido deslocado para o próximo opcode pela função getNBytes
//             frame->pc -= 3;
//             return;
//         }

//         //cria o frame no topo da pilha
//         fs->addFrame(
//             ce->getDef()->getMethod(name,descriptor),
//             ce->getDef()->get_classThatHasSerachedMethod(name,descriptor)->getCP()
//         );

//         //adiciona os parâmetros ao vetor de variáveis locais
//         fs->setArguments(args);

//     }

// }

// void Operations::invokeinterface() {
//     frame *auxFrame = threads->top();
//     uint16_t indexbyte = get_n_bytes_value(2, frame->pc);
//     Cp_info cp_Element = frame->cp_vector[indexbyte];

//     if (cp_Element.tag != INTERFACE_REF){
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para INTERFACE_REF!");
//     }

//     string class_name = Displayer::dereference_index(frame->cp_vector, cp_Element.info[0].u2);
//     Cp_info name_and_type_Element = frame->cp_vector[cp_Element.info[1].u2];
//     if(name_and_type_Element.tag != NAME_AND_TYPE) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para NAME_AND_TYPE!");
//     }

//     string name = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[0].u2);
//     string descriptor = Displayer::dereference_index(frame->cp_vector, name_and_type_Element.info[1].u2);

//     if (class_name.find("java/") != string::npos) {
//         throw std::runtime_error("Tentativa de invocar metodo de interface invalido!");
//     } else {
//         uint16_t num_args = 0; //numero de argumentos na pilha de operandos
//         uint16_t i = 1; //pulando primeiro argumento '('
//         while (descriptor[i] != ')') {
//             char baseType = descriptor[i];
//             if (baseType == 'D' || baseType == 'J') {      //64 bits
//                 num_args += 2;
//             } else if (baseType == 'L') {                  //referencia - instancia de class
//                 num_args++;
//                 while (descriptor[++i] != ';');
//             } else if (baseType == '[') {                  // referencia
//                 num_args++;
//                 while (descriptor[++i] == '[');
//                 if (descriptor[i] == 'L') while (descriptor[++i] != ';');
//             } else {
//                 num_args++;
//             }
//             i++;
//         }

//         vector<Typed_element> parametros;
//         for (int i = 0; i < num_args; i++) {
//             Typed_element Elemento = frame->operand_stack->pop_typed_element();
//             parametros.insert(parametros.begin(), Elemento);
//         }

//         Typed_element typed_element = frame->operand_stack->pop_typed_element();
//         if (typed_element.type != TYPE_REFERENCE){
//             throw std::runtime_error("Elemento do topo da pilha não e uma referencia!");
//         }
//         parametros.insert(parametros.begin(), typed_element);

//         Instance_class *instance = (Instance_class *) object_typed_element.value.pi;

//         // Caso <clinit> seja empilhado.
//         if (threads->top() != auxFrame) {
//             //empilha de volta os operandos desempilhados na ordem contrária que saíram
//             while (num_args-- > 0) {
//                 frame->operand_stack->push_type(parametros[num_args]);
//             }
//             //volta com o pc para o opcode que vai ser executado novamente
//             //ele já havia sido deslocado para o próximo opcode pela função getNBytes
//             frame->pc -= 3;
//             return;
//         }
//         //cria o frame no topo da pilha
//         fs->addFrame(
//             instance->getStatic()->getDef()->getMethod(name,descriptor),
//             instance->getStatic()->getDef()->get_classThatHasSerachedMethod(name,descriptor)->getCP()
//         );
//         //adiciona os parâmetros ao vetor de variáveis locais
//         fs->setArguments(parametros);
//     }
// }

// void Operations::func_new(){
//     uint16_t indexbyte = get_n_bytes_value(2, frame->pc);
//     string classe = Displayer::dereference_index(frame->cp_vector, indexbyte);
//     Static_class *aux =  Method_area::get_class(classe);

//     if (aux == nullptr) {
//         Method_area::addClass(classe);
//         aux = Method_area::get_class(classe);
//     }

//     frame->operand_stack->push_type((int*)aux->getInstance());
// }

// void Operations::newarray(){
//     uint8_t type = get_n_bytes_value(1, frame->pc);
//     int32_t index = frame->operand_stack->pop().is;

//     if (index < 0)
//         throw std::runtime_error("Negative Array Size.");

//     int *array;

//     switch(type){
//         case 4:
//         array = (int*) new Local_variable(index);
//         break;
//         case 5:
//         array = (int*) new std::vector<uint8_t>(index);
//         break;
//         case 6:
//         array = (int*) new Local_variable(index);
//         break;
//         case 7:
//         array = (int*) new Local_variable(2*index, true);
//         break;
//         case 8:
//         array = (int*) new Local_variable(index);
//         break;
//         case 9:
//         array = (int*) new Local_variable(index);
//         break;
//         case 10:
//         array = (int*) malloc(sizeof(index));
//         break;
//         case 11:
//         array = (int*) new Local_variable(2*index, true);
//         break;
//         default:
//         array = (int*) new Local_variable(index);
//         break;
//     }
//     cout << array << endl;
//     frame->operand_stack->push_type(array);
// }

// void Operations::anewarray() {
//     uint16_t indexbyte = get_n_bytes_value(2, frame->pc);
//     int32_t count = frame->operand_stack->pop().is;

//     if (count < 0)
//         throw std::runtime_error("Negative Array Size.");

//     Local_variable *array = new Local_variable(count * (BITS ? 2:1), BITS);
//     for (int i = 0; i < count; i++) {
//         Typed_element aux;
//         aux.type = TYPE_REFERENCE;
//         aux.value.pi = nullptr;
//         array->insert_typed_element(i, aux);
//     }

//     frame->operand_stack->push_type((int*)array);
// }

// void Operations::arraylength()
// {
//     Local_variable *arrayref;

//     arrayref = (Local_variable *) frame->operand_stack->pop().pi;
//     if (arrayref == nullptr)
//         throw runtime_error("Null pointer");

//     frame->operand_stack->push_type(arrayreframe->getMax());
// }

// void Operations::athrow()
// {
//     int type = frame->operand_stack->top_type();
//     Element value = frame->operand_stack->pop();

//     while (!frame->operand_stack->empty()) {
//         frame->operand_stack->pop();
//     }

//     frame->operand_stack->push_type(value, type);
// }

// //Fim linha 11
// //Inicio linha 12

// void Operations::wide() {
// 	//seta a variavel global wide -> TRUE
// 	is_wide = true;
// 	Operations::run(get_n_bytes_value(1, frame->pc));
// }

// //terminar
// void Operations::multianewarray(){

// 	uint16_t indexbyte = get_n_bytes_value(2, frame->pc);
// 	uint8_t dimensions = get_n_bytes_value(1, frame->pc);

//     Cp_info cp_Element = frame->cp_vector[indexbyte];
//     if(cp_Element.tag != CLASS) {
//         throw std::runtime_error("Elemento da constant pool apontado por index, não é uma referencia para CLASS!");
//     }

//     string class_name = Displayer::dereference_index(frame->cp_vector, cp_Element.info[0].u2);

//     Typed_element Element;

//     int count = 0;

// 	   while (class_name[count] == '[')
// 	   {
// 	   		count++;
// 	   }

// 	   string multiArrayType = class_name.substr(count+1, class_name.size()-count-2); // em caso de ser uma referência (e.g. [[[Ljava/lang/String;)

// 	   switch (class_name[count]) {
// 	       case 'L':
// 	           if (multiArrayType != "java/lang/String") {
// 	               Method_area::get_class(multiArrayType); // verifica se existe classe com esse nome
// 	           }
// 	           typed_element.real_type = RT_REFERENCE;
// 	           Element.type = TYPE_REFERENCE;
// 	           break;
// 	       case 'B':
// 	           typed_element.real_type = RT_BYTE;
// 	           Element.type = TYPE_INT;
// 	           break;
// 	       case 'C':
// 	           typed_element.real_type = RT_CHAR;
// 	           Element.type = TYPE_INT;
// 	           break;
// 	       case 'D':
// 	           typed_element.real_type = RT_DOUBLE;
// 	           Element.type = TYPE_DOUBLE;
// 	           break;
// 	       case 'F':
// 	           typed_element.real_type = RT_FLOAT;
// 	           Element.type = TYPE_FLOAT;
// 	           break;
// 	       case 'I':
// 	           typed_element.real_type = RT_INT;
// 	           Element.type = TYPE_INT;
// 	           break;
// 	       case 'J':
// 	           typed_element.real_type = RT_LONG;
// 	           Element.type = TYPE_LONG;
// 	           break;
// 	       case 'S':
// 	           typed_element.real_type = RT_SHORT;
// 	           Element.type = TYPE_INT;
// 	           break;
// 	       case 'Z':
// 	           typed_element.real_type = RT_BOOL;
// 	           Element.type = TYPE_INT;
// 	           break;
// 	       default:
// 	           exit(1);
// 	   }

//     stack<int> count_dim;
//     for (int i = 0; i < dimensions; i++) {
//         // PRECISO VERIFICAR O TIPO (INT)?
//         count_dim.push(frame->operand_stack->pop_typed_element().value.i);
//     }

// 	int* p = (int*)(getNewMultiArray(count_dim));

// 	typed_element.value.pi = p;

// 	frame->operand_stack->push_type(Element);

// }

// double Operations::getValue(n_array array, stack<int> access_indexes)
// {
// 	int index = 1;
// 	int aux = 0;

// 	for(int i = 0 ; i < sizeof(array.dims)/sizeof(*(array.dims)); i++)
// 	{
// 		aux += array.dims[i] * access_indexes.top();

// 		index = (aux * index) + aux;
// 		access_indexes.pop();
// 	}

// 	return array.array[index];

// }

// n_array *Operations::getNewMultiArray(stack<int> count_dim)
// {
// 	int size = 1;
// 	int value;

// 	n_array *array = (n_array*) malloc(sizeof(n_array)) ;

// 	int* dims = (int*) malloc(sizeof(double) * count_dim.size());

// 	for(int i = 0; count_dim.size() > 0; i++) {

// 		value = count_dim.top();
// 		size *= value;
// 		dims[i] = value;
// 		count_dim.pop();
// 	}

// 	int* p = (int*) malloc(sizeof(double) * size);

// 	for(int i = 0; i < size; i++)
// 	{
// 		p[i] = 0;
// 	}

// 	array->dims = dims;
// 	array->array = p;

// 	return array;

// }

// void Operations::ifnull(){
// 	int* ref = frame->operand_stack->pop().pi;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	if (ref == nullptr)
// 		frame->pc += branchbyte - 3;
// }

// void Operations::ifnonnull(){
// 	int* ref = frame->operand_stack->pop().pi;
// 	int16_t branchbyte = int16_t(get_n_bytes_value(2, frame->pc));

// 	if (ref != nullptr)
// 		frame->pc += branchbyte - 3;
// }

// void Operations::goto_w(){
// 	int32_t branchbyte = int32_t(get_n_bytes_value(4, frame->pc));

// 	frame->pc += branchbyte - 5;
// }

// void Operations::jsr_w(){
// 	int32_t offset = int32_t(get_n_bytes_value(4, frame->pc));

// 	frame->operand_stack->push_type(frame->pc);

// 	frame->pc += offset - 5;
// }

// //Fim linha 12
// //Opcionais

// void Operations::dup() {
// 	Typed_element value = frame->operand_stack->pop_typed_element();
// 	frame->operand_stack->push_type(value);
// 	frame->operand_stack->push_type(value);
// }

// void Operations::pop() {
// 	frame->operand_stack->pop_typed_element();
// }

// void Operations::pop2() {
// 	Typed_element aux = frame->operand_stack->pop_typed_element();
// 	if (aux.type == TYPE_LONG || aux.type == TYPE_DOUBLE) {
// 		frame->operand_stack->pop_typed_element();
// 	}
// }

// void Operations::dup_x1() {
// 	if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
// 		Typed_element aux = frame->operand_stack->pop_typed_element();
// 		if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
// 			frame->operand_stack->pop_typed_element();
// 		} else {
// 			frame->operand_stack->push_type(aux);
// 		}
// 	}
// }

// void Operations::dup_x2() {
// 	Typed_element aux = frame->operand_stack->pop_typed_element();
// 	if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
// 		Typed_element aux2 = frame->operand_stack->pop_typed_element(), aux3 = frame->operand_stack->pop_typed_element();
// 		frame->operand_stack->push_type(aux);
// 		frame->operand_stack->push_type(aux3);
// 		frame->operand_stack->push_type(aux2);
// 		frame->operand_stack->push_type(aux);
// 	} else {
// 		Typed_element aux2 = frame->operand_stack->pop_typed_element();
// 		frame->operand_stack->push_type(aux);
// 		frame->operand_stack->push_type(aux2);
// 		frame->operand_stack->push_type(aux);
// 	}
// }

// void Operations::dup2() {
// 	Typed_element aux = frame->operand_stack->pop_typed_element();

// 	if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
// 		Typed_element aux2 = frame->operand_stack->pop_typed_element();
// 		frame->operand_stack->push_type(aux2);
// 		frame->operand_stack->push_type(aux);
// 		frame->operand_stack->push_type(aux2);
// 		frame->operand_stack->push_type(aux);
// 	} else {
// 		frame->operand_stack->push_type(aux);
// 		frame->operand_stack->push_type(aux);
// 	}
// }

// void Operations::dup2_x1() {
// 	Typed_element aux = frame->operand_stack->pop_typed_element();

// 	if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
// 		Typed_element aux2 = frame->operand_stack->pop_typed_element(), aux3 = frame->operand_stack->pop_typed_element();
// 		frame->operand_stack->push_type(aux2);
// 		frame->operand_stack->push_type(aux);
// 		frame->operand_stack->push_type(aux3);
// 		frame->operand_stack->push_type(aux2);
// 		frame->operand_stack->push_type(aux);
// 	} else {
// 		Typed_element aux2 = frame->operand_stack->pop_typed_element();
// 		frame->operand_stack->push_type(aux);
// 		frame->operand_stack->push_type(aux2);
// 		frame->operand_stack->push_type(aux);
// 	}
// }

// void Operations::dup2_x2() {
// 	Typed_element aux = frame->operand_stack->pop_typed_element();

// 	if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
// 		Typed_element aux2 = frame->operand_stack->pop_typed_element(), aux3 = frame->operand_stack->pop_typed_element();
// 		if (aux3.type == TYPE_LONG || aux3.type == TYPE_DOUBLE) {
// 			frame->operand_stack->push_type(aux2);
// 			frame->operand_stack->push_type(aux);
// 			frame->operand_stack->push_type(aux3);
// 			frame->operand_stack->push_type(aux2);
// 			frame->operand_stack->push_type(aux);
// 		} else {
// 			Typed_element aux4 = frame->operand_stack->pop_typed_element();
// 			frame->operand_stack->push_type(aux2);
// 			frame->operand_stack->push_type(aux);
// 			frame->operand_stack->push_type(aux4);
// 			frame->operand_stack->push_type(aux3);
// 			frame->operand_stack->push_type(aux2);
// 			frame->operand_stack->push_type(aux);
// 		}
// 	} else {
// 		Typed_element aux2 = frame->operand_stack->pop_typed_element();
// 		if (aux2.type == TYPE_LONG || aux2.type == TYPE_DOUBLE) {
// 			frame->operand_stack->push_type(aux);
// 			frame->operand_stack->push_type(aux2);
// 			frame->operand_stack->push_type(aux);
// 		} else {
// 			Typed_element aux3 = frame->operand_stack->pop_typed_element();
// 			frame->operand_stack->push_type(aux);
// 			frame->operand_stack->push_type(aux3);
// 			frame->operand_stack->push_type(aux2);
// 			frame->operand_stack->push_type(aux);
// 		}
// 	}
// }

// void Operations::swap() {
// 	Typed_element aux = frame->operand_stack->pop_typed_element(), aux2 = frame->operand_stack->pop_typed_element();
// 	frame->operand_stack->push_type(aux);
// 	frame->operand_stack->push_type(aux2);
// }

void Operations::lload_n(short index)
{
}

void Operations::fload_n(short index)
{
}

void Operations::dload_n(short index)
{
}

void Operations::aload_n(short index)
{
}

void Operations::nop()
{
}

void Operations::aconst_null()
{
}

void Operations::iconst_m1()
{
}

void Operations::iconst_0()
{
}

void Operations::iconst_1()
{
}

void Operations::iconst_2()
{
}

void Operations::iconst_3()
{
}

void Operations::iconst_4()
{
}

void Operations::iconst_5()
{
}

void Operations::lconst_0()
{
}

void Operations::lconst_1()
{
}

void Operations::fconst_0()
{
}

void Operations::fconst_1()
{
}

void Operations::fconst_2()
{
}

void Operations::dconst_0()
{
}

void Operations::dconst_1()
{
}

void Operations::bipush()
{
}

void Operations::sipush()
{
}

void Operations::ldc()
{
}

void Operations::ldc_w()
{
}

void Operations::ldc2_w()
{
}

void Operations::iload()
{
}

void Operations::lload()
{
}

void Operations::fload()
{
}

void Operations::dload()
{
}

void Operations::aload()
{
}

void Operations::iload_0()
{
}

void Operations::iload_1()
{
}

void Operations::iload_2()
{
}

void Operations::iload_3()
{
}

void Operations::lload_0()
{
}

void Operations::lload_1()
{
}

void Operations::lload_2()
{
}

void Operations::lload_3()
{
}

void Operations::fload_0()
{
}

void Operations::fload_1()
{
}

void Operations::fload_2()
{
}

void Operations::fload_3()
{
}

void Operations::dload_0()
{
}

void Operations::dload_1()
{
}

void Operations::dload_2()
{
}

void Operations::dload_3()
{
}

void Operations::aload_0()
{
}

void Operations::aload_1()
{
}

void Operations::aload_2()
{
}

void Operations::aload_3()
{
}

void Operations::iaload()
{
}

void Operations::laload()
{
}

void Operations::faload()
{
}

void Operations::daload()
{
}

void Operations::aaload()
{
}

void Operations::baload()
{
}

void Operations::caload()
{
}

void Operations::saload()
{
}

void Operations::istore()
{
}

void Operations::lstore()
{
}

void Operations::fstore()
{
}

void Operations::dstore()
{
}

void Operations::astore()
{
}

void Operations::istore_1()
{
}

void Operations::istore_2()
{
}

void Operations::istore_3()
{
}

void Operations::istore_0()
{
}

void Operations::lstore_0()
{
}

void Operations::lstore_1()
{
}

void Operations::lstore_2()
{
}

void Operations::lstore_3()
{
}

void Operations::fstore_0()
{
}

void Operations::fstore_1()
{
}

void Operations::fstore_2()
{
}

void Operations::fstore_3()
{
}

void Operations::dstore_0()
{
}

void Operations::dstore_1()
{
}

void Operations::dstore_2()
{
}

void Operations::dstore_3()
{
}

void Operations::astore_0()
{
}

void Operations::astore_1()
{
}

void Operations::astore_2()
{
}

void Operations::astore_3()
{
}

void Operations::iastore()
{
}

void Operations::lastore()
{
}

void Operations::fastore()
{
}

void Operations::dastore()
{
}

void Operations::aastore()
{
}

void Operations::bastore()
{
}

void Operations::castore()
{
}

void Operations::sastore()
{
}

void Operations::pop()
{
}

void Operations::pop2()
{
}

void Operations::dup()
{
}

void Operations::dup_x1()
{
}

void Operations::dup_x2()
{
}

void Operations::dup2()
{
}

void Operations::dup2_x1()
{
}

void Operations::dup2_x2()
{
}

void Operations::swap()
{
}

void Operations::iadd()
{
}

void Operations::ladd()
{
}

void Operations::fadd()
{
}

void Operations::dadd()
{
}

void Operations::isub()
{
}

void Operations::lsub()
{
}

void Operations::fsub()
{
}

void Operations::dsub()
{
}

void Operations::imul()
{
}

void Operations::lmul()
{
}

void Operations::fmul()
{
}

void Operations::dmul()
{
}

void Operations::idiv()
{
}

void Operations::ldiv()
{
}

void Operations::fdiv()
{
}

void Operations::ddiv()
{
}

void Operations::irem()
{
}

void Operations::lrem()
{
}

void Operations::frem()
{
}

void Operations::drem()
{
}

void Operations::ineg()
{
}

void Operations::lneg()
{
}

void Operations::fneg()
{
}

void Operations::dneg()
{
}

void Operations::ishl()
{
}

void Operations::lshl()
{
}

void Operations::ishr()
{
}

void Operations::lshr()
{
}

void Operations::iushr()
{
}

void Operations::lushr()
{
}

void Operations::iand()
{
}

void Operations::land()
{
}

void Operations::ior()
{
}

void Operations::lor()
{
}

void Operations::ixor()
{
}

void Operations::lxor()
{
}

void Operations::iinc()
{
}

void Operations::i2l()
{
}

void Operations::i2f()
{
}

void Operations::i2d()
{
}

void Operations::l2i()
{
}

void Operations::l2f()
{
}

void Operations::l2d()
{
}

void Operations::f2i()
{
}

void Operations::f2l()
{
}

void Operations::f2d()
{
}

void Operations::d2i()
{
}

void Operations::d2l()
{
}

void Operations::d2f()
{
}

void Operations::i2b()
{
}

void Operations::i2c()
{
}

void Operations::i2s()
{
}

void Operations::lcmp()
{
}

void Operations::fcmpl()
{
}

void Operations::fcmpg()
{
}

void Operations::dcmpl()
{
}

void Operations::dcmpg()
{
}

void Operations::ifeq()
{
}

void Operations::ifne()
{
}

void Operations::iflt()
{
}

void Operations::ifge()
{
}

void Operations::ifgt()
{
}

void Operations::ifle()
{
}

void Operations::if_icmpeq()
{
}

void Operations::if_icmpne()
{
}

void Operations::if_icmplt()
{
}

void Operations::if_icmpge()
{
}

void Operations::if_icmpgt()
{
}

void Operations::if_icmple()
{
}

void Operations::if_acmpeq()
{
}

void Operations::if_acmpne()
{
}

void Operations::funcgoto()
{
}

void Operations::jsr()
{
}

void Operations::funcret()
{
}

void Operations::tableswitch()
{
}

void Operations::lookupswitch()
{
}

void Operations::ireturn()
{
}

void Operations::lreturn()
{
}

void Operations::freturn()
{
}

void Operations::dreturn()
{
}

void Operations::areturn()
{
}

void Operations::func_return()
{
}

void Operations::getstatic()
{
}

void Operations::putstatic()
{
}

void Operations::getfield()
{
}

void Operations::putfield()
{
}

void Operations::invokevirtual()
{
}

void Operations::invokespecial()
{
}

void Operations::invokestatic()
{
}

void Operations::invokeinterface()
{
}

void Operations::func_new()
{
}

void Operations::newarray()
{
}

void Operations::anewarray()
{
}

void Operations::arraylength()
{
}

void Operations::athrow()
{
}

void Operations::wide()
{
}

void Operations::multianewarray()
{
}

void Operations::ifnull()
{
}

void Operations::ifnonnull()
{
}

void Operations::goto_w()
{
}

void Operations::jsr_w()
{
}
