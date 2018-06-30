#include "Operations.hpp"

using namespace std;

Frame* Operations::frame = new Frame();
stack<Frame*>* Operations::threads = nullptr;
Frame_stack* Operations::frame_stack = nullptr;
bool Operations::is_wide = false;


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
    &Operations::goto_w, &Operations::jsr_w};// testar no final, &Operations::nop, &Operations::impdep1, &Operations::impdep2 

// Operations::Operations(Frame* ref) {
// 	frame = ref;
// }

U4 Operations::get_n_bytes_value(uint8_t n, vector<U2> pc){
  U4 value = pc[frame->current_pc_index];
  frame->current_pc_index++;
  for(int i = 1; i < n; i++){
    value = (value << 8) | pc[frame->current_pc_index];
    frame->current_pc_index++;
  }
  return value;
}

Static_class* Operations::get_static_class_with_field(Static_class* base, string field_name) {
    Typed_element ret = base->get_field(field_name);
    if(ret.type != TYPE_NOT_SET) {
        return base;
    }

    int cp_index = base->reader_class->super_class;
    if( cp_index == 0 ) {
        return NULL;
    }

    Static_class* child = Method_area::get_class(Displayer::dereference_index(base->reader_class->cp->cp_vector, cp_index));
    return get_static_class_with_field(child, field_name); 

}


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

void Operations::lload_n(short index)
{
    Typed_element aux = frame->local_variables->get_typed_element(index);
	frame->operand_stack->push_type(long(aux.value.l));
}

void Operations::fload_n(short index)
{
    Typed_element aux = frame->local_variables->get_typed_element(index);
	frame->operand_stack->push_type(aux.value.f);
}

void Operations::dload_n(short index)
{
    Typed_element aux = frame->local_variables->get_typed_element(index);
	frame->operand_stack->push_type(aux.value.d);
}

void Operations::aload_n(short index)
{
    Typed_element aux = frame->local_variables->get_typed_element(index);
	frame->operand_stack->push_type(aux.value.pi);
}

void Operations::nop()
{
}

void Operations::aconst_null()
{
    frame->operand_stack->push_type((int*)(nullptr));
}

void Operations::iconst_m1()
{
    frame->operand_stack->push_type(int(-1));

}

void Operations::iconst_0()
{
    frame->operand_stack->push_type(int(0));
}

void Operations::iconst_1()
{
    frame->operand_stack->push_type(int(1));
}

void Operations::iconst_2()
{
    frame->operand_stack->push_type(int(2));
}

void Operations::iconst_3()
{
    frame->operand_stack->push_type(int(3));
}

void Operations::iconst_4()
{
    frame->operand_stack->push_type(int(4));
}

void Operations::iconst_5()
{
    frame->operand_stack->push_type(int(5));
}

void Operations::lconst_0()
{
    frame->operand_stack->push_type(long(0));
}

void Operations::lconst_1()
{
    frame->operand_stack->push_type(long(1));
}

void Operations::fconst_0()
{
    frame->operand_stack->push_type(float(0.0));
}

void Operations::fconst_1()
{
    frame->operand_stack->push_type(float(1.0));
}

void Operations::fconst_2()
{
    frame->operand_stack->push_type(float(2.0));
}

void Operations::dconst_0()
{
    frame->operand_stack->push_type(double(0.0));
}

void Operations::dconst_1()
{
    frame->operand_stack->push_type(double(1.0));
}

void Operations::bipush()
{
    int32_t aux;
	int8_t byte = get_n_bytes_value(1, frame->pc);
	aux = (int32_t) (int8_t) byte; // extendendo o sinal
	frame->operand_stack->push_type(int(aux));
}

void Operations::sipush()
{
    uint16_t val_short;
	int32_t val_push_short;
	val_short = get_n_bytes_value(2, frame->pc);
	val_push_short = (int32_t) (int16_t) val_push_short;  // extendendo o sinal
	frame->operand_stack->push_type(int(val_push_short));
}

void Operations::ldc()
{
    // Arrumar array antes de implementar essa função
}

void Operations::ldc_w()
{

}

void Operations::ldc2_w()
{
    uint8_t index = get_n_bytes_value(2, frame->pc);
	long val_push_long;
	double val_push_double; 
	if (frame->cp_vector[index].tag == LONG){
		val_push_long = Displayer::u4_to_long(frame->cp_vector[index].info[0].u4, frame->cp_vector[index+1].info[0].u4);
		frame->operand_stack->push_type(long(val_push_long));
	} else {
		val_push_double = Displayer::u4_to_double(frame->cp_vector[index].info[0].u4, frame->cp_vector[index+1].info[0].u4);
		frame->operand_stack->push_type(double(val_push_double));
	}
}

void Operations::iload()
{
    uint16_t index = 0;

	if (is_wide){
		index = get_n_bytes_value(2, frame->pc);
		is_wide = false;
	} else {
		index = get_n_bytes_value(1, frame->pc);
	}
	
	Typed_element aux = frame->local_variables->get_typed_element(int(index));
	frame->operand_stack->push_type(int(aux.value.i));
}

void Operations::lload()
{
    uint16_t index = 0;
	if (is_wide) {
		index = get_n_bytes_value(2, frame->pc);
		is_wide = false;
	}else
		index = get_n_bytes_value(1, frame->pc);
	
	Typed_element aux = frame->local_variables->get_typed_element(int(index));
	frame->operand_stack->push_type(long(aux.value.l));
}

void Operations::fload()
{
    uint16_t index = 0;

	if (is_wide) {
		index = get_n_bytes_value(2, frame->pc);
		is_wide = false;
	}else
		index = get_n_bytes_value(1, frame->pc);
	
	Typed_element aux = frame->local_variables->get_typed_element(int(index));
	frame->operand_stack->push_type(float(aux.value.f));
}

void Operations::dload()
{
    uint16_t index;

	if (is_wide) {
		index = get_n_bytes_value(2, frame->pc);
		is_wide = false;
	} else
		index = get_n_bytes_value(1, frame->pc);
	
	Typed_element aux = frame->local_variables->get_typed_element(int(index));
	frame->operand_stack->push_type(double(aux.value.d));
}

void Operations::aload()
{
    uint16_t index = 0;

	if (is_wide) {
		index = get_n_bytes_value(2, frame->pc);
		is_wide = false;
	}else
		index = get_n_bytes_value(1, frame->pc);
	
	Typed_element aux = frame->local_variables->get_typed_element(int(index));
	frame->operand_stack->push_type((int*)(aux.value.pi));
}

void Operations::iload_0()
{
    Typed_element aux = frame->local_variables->get_typed_element(0);
	frame->operand_stack->push_type(int(aux.value.i));
}

void Operations::iload_1()
{
    Typed_element aux = frame->local_variables->get_typed_element(1);
	frame->operand_stack->push_type(int(aux.value.i));
}

void Operations::iload_2()
{
    Typed_element aux = frame->local_variables->get_typed_element(2);
	frame->operand_stack->push_type(int(aux.value.i));
}

void Operations::iload_3()
{
    Typed_element aux = frame->local_variables->get_typed_element(3);
	frame->operand_stack->push_type(int(aux.value.i));
}

void Operations::lload_0()
{
    lload_n(0);
}

void Operations::lload_1()
{
    lload_n(1);
}

void Operations::lload_2()
{
    lload_n(2);
}

void Operations::lload_3()
{
    lload_n(3);
}

void Operations::fload_0()
{
    fload_n(0);
}

void Operations::fload_1()
{
    fload_n(1);
}

void Operations::fload_2()
{
    fload_n(2);
}

void Operations::fload_3()
{
    fload_n(3);
}

void Operations::dload_0()
{
    dload_n(0);
}

void Operations::dload_1()
{
    dload_n(1);
}

void Operations::dload_2()
{
    dload_n(2);
}

void Operations::dload_3()
{
    dload_n(3);
}

void Operations::aload_0()
{
    aload_n(0);
}

void Operations::aload_1()
{
    aload_n(1);
}

void Operations::aload_2()
{
    aload_n(2);
}

void Operations::aload_3()
{
    aload_n(3);
}

void Operations::iaload()
{
    Element value1, value2;

	value1 = frame->operand_stack->pop_element();
  	value2 = frame->operand_stack->pop_element();
  	int *ref = value2.pi;

  	if (ref == nullptr)
    	throw runtime_error("Null pointer");
	frame->operand_stack->push_type(ref[value1.i]);
}

void Operations::laload()
{
    Element value1, value2;
	Typed_element result;

	value1 = frame->operand_stack->pop_element();
  	value2 = frame->operand_stack->pop_element();
  	Local_variable *ref = (Local_variable *) value2.pi;
  	if (ref == nullptr)
    	throw runtime_error("Null pointer");

	frame->operand_stack->push_type(ref->get_typed_element(value1.i));
}

void Operations::faload()
{
    int index = frame->operand_stack->pop_element().i;
	Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop_element().pi;
	
    // if(arrayref == NULL){
	// }
    
	frame->operand_stack->push_type(arrayref->get_typed_element(index));
}

void Operations::daload()
{
    int index = frame->operand_stack->pop_element().i;
	Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop_element().pi;
	frame->operand_stack->push_type(arrayref->get_typed_element(index));
}

void Operations::aaload()
{
    int index = frame->operand_stack->pop_element().i;
	Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop_element().pi;
	frame->operand_stack->push_type(arrayref->get_typed_element(index));
}

void Operations::baload()
{
    int index = frame->operand_stack->pop_element().i;
	Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop_element().pi;
	frame->operand_stack->push_type(arrayref->get_typed_element(index));
}

void Operations::caload()
{
    int index = frame->operand_stack->pop_element().i;
	std::vector<char> *arrayref = (std::vector<char> *) frame->operand_stack->pop_element().pi;
	frame->operand_stack->push_type(arrayref->at(index));
}

void Operations::saload()
{
    int index = frame->operand_stack->pop_element().i;
	Local_variable *arrayref = (Local_variable *) frame->operand_stack->pop_element().pi;
	frame->operand_stack->push_type(arrayref->get_typed_element(index));
}

void Operations::istore()
{
    uint16_t index = 0;

	if (is_wide) {
		index = get_n_bytes_value(2, frame->pc);
		is_wide = false;
	}else
		index = get_n_bytes_value(1, frame->pc);   

	if(frame->operand_stack->top_type() == TYPE_INT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, index);
	}
	else
		printf("Operando no topo != TYPE_INT\n");
}

void Operations::istore_0()
{
    if(frame->operand_stack->top_type() == TYPE_INT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux,0);
	}
	else
		printf("Operando no topo != TYPE_INT\n");
}

void Operations::istore_1()
{
    if(frame->operand_stack->top_type() == TYPE_INT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux,1);
	}
	else
		printf("Operando no topo != TYPE_INT\n");
}

void Operations::istore_2()
{
    if(frame->operand_stack->top_type() == TYPE_INT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux,2);
	}
	else
		printf("Operando no topo != TYPE_INT\n");
}

void Operations::istore_3()
{
    if(frame->operand_stack->top_type() == TYPE_INT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux,3);
	}
	else
		printf("Operando no topo != TYPE_INT\n");
}

void Operations::lstore()
{
    if(frame->operand_stack->top_type() == TYPE_LONG) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 1);
	}
	else
		printf("Operando no topo != TYPE_LONG\n");
}

void Operations::lstore_0()
{
    Typed_element var = frame->operand_stack->pop_typed_element();
	if(var.type == TYPE_LONG) {
		frame->local_variables->insert_typed_element(var,0);
	}
	else
		printf("Operando no topo != TYPE_LONG\n");
}

void Operations::lstore_1()
{
    if(frame->operand_stack->top_type() == TYPE_LONG) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 1);
	}
	else
		printf("Operando no topo != TYPE_LONG\n");
}

void Operations::lstore_2()
{
    if(frame->operand_stack->top_type() == TYPE_LONG) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 2);
	}
	else
		printf("Operando no topo != TYPE_LONG\n");
}

void Operations::lstore_3()
{
    if(frame->operand_stack->top_type() == TYPE_LONG) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 3);
	}
	else
		printf("Operando no topo != TYPE_LONG\n");
}

void Operations::fstore()
{
    uint16_t index = 0;

	if (is_wide) {
		index = get_n_bytes_value(2, frame->pc);
		is_wide = false;
	}else
		index = get_n_bytes_value(1, frame->pc); 
	
	if(frame->operand_stack->top_type() == TYPE_FLOAT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, index);
	}
	else
		printf("Operando no topo != TYPE_FLOAT\n");
}

void Operations::fstore_0()
{
    if(frame->operand_stack->top_type() == TYPE_FLOAT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 0);
	}
	else
		printf("Operando no topo != TYPE_FLOAT\n");
}

void Operations::fstore_1()
{
    if(frame->operand_stack->top_type() == TYPE_FLOAT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 1);
	}
	else
		printf("Operando no topo != TYPE_FLOAT\n");
}

void Operations::fstore_2()
{
    if(frame->operand_stack->top_type() == TYPE_FLOAT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 2);
	}
	else
		printf("Operando no topo != TYPE_FLOAT\n");
}

void Operations::fstore_3()
{
    if(frame->operand_stack->top_type() == TYPE_FLOAT) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 3);
	}
	else
		printf("Operando no topo != TYPE_FLOAT\n");
}

void Operations::dstore()
{
    uint16_t index = 0;

	if (is_wide) {
		index = get_n_bytes_value(2, frame->pc);
		is_wide = false;
	} else
		index = get_n_bytes_value(1, frame->pc); 

	if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, index);
	}
	else
		printf("Operando no topo != TYPE_DOUBLE\n");
}

void Operations::dstore_0()
{
    if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 0);
	}
	else
		printf("Operando no topo != TYPE_DOUBLE\n");
}

void Operations::dstore_1()
{
    if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 1);
	}
	else
		printf("Operando no topo != TYPE_DOUBLE\n");
}

void Operations::dstore_2()
{
    if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 2);
	}
	else
		printf("Operando no topo != TYPE_DOUBLE\n");
}

void Operations::dstore_3()
{
    if(frame->operand_stack->top_type() == TYPE_DOUBLE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 3);
	}
	else
		printf("Operando no topo != TYPE_DOUBLE\n");
}

void Operations::astore()
{
    uint16_t index = 0;

   	if (is_wide) {
		index = get_n_bytes_value(2, frame->pc);
		is_wide = false;
	} else
		index = get_n_bytes_value(1, frame->pc); 

	if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, index);
	}
	else
		printf("Operando no topo != TYPE_REFERECE\n");
}

void Operations::astore_0()
{
    if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 0);
	}
	else
		printf("Operando no topo != TYPE_REFERENCE\n");
}

void Operations::astore_1()
{
    if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 1);
	}
	else
		printf("Operando no topo != TYPE_REFERENCE\n");
}

void Operations::astore_2()
{
    if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 2);
	}
	else
		printf("Operando no topo != TYPE_REFERENCE\n");
}

void Operations::astore_3()
{
    if(frame->operand_stack->top_type() == TYPE_REFERENCE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		frame->local_variables->insert_typed_element(aux, 3);
	}
	else
		printf("Operando no topo != TYPE_REFERENCE\n");
}

void Operations::iastore()
{
    Element value = frame->operand_stack->pop_element();
	Element index = frame->operand_stack->pop_element();
	int *vector = frame->operand_stack->pop_element().pi;

	// if(vector.pi == NULL)
	// 	throw(NullPointerException);
	// if(index < 0 || index >= (vector.pi).capacity())
	// 	throw(ArrayIndexOutOfBoundsException);

	if (vector == nullptr) throw std::runtime_error("NullPointerException");
		Typed_element aux;
		aux.value.i = value.i;
		aux.type = TYPE_INT;
		aux.real_type = RT_INT;
		vector[index.i] = value.i;
}

void Operations::lastore()
{
    Element value = frame->operand_stack->pop_element();
	Element index = frame->operand_stack->pop_element();
	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop_element().pi;
	
	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
		Typed_element aux;
		aux.value.l = value.l;
		aux.type = TYPE_LONG;
		aux.real_type = RT_LONG;
		vetor->insert_typed_element(aux, index.i);
}

void Operations::fastore()
{
    Element value = frame->operand_stack->pop_element();
	Element index = frame->operand_stack->pop_element();
	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop_element().pi;
	
	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
		Typed_element aux;
		aux.value.f = value.f;
		aux.type = TYPE_FLOAT;
		aux.real_type = RT_FLOAT;
		vetor->insert_typed_element(aux, index.i);
}

void Operations::dastore()
{
    Element value = frame->operand_stack->pop_element();
	Element index = frame->operand_stack->pop_element();
	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop_element().pi;
	
	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
		Typed_element aux;
		aux.value.d = value.d;
		aux.type = TYPE_DOUBLE;
		aux.real_type = RT_DOUBLE;
		vetor->insert_typed_element(aux,index.i);
}
//ve se ta errado
void Operations::aastore()
{
    Element value = frame->operand_stack->pop_element();
    Element index = frame->operand_stack->pop_element();
    Local_variable *vetor = (Local_variable *) frame->operand_stack->pop_element().pi;

    if (vetor == nullptr) throw std::runtime_error("NullPointerException");
        Typed_element aux;
		aux.value.pi = value.pi;
		aux.type = TYPE_REFERENCE;
		aux.real_type = RT_REFERENCE;
		vetor->insert_typed_element(aux, index.i);

}
//ve se ta errado
void Operations::bastore()
{
    Element value = frame->operand_stack->pop_element();
	Element index = frame->operand_stack->pop_element();
	Local_variable *vetor = (Local_variable *) frame->operand_stack->pop_element().pi;

	if (vetor == nullptr) throw std::runtime_error("NullPointerException");
		Typed_element aux;
		aux.value.i = value.i;
		aux.type = TYPE_INT;
		aux.real_type = RT_BOOL;
		vetor->insert_typed_element(aux, index.i);
    
}

void Operations::castore(){
    
    
}

void Operations::sastore()
{
    Element value = frame->operand_stack->pop_element();
	Element index = frame->operand_stack->pop_element();
	Local_variable *vector = (Local_variable *) frame->operand_stack->pop_element().pi;

	if (vector == nullptr) throw std::runtime_error("NullPointerException");
		Typed_element aux;
		aux.value.i = value.i;
		aux.type = TYPE_INT;
		aux.real_type = RT_SHORT;
		vector->insert_typed_element( aux,index.i);
	
}

void Operations::pop()
{
    frame->operand_stack->pop_typed_element();
}

void Operations::pop2()
{
    Typed_element aux = frame->operand_stack->pop_typed_element();
	if (aux.type == TYPE_LONG || aux.type == TYPE_DOUBLE) {
		frame->operand_stack->pop_typed_element();
	}
}

void Operations::dup()
{
    Typed_element value = frame->operand_stack->pop_typed_element();
	frame->operand_stack->push_type(value);
	frame->operand_stack->push_type(value);
}

void Operations::dup_x1()
{
    if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
		Typed_element aux = frame->operand_stack->pop_typed_element();
		if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
			frame->operand_stack->pop_typed_element();
		} else {
			frame->operand_stack->push_type(aux);
		}
	}
}

void Operations::dup_x2()
{
    Typed_element aux = frame->operand_stack->pop_typed_element();
	if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
		Typed_element aux2 = frame->operand_stack->pop_typed_element(), aux3 = frame->operand_stack->pop_typed_element();
		frame->operand_stack->push_type(aux);
		frame->operand_stack->push_type(aux3);
		frame->operand_stack->push_type(aux2);
		frame->operand_stack->push_type(aux);
	} else {
		Typed_element aux2 = frame->operand_stack->pop_typed_element();
		frame->operand_stack->push_type(aux);
		frame->operand_stack->push_type(aux2);
		frame->operand_stack->push_type(aux);
	}
}

void Operations::dup2()
{
    Typed_element aux = frame->operand_stack->pop_typed_element();

	if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
		Typed_element aux2 = frame->operand_stack->pop_typed_element();
		frame->operand_stack->push_type(aux2);
		frame->operand_stack->push_type(aux);
		frame->operand_stack->push_type(aux2);
		frame->operand_stack->push_type(aux);
	} else {
		frame->operand_stack->push_type(aux);
		frame->operand_stack->push_type(aux);
	}
}

void Operations::dup2_x1()
{
    Typed_element aux = frame->operand_stack->pop_typed_element();

	if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
		Typed_element aux2 = frame->operand_stack->pop_typed_element(), aux3 = frame->operand_stack->pop_typed_element();
		frame->operand_stack->push_type(aux2);
		frame->operand_stack->push_type(aux);
		frame->operand_stack->push_type(aux3);
		frame->operand_stack->push_type(aux2);
		frame->operand_stack->push_type(aux);
	} else {
		Typed_element aux2 = frame->operand_stack->pop_typed_element();
		frame->operand_stack->push_type(aux);
		frame->operand_stack->push_type(aux2);
		frame->operand_stack->push_type(aux);
	}
}

void Operations::dup2_x2()
{
    Typed_element aux = frame->operand_stack->pop_typed_element();

	if (frame->operand_stack->top_type() != TYPE_LONG && frame->operand_stack->top_type() != TYPE_DOUBLE) {
		Typed_element aux2 = frame->operand_stack->pop_typed_element(), aux3 = frame->operand_stack->pop_typed_element();
		if (aux3.type == TYPE_LONG || aux3.type == TYPE_DOUBLE) {
			frame->operand_stack->push_type(aux2);
			frame->operand_stack->push_type(aux);
			frame->operand_stack->push_type(aux3);
			frame->operand_stack->push_type(aux2);
			frame->operand_stack->push_type(aux);
		} else {
			Typed_element aux4 = frame->operand_stack->pop_typed_element();
			frame->operand_stack->push_type(aux2);
			frame->operand_stack->push_type(aux);
			frame->operand_stack->push_type(aux4);
			frame->operand_stack->push_type(aux3);
			frame->operand_stack->push_type(aux2);
			frame->operand_stack->push_type(aux);
		}
	} else {
		Typed_element aux2 = frame->operand_stack->pop_typed_element();
		if (aux2.type == TYPE_LONG || aux2.type == TYPE_DOUBLE) {
			frame->operand_stack->push_type(aux);
			frame->operand_stack->push_type(aux2);
			frame->operand_stack->push_type(aux);
		} else {
			Typed_element aux3 = frame->operand_stack->pop_typed_element();
			frame->operand_stack->push_type(aux);
			frame->operand_stack->push_type(aux3);
			frame->operand_stack->push_type(aux2);
			frame->operand_stack->push_type(aux);
		}
	}
}

void Operations::swap()
{
    Typed_element aux = frame->operand_stack->pop_typed_element(), aux2 = frame->operand_stack->pop_typed_element();
	frame->operand_stack->push_type(aux);
	frame->operand_stack->push_type(aux2);
}

void Operations::iadd()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_INT) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um inteiro!");
    }

    if (frame->operand_stack->top_type() == TYPE_INT) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um inteiro!");
    }

	result.type = TYPE_INT;
	result.real_type = RT_INT;
	result.value.i = value1.i + value2.i;
	frame->operand_stack->push_type(result);
}

void Operations::ladd()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_LONG) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um long!");
    }

    if (frame->operand_stack->top_type() == TYPE_LONG) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um long!");
    }

	result.type = TYPE_LONG;
	result.real_type = RT_LONG;
	result.value.l = value1.l + value2.l;
	frame->operand_stack->push_type(result);
}

void Operations::fadd()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_FLOAT) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um float!");
    }

    if (frame->operand_stack->top_type() == TYPE_FLOAT) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um float!");
    }

	result.type = TYPE_FLOAT;
	result.real_type = RT_FLOAT;
	result.value.f = value1.f + value2.f;
	frame->operand_stack->push_type(result);
}

void Operations::dadd()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um double!");
    }

    if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um double!");
    }

	result.type = TYPE_DOUBLE;
	result.real_type = RT_DOUBLE;
	result.value.d = value1.d + value2.d;
	frame->operand_stack->push_type(result);
}

void Operations::isub()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_INT) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um inteiro!");
    }

    if (frame->operand_stack->top_type() == TYPE_INT) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um inteiro!");
    }

	result.type = TYPE_INT;
	result.real_type = RT_INT;
	result.value.i = value1.i - value2.i;
	frame->operand_stack->push_type(result);
}

void Operations::lsub()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_LONG) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um long!");
    }

    if (frame->operand_stack->top_type() == TYPE_LONG) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um long!");
    }

	result.type = TYPE_LONG;
	result.real_type = RT_LONG;
	result.value.l = value1.l - value2.l;
	frame->operand_stack->push_type(result);
}

void Operations::fsub()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_FLOAT) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um float!");
    }

    if (frame->operand_stack->top_type() == TYPE_FLOAT) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um float!");
    }

	result.type = TYPE_FLOAT;
	result.real_type = RT_FLOAT;
	result.value.f = value1.f - value2.f;
	frame->operand_stack->push_type(result);
}

void Operations::dsub()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um double!");
    }

    if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um double!");
    }

	result.type = TYPE_DOUBLE;
	result.real_type = RT_DOUBLE;
	result.value.d = value1.d - value2.d;
	frame->operand_stack->push_type(result);
}

void Operations::imul()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_INT) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um inteiro!");
    }

    if (frame->operand_stack->top_type() == TYPE_INT) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um inteiro!");
    }

	result.type = TYPE_INT;
	result.real_type = RT_INT;
	result.value.i = value1.i * value2.i;
	frame->operand_stack->push_type(result);
}

void Operations::lmul()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_LONG) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um long!");
    }

    if (frame->operand_stack->top_type() == TYPE_LONG) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um long!");
    }

	result.type = TYPE_LONG;
	result.real_type = RT_LONG;
	result.value.l = value1.l * value2.l;
	frame->operand_stack->push_type(result);
}

void Operations::fmul()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_FLOAT) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um float!");
    }

    if (frame->operand_stack->top_type() == TYPE_FLOAT) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um float!");
    }

	result.type = TYPE_FLOAT;
	result.real_type = RT_FLOAT;
	result.value.f = value1.f * value2.f;
	frame->operand_stack->push_type(result);
}

void Operations::dmul()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um double!");
    }

    if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um double!");
    }

	result.type = TYPE_DOUBLE;
	result.real_type = RT_DOUBLE;
	result.value.d = value1.d * value2.d;
	frame->operand_stack->push_type(result);
}

void Operations::idiv()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_INT) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um inteiro!");
    }

    if (frame->operand_stack->top_type() == TYPE_INT) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um inteiro!");
    }

	result.type = TYPE_INT;
	result.real_type = RT_INT;
	result.value.i = value1.i / value2.i;
	frame->operand_stack->push_type(result);
}

void Operations::ldiv()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_LONG) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um long!");
    }

    if (frame->operand_stack->top_type() == TYPE_LONG) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um long!");
    }

	result.type = TYPE_LONG;
	result.real_type = RT_LONG;
	result.value.l = value1.l / value2.l;
	frame->operand_stack->push_type(result);
}

void Operations::fdiv()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_FLOAT) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um float!");
    }

    if (frame->operand_stack->top_type() == TYPE_FLOAT) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um float!");
    }

	result.type = TYPE_FLOAT;
	result.real_type = RT_FLOAT;
	result.value.f = value1.f / value2.f;
	frame->operand_stack->push_type(result);
}

void Operations::ddiv()
{
    Element value1, value2;
	Typed_element result;

    if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
    	value2 = frame->operand_stack->pop_element();
    } else {
    	throw std::runtime_error("Elemento lido nao era um double!");
    }

    if (frame->operand_stack->top_type() == TYPE_DOUBLE) {
		value1 = frame->operand_stack->pop_element();	
    } else {
    	throw std::runtime_error("Elemento lido nao era um double!");
    }

	result.type = TYPE_DOUBLE;
	result.real_type = RT_DOUBLE;
	result.value.d = value1.d / value2.d;
	frame->operand_stack->push_type(result);
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



void Operations::getstatic(){
    uint16_t index_byte = get_n_bytes_value(2, frame->pc);
    frame->current_pc_index--;
    Frame* aux_frame = frame;
    Cp_info cp_element = frame->cp_vector[index_byte];
    if(cp_element.tag != FIELDREF) {
        throw runtime_error("Elemento da constant pool apontado por index, não é uma referencia para FIELD_REF!");
    }
    string class_name = Displayer::dereference_index(frame->cp_vector, cp_element.info[0].u2);
    Cp_info name_and_type_element = frame->cp_vector[cp_element.info[1].u2];
    if(name_and_type_element.tag != NAMEANDTYPE) {
        throw runtime_error("Elemento da constant pool apontado por index, não é uma referencia para NAME_AND_TYPE!");
    }
    string name = Displayer::dereference_index(frame->cp_vector, name_and_type_element.info[0].u2);
    string descriptor = Displayer::dereference_index(frame->cp_vector, name_and_type_element.info[1].u2);

    // JAVA LANG
    if (class_name == "java/lang/System" && descriptor == "Ljava/io/PrintStream;" ) {
        cout << "Saida 1 " << endl;
        frame->current_pc_index++;

        return;
    }

    Static_class* static_class = get_static_class_with_field( Method_area::get_class(class_name), name);

    if(static_class == NULL) throw runtime_error("Field nao existe na classe definida!");

    // // Caso <clinit> seja empilhado.
    if (threads->top() != aux_frame) {
        cout << "Saida 2 " << endl;

        return;
    }


    Typed_element element = static_class->get_field(name);

    if(element.type == TYPE_BOOL) 
    {
        element.type = TYPE_INT;
    }

    frame->operand_stack->push_type(element);
    

    frame->current_pc_index++;
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
    Frame *aux_frame = frame;
    uint16_t index_byte = get_n_bytes_value(2, frame->pc);

    Cp_info cp_element = frame->cp_vector[index_byte];
    if(cp_element.tag != METHODREF) {
        throw runtime_error("Elemento da constant pool apontado por index, não é uma referencia para METHOD_REF!");
    }
    string class_name = Displayer::dereference_index(frame->cp_vector, cp_element.info[0].u2);
    Cp_info name_and_type_element = frame->cp_vector[cp_element.info[1].u2];
    if(name_and_type_element.tag != NAMEANDTYPE) {
        throw runtime_error("Elemento da constant pool apontado por index, não é uma referencia para NAME_AND_TYPE!");
    }

    string name = Displayer::dereference_index(frame->cp_vector, name_and_type_element.info[0].u2);
    string descriptor = Displayer::dereference_index(frame->cp_vector, name_and_type_element.info[1].u2);
    if (class_name.find("java/") != string::npos) {
        
        if (class_name == "java/io/PrintStream" && (name == "print" || name == "println")) {
            if (descriptor != "()V") {
                Typed_element element = frame->operand_stack->pop_typed_element();
                switch (element.real_type) {
                    case RT_DOUBLE:
                        printf("%f", element.value.d);
                        break;
                    case RT_FLOAT:
                        printf("%f", element.value.f);
                        break;
                    case RT_LONG:
                        printf("%lld", element.value.ls);
                        break;
                    case RT_REFERENCE:
                        cout << Displayer::display_UTF8((unsigned char *)element.value.pi, 0);
                        break;
                    case RT_BOOL:
                        printf("%s", element.value.b == 0 ? "false" : "true");
                        break;
                    case RT_BYTE:
                        printf("%d", element.value.b);
                        break;
                    case RT_CHAR:
                        printf("%c", element.value.bs);
                        break;
                    case RT_SHORT:
                
                        printf("%d", element.value.ss);
                        break;
                    case RT_INT:
                        printf("%d", element.value.is);
                        break;
                    default:
                        printf("%d", element.value.is);
                        break;
                }
            }

            if (name == "println") printf("\n");

        } else if (class_name == "java/lang/String" && name == "length") {

            Typed_element element = frame->operand_stack->pop_typed_element();

            if(element.real_type == RT_REFERENCE) {
                Typed_element ret;
                ret.type = TYPE_INT;
                ret.real_type = RT_INT;
                ret.value.i = Displayer::display_UTF8((unsigned char *)element.value.pi, 0).size();

                frame->operand_stack->push_type(ret);
            }
            else 
            {
            	throw runtime_error("Dado Invalido.");
            }



        } else if (class_name == "java/lang/String" && name == "equals") {

            Typed_element element_1 = frame->operand_stack->pop_typed_element();
            Typed_element element_2 = frame->operand_stack->pop_typed_element();

            if(element_1.real_type == RT_REFERENCE && element_2.real_type == RT_REFERENCE) {
                Typed_element ret;
                ret.type = TYPE_INT;
                ret.real_type = RT_INT;

                if (Displayer::display_UTF8((unsigned char *)element_1.value.pi, 0) == Displayer::display_UTF8((unsigned char *)element_2.value.pi, 0)) {
                    ret.value.b = 1;
                } else {
                    ret.value.b = 0;
                }

                frame->operand_stack->push_type(ret);
            }
            else 
            {
            	throw runtime_error("Dados Invalidos.");
            }


        } else {
            throw runtime_error("Metodo Invalido.");
        }
    } else {
        
        uint16_t num_args = 0; // numero de argumentos contidos na pilha de operands_stack
        uint16_t i = 1; // pulando o primeiro '('
        while (descriptor[i] != ')') 
        {
            char base_type = descriptor[i];
            if (base_type == 'D' || base_type == 'J') {
                num_args += 2;
            } else if (base_type == 'L') {
                num_args++;
                while (descriptor[++i] != ';');
            } else if (base_type == '[') {
                num_args++;
                while (descriptor[++i] == '[');
                if (descriptor[i] == 'L') while (descriptor[++i] != ';');
            } else {
                num_args++;
            }
            i++;
        }

        vector<Typed_element> args;
        for (int i = 0; i < num_args; i++) 
        {
            Typed_element element = frame->operand_stack->pop_typed_element();
            args.insert(args.begin(), element);
        }

        Typed_element object_element = frame->operand_stack->pop_typed_element();
        if(object_element.type == TYPE_REFERENCE)
        {
            throw runtime_error("Elemento não é uma referencia para REFERENCE!");
        }
        args.insert(args.begin(), object_element);

        Instance_class* instance = (Instance_class *) object_element.value.pi;

        Static_class *classRuntime = Method_area::get_class(class_name);

        // Caso <clinit> seja empilhado.
        if (threads->top() != aux_frame) {
        	frame->current_pc_index--;
        	return;
    	}

        frame_stack->add_frame(
            instance->static_class->reader_class->get_method(name,descriptor), 
            instance->static_class->reader_class->get_searched_method_class(name,descriptor)->cp->cp_vector
        );
        frame_stack->set_arguments(args);
        
    }
}

void Operations::invokespecial()
{
    Frame *aux_frame = threads->top();
    uint16_t index_byte = get_n_bytes_value(2, frame->pc);

    Cp_info cp_element = frame->cp_vector[index_byte];
    if(cp_element.tag != METHODREF) {
        throw runtime_error("INVOKESPECIAL: Pointed constant pool element is not METHODREF");
    }


    string classe = Displayer::dereference_index(frame->cp_vector, cp_element.info[0].u2);

    Cp_info metodo = frame->cp_vector[cp_element.info[1].u2];
    if(metodo.tag != NAMEANDTYPE) {
        throw runtime_error("INVOKESPECIAL: Pointed constant pool element is not NAMEANDTYPE");
    }

    string name = Displayer::dereference_index(frame->cp_vector, metodo.info[0].u2);
    string desc = Displayer::dereference_index(frame->cp_vector, metodo.info[1].u2);
    
    if ((classe == "java/lang/Object" || classe == "java/lang/String") && name == "<init>") {
        if (classe == "java/lang/String") {
            frame->operand_stack->pop_element();
        }
        return;
    }
    
    if (classe.find("java/") != string::npos) {
        cerr << "INVOKESPECIAL: ERROR: \"" << name << "\" not defined." << endl;
        exit(1);
    } else {
        uint16_t count = 0;
        uint16_t i = 1;

        while (desc[i] != ')') {
            char base_type = desc[i];
            if (base_type == 'D' || base_type == 'J') {
                (++count)++;
            } else if (base_type == 'L') {
                count++;
                while (desc[++i] != ';');
            } else if (base_type == '[') {
                count++;
                while (desc[++i] == '[');
                if (desc[i] == 'L') {
                    while (desc[++i] != ';');
                }
            } else {
                count++;
            }
            i++;
        }

        vector<Typed_element> parametros;
        for (int i = 0; i < count; i++) {
            Typed_element prox = frame->operand_stack->pop_typed_element();
            parametros.insert(parametros.begin(), prox);
        }
        
        Typed_element object_element = frame->operand_stack->pop_typed_element();

        parametros.insert(parametros.begin(), object_element);

        Instance_class* instance = (Instance_class *) object_element.value.pi;

        Static_class *classRuntime = Method_area::get_class(classe);

        if (threads->top() != aux_frame) {
            frame->operand_stack->push_type(parametros[0]);
            while (count-- > 0) {
                frame->operand_stack->push_type(parametros[count]);
            }
            frame->current_pc_index--;
            return;
        }

        frame_stack->add_frame(
            instance->static_class->reader_class->get_method(name,desc), 
            instance->static_class->reader_class->get_searched_method_class(name,desc)->cp->cp_vector
        );        
        //adiciona os parâmetros ao vetor de variáveis locais
        frame_stack->set_arguments(parametros);

    }
}

void Operations::invokestatic()
{
    Frame *aux_frame = threads->top();
    uint16_t index_byte = get_n_bytes_value(2, frame->pc);
    Cp_info cp_element = frame->cp_vector[index_byte];

    if(cp_element.tag != METHODREF)
        throw runtime_error("INVOKESTATIC: Pointed constant pool element is not METHODREF");
    
    
    string class_name = Displayer::dereference_index(frame->cp_vector, cp_element.info[0].u2);
    Cp_info name_and_type_element = frame->cp_vector[cp_element.info[1].u2];

    if(name_and_type_element.tag != NAMEANDTYPE) {
        throw runtime_error("INVOKESTATIC: Pointed constant pool element is not NAMEANDTYPE");
    }

    string name = Displayer::dereference_index(frame->cp_vector, name_and_type_element.info[0].u2);
    string descriptor = Displayer::dereference_index(frame->cp_vector, name_and_type_element.info[1].u2);
    

    if (class_name == "java/lang/Object" && name == "registerNatives") {
        cout << "saida 1" << endl;
        frame->current_pc_index++;
        return;
    }

    if (class_name.find("java/") != string::npos) {
        cerr << "INVOKESTATIC: Invalid static method invocation: " << name << endl;
    }
    else {

        uint16_t num_args = 0;
        uint16_t i = 1;
        while (descriptor[i] != ')') {
            char base_type = descriptor[i];
            if (base_type == 'D' || base_type == 'J') {
                num_args += 2;
            } else if (base_type == 'L') {
                num_args++;
                while (descriptor[++i] != ';');
            } else if (base_type == '[') {
                num_args++;
                while (descriptor[++i] == '[');
                if (descriptor[i] == 'L') while (descriptor[++i] != ';');
            } else {
                num_args++;
            }
            i++;
        }

        vector<Typed_element> args;
        for (int i = 0; i < num_args; i++) {
            
            Typed_element typed_element = frame->operand_stack->pop_typed_element();
            args.insert(args.begin(), typed_element);
            

        }

        Static_class *static_class = Method_area::get_class(class_name);

        if (threads->top() != aux_frame) {
            
            while (num_args-- > 0) {
                frame->operand_stack->push_type(args[num_args]);
            }
            
            frame->current_pc_index--;
            

            return;
        }
        

        
        frame_stack->add_frame(
            static_class->reader_class->get_method(name,descriptor), 
            static_class->reader_class->get_searched_method_class(name,descriptor)->cp->cp_vector
        );

        
        frame_stack->set_arguments(args);
        


    }

}

void Operations::invokeinterface()
{
    Frame *aux_frame = threads->top();
    uint16_t index_byte = get_n_bytes_value(2, frame->pc);
    Cp_info cp_element = frame->cp_vector[index_byte];

    if (cp_element.tag != INTERFACEMETHODREF){
        throw runtime_error("INVOKEINTERFACE: Pointed constant pool element is not METHODREF");
    }

    string class_name = Displayer::dereference_index(frame->cp_vector, cp_element.info[0].u2);
    Cp_info name_and_type_element = frame->cp_vector[cp_element.info[1].u2];
    if(name_and_type_element.tag != NAMEANDTYPE) {
        throw runtime_error("INVOKEINTERFACE: Pointed constant pool element is not NAMEANDTYPE");
    }

    string name = Displayer::dereference_index(frame->cp_vector, name_and_type_element.info[0].u2);
    string descriptor = Displayer::dereference_index(frame->cp_vector, name_and_type_element.info[1].u2);

    if (class_name.find("java/") != string::npos) {
        throw runtime_error("INVOKEINTERFACE Invalid interface method invocation");
    } else {
        uint16_t num_args = 0; 
        uint16_t i = 1; 
        while (descriptor[i] != ')') {
            char base_type = descriptor[i];
            if (base_type == 'D' || base_type == 'J') {      
                num_args += 2;
            } else if (base_type == 'L') {                  
                num_args++;
                while (descriptor[++i] != ';');
            } else if (base_type == '[') {                  
                num_args++;
                while (descriptor[++i] == '[');
                if (descriptor[i] == 'L') while (descriptor[++i] != ';');
            } else {
                num_args++;
            }
            i++;
        }
        
        vector<Typed_element> parametros;
        for (int i = 0; i < num_args; i++) {
            Typed_element elemento = frame->operand_stack->pop_typed_element();
            parametros.insert(parametros.begin(), elemento);
        }

        Typed_element object_element = frame->operand_stack->pop_typed_element();
        if (object_element.type != TYPE_REFERENCE){
            throw runtime_error("INVOKEINTERFACE: Top of stack element is not TYPE_REFERENCE");
        }
        parametros.insert(parametros.begin(), object_element);
        
        Instance_class *instance = (Instance_class *) object_element.value.pi;

        if (threads->top() != aux_frame) {
            while (num_args-- > 0) {
                frame->operand_stack->push_type(parametros[num_args]);
            }
            frame->current_pc_index--;
            return;
        }
        
        frame_stack->add_frame(
            instance->static_class->reader_class->get_method(name,descriptor), 
            instance->static_class->reader_class->get_searched_method_class(name,descriptor)->cp->cp_vector
        );
        frame_stack->set_arguments(parametros);
    }
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

// void Operations::impdep1(){

// }
    
// void Operations::impdep2(){
    

// }
