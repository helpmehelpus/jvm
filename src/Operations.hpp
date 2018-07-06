#ifndef OPERATIONS
#define OPERATIONS

#include<math.h>


#include "Array.hpp"
#include "Base_types.hpp"
#include "Frame.hpp"
#include "Method_area.hpp"
#include "Constant_pool.hpp"
#include "Displayer.hpp"


using namespace std;

typedef void (*func)(void);

class Operations {
public:
	// Operations(Frame*);
	static bool is_wide;
	static Frame* frame;
	static stack<Frame*>* threads;
	static Frame_stack* frame_stack;
	

	static void set_frame(Frame*);
	static void set_threads(stack<Frame*>*);
	static void set_frame_stack(Frame_stack*);
	static U4 get_n_bytes_value(U1 n, unsigned char ** pc);

	static Static_class* get_static_class_with_field(Static_class* base, string field_name);
	static Array* get_new_multi_array(stack<int> count_dim);
	// static double get_value(Array array, stack<int> access_indexes);

	const static func functions[];

	static void run(int);


	static void lload_n(short index);
	static void fload_n(short index);
	static void dload_n(short index);
	static void aload_n(short index);

	/*!
	* Instrução que não realiza nenhuma operação
    */
	
	static void nop();

	/*!
	* Instrução que empilha uma referência ao \e null \e object na pilha de operandos.
    */
	static void aconst_null();

	/*!
	* Instrução que empilha inteiro -1 na pilha de operandos.
    */
	static void iconst_m1();

	/*!
	* Instrução que empilha inteiro 0 na pilha de operandos.
    */
	static void iconst_0();

	/*!
	* Instrução que empilha inteiro 1 na pilha de operandos.
    */
	static void iconst_1();

	/*!
	* Instrução que empilha inteiro 2 na pilha de operandos.
    */
	static void iconst_2();

	/*!
	* Instrução que empilha inteiro 3 na pilha de operandos.
    */
	static void iconst_3();

	/*!
	* Instrução que empilha inteiro 4 na pilha de operandos.
    */
	static void iconst_4();

	/*!
	* Instrução que empilha inteiro 5 na pilha de operandos.
    */
	static void iconst_5();

	/*!
	* Instrução que empilha \e long 0 na pilha de operandos.
    */
	static void lconst_0();

	/*!
	* Instrução que empilha \e long 1 na pilha de operandos.
    */
	static void lconst_1();

	/*!
	* Instrução que empilha \e float 0.0 na pilha de operandos.
    */
	static void fconst_0();

	/*!
	* Instrução que empilha \e float 1.0 na pilha de operandos.
    */
	static void fconst_1();

	/*!
	* Instrução que empilha \e float 2.0 na pilha de operandos.
    */
	static void fconst_2();

	/*!
	* Instrução que empilha \e double 0.0 na pilha de operandos.
    */
	static void dconst_0();

	/*!
	* Instrução que empilha \e float 1.0 na pilha de operandos.
    */
	static void dconst_1();

	/*!
	* Instrução que converte um byte imediato com extensão de sinal em um inteiro e o empilha na pilha de operandos.
    */
	static void bipush();

	/*!
	* Instrução que converte a concatenação de dois bytes com extensão de sinal em um inteiro e o empilha na pilha de operandos.
    */
	static void sipush();

	/*!
	* Instrução que empilha item do \e Constant \e Pool.
    */
	static void ldc();

	/*!
	* Instrução que empilha item com largo índice do \e Constant \e Pool.
    */
	static void ldc_w();

	/*!
	* Instrução que empilha long ou double com largo índice do \e Constant \e Pool.
    */
	static void ldc2_w();

	/*!
	* Instrução que carrega um inteiro das variáveis locais.
    */
	static void iload();

	/*!
	*Instrução que carrega um \e long das variáveis locais.
    */
	static void lload();

	/*!
	*Instrução que carrega um \e float das variáveis locais.
    */
	static void fload();

	/*!
	*Instrução que carrega um \e double das variáveis locais.
    */
	static void dload();

	/*!
	* Instrução que carrega uma referência das variáveis locais.
    */
	static void aload();

	/*!
	* Instrução que empilha o valor inteiro da variável local no índice 0 na pilha de operandos.
    */
	static void iload_0();

	/*!
	* Instrução que empilha o valor inteiro da variável local no índice 1 na pilha de operandos.
    */
	static void iload_1();

	/*!
	* Instrução que empilha o valor inteiro da variável local no índice 2 na pilha de operandos.
    */
	static void iload_2();

	/*!
	* Instrução que empilha o valor inteiro da variável local no índice 3 na pilha de operandos.
    */
	static void iload_3();

	/*!
	* Instrução que empilha o valor \e long da variável local no índice 0 na pilha de operandos.
    */
	static void lload_0();

	/*!
	* Instrução que empilha o valor \e long da variável local no índice 1 na pilha de operandos.
    */
	static void lload_1();

	/*!
	* Instrução que empilha o valor \e long da variável local no índice 2 na pilha de operandos.
    */

	static void lload_2();

	/*!
	*Instrução que empilha o valor \e long da variável local no índice 3 na pilha de operandos.
    */
	static void lload_3();

	/*!
	* Instrução que empilha o valor \e float da variável local no índice 0 na pilha de operandos.
    */
	static void fload_0();

	/*!
	* Instrução que empilha o valor \e float da variável local no índice 1 na pilha de operandos.
    */
	static void fload_1();

	/*!
	* Instrução que empilha o valor \e float da variável local no índice 2 na pilha de operandos.
    */
	static void fload_2();

	/*!
	* Instrução que empilha o valor \e float da variável local no índice 3 na pilha de operandos.
    */
	static void fload_3();

	/*!
	* Instrução que empilha o valor \e double da variável local no índice 0 na pilha de operandos.
    */
	static void dload_0();

	/*!
	* Instrução que empilha o valor \e double da variável local no índice 1 na pilha de operandos.
    */
	static void dload_1();

	/*!
	* Instrução que empilha o valor \e double da variável local no índice 2 na pilha de operandos.
    */
	static void dload_2();

	/*!
	* Instrução que empilha o valor \e double da variável local no índice 3 na pilha de operandos.
    */
	static void dload_3();

	/*!
	* Instrução que empilha o valor referência da variável local no índice 0 na pilha de operandos.
    */
	static void aload_0();

	/*!
	* Instrução que empilha o valor referência da variável local no índice 1 na pilha de operandos.
    */
	static void aload_1();

	/*!
	* Instrução que empilha o valor referência da variável local no índice 2 na pilha de operandos.
    */
	static void aload_2();

	/*!
	* Instrução que empilha o valor referência da variável local no índice 3 na pilha de operandos.
    */
	static void aload_3();

	/*!
	* Instrução que carrega um inteiro de um vetor.
    */
	static void iaload();

	/*!
	* Instrução que carrega um \e long de um vetor.
    */
	static void laload();

	/*!
	* Instrução que carrega um \e float de um vetor.
    */

	static void faload();

	/*!
	* Instrução que carrega um \e double de um vetor.
    */
	static void daload();

	/*!
	* Instrução que carrega uma referência de um vetor.
    */
	static void aaload();

	/*!
	*Instrução que carrega um \e byte ou \e boleano de um vetor.
    */
	static void baload();

	/*!
	* Instrução que caractere de um vetor.
    */
	static void caload();

	/*!
	* Instrução que carrega um short de um vetor.
    */
	static void saload();

	/*!
	* Instrução que salva inteiro nas variáveis locais
    */
	static void istore();

	/*!
	* Instrução que  salva \e long nas variáveis locais
    */
	static void lstore();

	/*!
	* Instrução que salva \e float nas variáveis locais
    */
	static void fstore();

	/*!
	* Instrução que salva \e double nas variáveis locais
    */
	static void dstore();

	/*!
	* Instrução que salva referência nas variáveis locais
    */
	static void astore();

	/*!
	* Instrução que desempilha o valor inteiro da variável local no índice 1 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void istore_1();

	/*!
	*Instrução que desempilha o valor inteiro da variável local no índice 2 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void istore_2();

	/*!
	* Instrução que desempilha o valor inteiro da variável local no índice 3 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void istore_3();

	/*!
	* Instrução que desempilha o valor inteiro da variável local no índice 0 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void istore_0();

	/*!
	* Instrução que desempilha o valor \e long da variável local no índice 0 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void lstore_0();

	/*!
	* Instrução que desempilha o valor \e long da variável local no índice 1 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void lstore_1();

	/*!
	* Instrução que desempilha o valor \e long da variável local no índice 2 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void lstore_2();

	/*!
	* Instrução que desempilha o valor \e long da variável local no índice 3 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void lstore_3();

	/*!
	* Instrução que desempilha o valor \e float da variável local no índice 0 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void fstore_0();

	/*!
	* Instrução que desempilha o valor \e float da variável local no índice 0 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void fstore_1();

	/*!
	* Instrução que desempilha o valor \e float da variável local no índice 2 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void fstore_2();
	
	/*!
	* Instrução que desempilha o valor \e float da variável local no índice 3 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void fstore_3();

	/*!
	* Instrução que desempilha o valor \e double da variável local no índice 0 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void dstore_0();

	/*!
	* Instrução que desempilha o valor \e double da variável local no índice 1 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void dstore_1();

	/*!
	* Instrução que desempilha o valor \e double da variável local no índice 2 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void dstore_2();

	/*!
	* Instrução que desempilha o valor \e double da variável local no índice 3 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void dstore_3();

	/*!
	* Instrução que desempilha o valor referência da variável local no índice 0 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void astore_0();

	/*!
	* Instrução que desempilha o valor referência da variável local no índice 1 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void astore_1();

	/*!
	* Instrução que desempilha o valor referência da variável local no índice 2 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void astore_2();

	/*!
	* Instrução que desempilha o valor referência da variável local no índice 3 na pilha de operandos e o valor da variável local é atribuido ao valor desempilhado.
    */
	static void astore_3();

	/*!
	* Instrução que salva em um vetor de inteiros.
    */
	static void iastore();

	/*!
	* Instrução que salva em um vetor de \e longs.
    */


	static void lastore();

	/*!
	* Instrução que salva em um vetor de \e floats.
    */
	static void fastore();

	/*!
	* Instrução que salva em um vetor de \e doubles.
    */
	static void dastore();

	/*!
	* Instrução que salva em um vetor de referências.
    */
	static void aastore();

	/*!
	* Instrução que salva em um vetor de booleanos.
    */
	static void bastore();

	/*!
	* Instrução que salva em um vetor de \e chars.
    */
	static void castore();

	/*!
	* Instrução que salva em um vetor de \e shorts.
    */
	static void sastore();

	/*!
	* Instrução que desempilha o topo da pilha.
    */
	static void pop();

	/*!
	* Instrução que desempilha o primeirou ou segundo topos da pilha.
    */
	static void pop2();

	/*!
	* Instrução que
    */
	static void dup();

	/*!
	* Instrução que
    */
	static void dup_x1();

	/*!
	* Instrução que
    */
	static void dup_x2();

	/*!
	* Instrução que
    */
	static void dup2();

	/*!
	* Instrução que
    */
	static void dup2_x1();

	/*!
	* Instrução que
    */
	static void dup2_x2();

	/*!
	* Instrução que
    */
	static void swap();

	/*!
	* Instrução que
    */


/*!
	* Instrução que
    */
	static void iadd();

	/*!
	* Instrução que
    */
	static void ladd();

	/*!
	* Instrução que
    */
	static void fadd();

	/*!
	* Instrução que
    */
	static void dadd();

	/*!
	* Instrução que
    */
	static void isub();

	/*!
	* Instrução que
    */
	static void lsub();

	/*!
	* Instrução que
    */
	static void fsub();

	/*!
	* Instrução que
    */
	static void dsub();

	/*!
	* Instrução que
    */
	static void imul();

	/*!
	* Instrução que
    */
	static void lmul();

	/*!
	* Instrução que
    */
	static void fmul();

	/*!
	* Instrução que
    */
	static void dmul();

	/*!
	* Instrução que
    */
	static void idiv();

	/*!
	* Instrução que
    */
	static void ldiv();

	/*!
	* Instrução que
    */
	static void fdiv();

	/*!
	* Instrução que
    */
	static void ddiv();

	/*!
	* Instrução que
    */


/*!
	* Instrução que
    */
	static void irem();

	/*!
	* Instrução que
    */
	static void lrem();

	/*!
	* Instrução que
    */
	static void frem();

	/*!
	* Instrução que
    */
	static void drem();

	/*!
	* Instrução que
    */
	static void ineg();

	/*!
	* Instrução que
    */
	static void lneg();

	/*!
	* Instrução que
    */
	static void fneg();

	/*!
	* Instrução que
    */
	static void dneg();

	/*!
	* Instrução que
    */
	static void ishl();

	/*!
	* Instrução que
    */
	static void lshl();

	/*!
	* Instrução que
    */
	static void ishr();

	/*!
	* Instrução que
    */
	static void lshr();

	/*!
	* Instrução que
    */
	static void iushr();

	/*!
	* Instrução que
    */
	static void lushr();

	/*!
	* Instrução que
    */
	static void iand();

	/*!
	* Instrução que
    */
	static void land();

	/*!
	* Instrução que
    */


/*!
	* Instrução que
    */
	static void ior();

	/*!
	* Instrução que
    */
	static void lor();

	/*!
	* Instrução que
    */
	static void ixor();

	/*!
	* Instrução que
    */
	static void lxor();

	/*!
	* Instrução que
    */
	static void iinc();

	/*!
	* Instrução que
    */
	static void i2l();

	/*!
	* Instrução que
    */
	static void i2f();

	/*!
	* Instrução que
    */
	static void i2d();

	/*!
	* Instrução que
    */
	static void l2i();

	/*!
	* Instrução que
    */
	static void l2f();

	/*!
	* Instrução que
    */
	static void l2d();

	/*!
	* Instrução que
    */
	static void f2i();

	/*!
	* Instrução que
    */
	static void f2l();

	/*!
	* Instrução que
    */
	static void f2d();

	/*!
	* Instrução que
    */
	static void d2i();

	/*!
	* Instrução que
    */
	static void d2l();

	/*!
	* Instrução que
    */


/*!
	* Instrução que
    */
	static void d2f();

	/*!
	* Instrução que
    */
	static void i2b();

	/*!
	* Instrução que
    */
	static void i2c();

	/*!
	* Instrução que
    */
	static void i2s();

	/*!
	* Instrução que
    */
	static void lcmp();

	/*!
	* Instrução que
    */
	static void fcmpl();

	/*!
	* Instrução que
    */
	static void fcmpg();

	/*!
	* Instrução que
    */
	static void dcmpl();

	/*!
	* Instrução que
    */
	static void dcmpg();

	/*!
	* Instrução que
    */
	static void ifeq();

	/*!
	* Instrução que
    */
	static void ifne();

	/*!
	* Instrução que
    */
	static void iflt();

	/*!
	* Instrução que
    */
	static void ifge();

	/*!
	* Instrução que
    */
	static void ifgt();

	/*!
	* Instrução que
    */
	static void ifle();

	/*!
	* Instrução que
    */
	static void if_icmpeq();

	/*!
	* Instrução que
    */


/*!
	* Instrução que
    */
	static void if_icmpne();

	/*!
	* Instrução que
    */
	static void if_icmplt();

	/*!
	* Instrução que
    */
	static void if_icmpge();

	/*!
	* Instrução que
    */
	static void if_icmpgt();

	/*!
	* Instrução que
    */
	static void if_icmple();

	/*!
	* Instrução que
    */
	static void if_acmpeq();

	/*!
	* Instrução que
    */
	static void if_acmpne();

	/*!
	* Instrução que
    */
	static void funcgoto();

	/*!
	* Instrução que
    */
	static void jsr();

	/*!
	* Instrução que
    */
	static void funcret();

	/*!
	* Instrução que
    */
	static void tableswitch();

	/*!
	* Instrução que
    */
	static void lookupswitch();

	/*!
	* Instrução que
    */
	static void ireturn();

	/*!
	* Instrução que
    */
	static void lreturn();

	/*!
	* Instrução que
    */
	static void freturn();

	/*!
	* Instrução que
    */
	static void dreturn();

	/*!
	* Instrução que
    */


/*!
	* Instrução que
    */
	static void areturn();

	/*!
	* Instrução que
    */
	static void func_return();

	/*!
	* Instrução que
    */
	static void getstatic();

	/*!
	* Instrução que
    */
	static void putstatic();

	/*!
	* Instrução que
    */
	static void getfield();

	/*!
	* Instrução que
    */
	static void putfield();

	/*!
	* Instrução que
    */
	static void invokevirtual();

	/*!
	* Instrução que
    */
	static void invokespecial();

	/*!
	* Instrução que
    */
	static void invokestatic();

	/*!
	* Instrução que
    */
	static void invokeinterface();

	/*!
	* Instrução que
    */


/*!
	* Instrução que
    */
	static void func_new();

	/*!
	* Instrução que
    */
	static void newarray();

	/*!
	* Instrução que
    */
	static void anewarray();

	/*!
	* Instrução que
    */
	static void arraylength();

	/*!
	* Instrução que
    */
	static void athrow();

	/*!
	* Instrução que
    */


/*!
	* Instrução que
    */
	static void wide();

	/*!
	* Instrução que
    */
	static void multianewarray();

	/*!
	* Instrução que
    */
	static void ifnull();

	/*!
	* Instrução que
    */
	static void ifnonnull();

	/*!
	* Instrução que
    */
	static void goto_w();

	/*!
	* Instrução que
    */
	static void jsr_w();

	/*!
	* Instrução que
    */
	// static void breakpoint();

	/*!
	* Instrução que
    */
	// static void impdep1();

	/*!
	* Instrução que
    */
	// static void impdep2();

	/*!
	* Instrução que
    */
	static int check_float(float f);

	/*!
	* Instrução que
    */
	static int check_double(double d);

	/*!
	* Instrução que
    */
	
};

#endif