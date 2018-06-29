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
    &Operations::goto_w, &Operations::jsr_w };

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



void Operations::getstatic(){
    uint16_t index_byte = get_n_bytes_value(2, frame->pc);
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
        frame->current_pc_index++;
        return;
    }

    Static_class* static_class = get_static_class_with_field( Method_area::get_class(class_name), name);

    if(static_class == NULL) throw runtime_error("Field nao existe na classe definida!");

    // // Caso <clinit> seja empilhado.
    if (threads->top() != aux_frame) {
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
                        printf("%ld", element.value.ls);
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
            char baseType = descriptor[i];
            if (baseType == 'D' || baseType == 'J') {
                num_args += 2;
            } else if (baseType == 'L') {
                num_args++;
                while (descriptor[++i] != ';');
            } else if (baseType == '[') {
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
