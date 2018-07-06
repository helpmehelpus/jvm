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

/*! \class Operations
 *	\brief Classe responsável por realizar as operações da JVM
 *
 * 
 */
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
	* Instrução que carrega caractere de um vetor.
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
	* Instrução que desempilha o primeiro ou segundo topos da pilha.
    */
	static void pop2();

	/*!
	* Instrução que duplica o topo da pilha.
    */
	static void dup();

	/*!
	* Instrução que duplica o topo da pilha e insere dois valores.
    */
	static void dup_x1();

	/*!
	* Instrução que duplica o topo da pilha e insere três valores.
    */
	static void dup_x2();

	/*!
	* Instrução que duplica o primeiro ou segundo topos da pilha
    */
	static void dup2();

	/*!
	* Instrução que duplica o primeiro ou segundo topos da pilha e insere dois ou três valores.
    */
	static void dup2_x1();

	/*!
	* Instrução que duplica o primeiro ou segundo topos da pilha e insere dois, três ou quatro valores.
    */
	static void dup2_x2();

	/*!
	* Instrução que troca os dois primeiros topos da pilha.
    */
	static void swap();

	/*!
	* Instrução que soma inteiros.
    */
	static void iadd();

	/*!
	* Instrução que soma \e longs.
    */
	static void ladd();

	/*!
	* Instrução que soma \e floats.
    */
	static void fadd();

	/*!
	* Instrução que soma \e doubles.
    */
	static void dadd();

	/*!
	* Instrução que subtrai inteiros.
    */
	static void isub();

	/*!
	* Instrução que subtrai \e longs.
    */
	static void lsub();

	/*!
	* Instrução que subtrai \e floats.
    */
	static void fsub();

	/*!
	* Instrução que subtrai \e doubles.
    */
	static void dsub();

	/*!
 	* Instrução que multiplica inteiros.
    */
	static void imul();

	/*!
	* Instrução que multiplica \e longs.
    */
	static void lmul();

	/*!
	* Instrução que multiplica \e floats.
    */
	static void fmul();

	/*!
	* Instrução que multiplica \e doubles.
    */
	static void dmul();

	/*!
	* Instrução que divide inteiros.
    */
	static void idiv();

	/*!
	* Instrução que divide \e longs.
    */
	static void ldiv();

	/*!
	* Instrução que divide \e floats.
    */
	static void fdiv();

	/*!
	* Instrução que divide \e doubles.
    */
	static void ddiv();

	/*!
	* Instrução que retorna o resto de uma divisão inteira.
    */
	static void irem();

	/*!
	* Instrução que retorna o resto de uma divisão de \e longs.
    */
	static void lrem();

	/*!
	* Instrução que retorna o resto de uma divisão de \e floats.
    */
	static void frem();

	/*!
	* Instrução que retorna o resto de uma divisão \e doubles	.
    */
	static void drem();

	/*!
	* Instrução que nega um inteiro.
    */
	static void ineg();

	/*!
	* Instrução que nega um \e long.
    */
	static void lneg();

	/*!
	* Instrução que nega um \e float.
    */
	static void fneg();

	/*!
	* Instrução que nega um \e double.
    */
	static void dneg();

	/*!
	* Instrução que aritmético-desloca um inteiro para a esquerda.
    */
	static void ishl();

	/*!
	* Instrução que aritmético-desloca um \e long para a esquerda.
    */
	static void lshl();

	/*!
	* Instrução que aritmético-desloca um inteiro para a direita.
    */
	static void ishr();

	/*!
	* Instrução que aritmético-desloca um \e long para a direita.
    */
	static void lshr();

	/*!
	* Instrução que lógico-desloca um inteiro para a direita
    */
	static void iushr();

	/*!
	* Instrução que lógico-desloca um \e long para a direita
    */
	static void lushr();

	/*!
	* Instrução que realiza um E \e bit a \e bit entre inteiros.
    */
	static void iand();

	/*!
	* Instrução que realiza um E \e bit a \e bit entre \e longs
    */
	static void land();

	/*!
	* Instrução que realiza um OU \e bit a \e bit entre inteiros.
    */

	static void ior();
	/*!
	* Instrução que realiza um OU \e bit a \e bit entre \e longs.
    */

	static void lor();

	/*!
	* Instrução que realiza um XOR \e bit a \e bit entre inteiros.
    */

	static void ixor();

	/*!
	* Instrução que realiza um XOR \e bit a \e bit entre \e longs.
    */
	static void lxor();

	/*!
	* Instrução que incrementa variável local por uma constante.
    */
	static void iinc();

	/*!
	* Instrução que converte inteiro para \e long.
    */
	static void i2l();

	/*!
	* Instrução que converte inteiro para \e float.
    */
	static void i2f();

	/*!
	* Instrução que converte inteiro para \e double.
    */
	static void i2d();

	/*!
	* Instrução que converte \e long para inteiro.
    */
	static void l2i();

	/*!
	* Instrução que converte \e long para \e float.
    */
	static void l2f();

	/*!
	* Instrução que converte \e long para \e double.
    */
	static void l2d();

	/*!
	* Instrução que converte \e float para inteiro.
    */
	static void f2i();

	/*!
	* Instrução que converte \e float para \e long.
    */
	static void f2l();

	/*!
	* Instrução que converte \e float para \e double.
    */
	static void f2d();

	/*!
	* Instrução que converte \e double para inteiro.
    */
	static void d2i();

	/*!
	* Instrução que converte  \e double para \e long.
    */
	static void d2l();

	/*!
	* Instrução que convete \e double para \e float.
    */
	static void d2f();

	/*!
	* Instrução que converte inteiro para byte.
    */
	static void i2b();

	/*!
	* Instrução que converte inteiro para \e char.
    */
	static void i2c();

	/*!
	* Instrução que converte intero para \e short.
    */
	static void i2s();

	/*!
	* Instrução que compara \e longs.
    */
	static void lcmp();

	/*!
	* Instrução que compara \e floats (menor).
    */
	static void fcmpl();

	/*!
	* Instrução que compara \e floats (maior).
    */
	static void fcmpg();

	/*!
	* Instrução que compara \e doubles (menor).
    */
	static void dcmpl();

	/*!
	* Instrução que compara \e doubles (maior).
    */
	static void dcmpg();

	/*!
	* Instrução que realiza um e branch caso a comparação seja zero (igual).
    */
	static void ifeq();

	/*!
	* Instrução que realiza um e branch caso a comparação seja zero (diferente).
    */
	static void ifne();

	/*!
	* Instrução que realiza um e branch caso a comparação seja zero (menor).
    */
	static void iflt();

	/*!
	* Instrução que realiza um e branch caso a comparação seja zero (maior igual).
    */
	static void ifge();

	/*!
	* Instrução que realiza um e branch caso a comparação seja zero (maior).
    */
	static void ifgt();

	/*!
	* Instrução que realiza um e branch caso a comparação seja zero (menor igual).
    */
	static void ifle();

	/*!
	* Instrução que realiza um \e branch se a comparação de inteiros é satisfeita (iguais).
    */
	static void if_icmpeq();

	/*!
	* Instrução que realiza um \e branch se a comparação de inteiros é satisfeita (diferentes).
    */

	static void if_icmpne();

	/*!
	* Instrução que realiza um \e branch se a comparação de inteiros é satisfeita (menor).
    */
	static void if_icmplt();

	/*!
	* Instrução que realiza um \e branch se a comparação de inteiros é satisfeita (maior igual).
    */
	static void if_icmpge();

	/*!
	* Instrução que realiza um \e branch se a comparação de inteiros é satisfeita (maior).
    */
	static void if_icmpgt();

	/*!
	* Instrução que realiza um \e branch se a comparação de inteiros é satisfeita (menor igual).
    */
	static void if_icmple();

	/*!
	* Instrução que realiza um \e branch se a comparação de referências é satisfeita (igual).
    */
	static void if_acmpeq();

	/*!
	* Instrução que realiza um \e branch se a comparação de referências é satisfeita (diferente).
    */
	static void if_acmpne();

	/*!
	* Instrução que sempre realiza um branch.
    */
	static void funcgoto();

	/*!
	* Instrução que pula para uma subrotina.
    */
	static void jsr();

	/*!
	* Instrução que retorna de uma subrotina
    */
	static void funcret();

	/*!
	* Instrução que acessa a tabela de jump por indice e pula.
    */
	static void tableswitch();

	/*!
	* Instrução queacessa a tabela de jump por correspondência de chave e pula.
    */
	static void lookupswitch();

	/*!
	* Instrução que retorna um inteiro de um método.
    */
	static void ireturn();

	/*!
	* Instrução que um \e long de um método.
    */
	static void lreturn();

	/*!
	* Instrução que retorna um \e float de um método.
    */
	static void freturn();

	/*!
	* Instrução que retorna um \e double de um método.
    */
	static void dreturn();

	/*!
	* Instrução que retorna uma referência de um método.
    */

	static void areturn();

	/*!
	* Instrução que retorna void de um método.
    */
	static void func_return();

	/*!
	* Instrução que retorna um campo estático de um método.
    */
	static void getstatic();

	/*!
	* Instrução que define um campo estático para um método.
    */
	static void putstatic();

	/*!
	* Instrução que busca um campo de um objeto.
    */
	static void getfield();

	/*!
	* Instrução que define um campo de um objeto.
    */
	static void putfield();

	/*!
	* Instrução que invoca a instância de um método.
    */
	static void invokevirtual();

	/*!
	* Instrução que invoca a instância de um método.tratamento especial para invocações de método de inicialização de superclasse, privada e instância
    */
	static void invokespecial();

	/*!
	* Instrução que um método de uma classe estática .
    */
	static void invokestatic();

	/*!
	* Instrução que invoca o método de interface.
    */
	static void invokeinterface();

	/*!
	* Instrução que cria um objeto.
    */

	static void func_new();

	/*!
	* Instrução que um vetor.
    */
	static void newarray();

	/*!
	* Instrução que um vetor de referências.
    */
	static void anewarray();

	/*!
	* Instrução que retorna o tamanho do array.
    */
	static void arraylength();

	/*!
	* Instrução que lança uma exceção ou erro.
    */
	static void athrow();

	/*!
	* Instrução que estende o índice de variáveis locais por bytes adicionais
    */

	static void wide();

	/*!
	* Instrução que um array multidimensional.
    */
	static void multianewarray();

	/*!
	* Instrução que realiza um \e branch se a referência é nula.
    */
	static void ifnull();

	/*!
	* Instrução que realiza um \e branch se a referência não 	é nula.
    */
	static void ifnonnull();

	/*!
	* Instrução que realiza um \e branch sempre, índice amplo.
    */
	static void goto_w();

	/*!
	* Instrução que oula para a subrotina, índice largo.
    */
	static void jsr_w();


	// static void breakpoint();

	
	// static void impdep1();

	// static void impdep2();

	/*!
	* Instrução que checa um \e float.
    */
	static int check_float(float f);

	/*!
	* Instrução que checa um \e double.
    */
	static int check_double(double d);

	
};

#endif