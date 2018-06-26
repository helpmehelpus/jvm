#ifndef OPERATIONS
#define OPERATIONS

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
	static U4 get_n_bytes_value(U1 n, vector<U2> pc);

	static Static_class* get_static_class_with_field(Static_class* base, string field_name);
	static Array* get_new_multi_array(stack<int> count_dim);
	static double get_value(Array array, stack<int> access_indexes);

	const static func functions[];

	static void run(int);


	static void lload_n(short index);
	static void fload_n(short index);
	static void dload_n(short index);
	static void aload_n(short index);

	static void nop();
	static void aconst_null();
	static void iconst_m1();
	static void iconst_0();
	static void iconst_1();
	static void iconst_2();
	static void iconst_3();
	static void iconst_4();
	static void iconst_5();
	static void lconst_0();
	static void lconst_1();
	static void fconst_0();
	static void fconst_1();
	static void fconst_2();
	static void dconst_0();
	static void dconst_1();

	static void bipush();
	static void sipush();
	static void ldc();
	static void ldc_w();
	static void ldc2_w();
	static void iload();
	static void lload();
	static void fload();
	static void dload();
	static void aload();
	static void iload_0();
	static void iload_1();
	static void iload_2();
	static void iload_3();
	static void lload_0();
	static void lload_1();

	static void lload_2();
	static void lload_3();
	static void fload_0();
	static void fload_1();
	static void fload_2();
	static void fload_3();
	static void dload_0();
	static void dload_1();
	static void dload_2();
	static void dload_3();
	static void aload_0();
	static void aload_1();
	static void aload_2();
	static void aload_3();
	static void iaload();
	static void laload();

	static void faload();
	static void daload();
	static void aaload();
	static void baload();
	static void caload();
	static void saload();
	static void istore();
	static void lstore();
	static void fstore();
	static void dstore();
	static void astore();
	static void istore_1();
	static void istore_2();
	static void istore_3();
	static void istore_0();
	static void lstore_0();

	static void lstore_1();
	static void lstore_2();
	static void lstore_3();
	static void fstore_0();
	static void fstore_1();
	static void fstore_2();
	static void fstore_3();
	static void dstore_0();
	static void dstore_1();
	static void dstore_2();
	static void dstore_3();
	static void astore_0();
	static void astore_1();
	static void astore_2();
	static void astore_3();
	static void iastore();

	static void lastore();
	static void fastore();
	static void dastore();
	static void aastore();
	static void bastore();
	static void castore();
	static void sastore();
	static void pop();
	static void pop2();
	static void dup();
	static void dup_x1();
	static void dup_x2();
	static void dup2();
	static void dup2_x1();
	static void dup2_x2();
	static void swap();

	static void iadd();
	static void ladd();
	static void fadd();
	static void dadd();
	static void isub();
	static void lsub();
	static void fsub();
	static void dsub();
	static void imul();
	static void lmul();
	static void fmul();
	static void dmul();
	static void idiv();
	static void ldiv();
	static void fdiv();
	static void ddiv();

	static void irem();
	static void lrem();
	static void frem();
	static void drem();
	static void ineg();
	static void lneg();
	static void fneg();
	static void dneg();
	static void ishl();
	static void lshl();
	static void ishr();
	static void lshr();
	static void iushr();
	static void lushr();
	static void iand();
	static void land();

	static void ior();
	static void lor();
	static void ixor();
	static void lxor();
	static void iinc();
	static void i2l();
	static void i2f();
	static void i2d();
	static void l2i();
	static void l2f();
	static void l2d();
	static void f2i();
	static void f2l();
	static void f2d();
	static void d2i();
	static void d2l();

	static void d2f();
	static void i2b();
	static void i2c();
	static void i2s();
	static void lcmp();
	static void fcmpl();
	static void fcmpg();
	static void dcmpl();
	static void dcmpg();
	static void ifeq();
	static void ifne();
	static void iflt();
	static void ifge();
	static void ifgt();
	static void ifle();
	static void if_icmpeq();

	static void if_icmpne();
	static void if_icmplt();
	static void if_icmpge();
	static void if_icmpgt();
	static void if_icmple();
	static void if_acmpeq();
	static void if_acmpne();
	static void funcgoto();
	static void jsr();
	static void funcret();
	static void tableswitch();
	static void lookupswitch();
	static void ireturn();
	static void lreturn();
	static void freturn();
	static void dreturn();

	static void areturn();
	static void func_return();
	static void getstatic();
	static void putstatic();
	static void getfield();
	static void putfield();
	static void invokevirtual();
	static void invokespecial();
	static void invokestatic();
	static void invokeinterface();

	static void func_new();
	static void newarray();
	static void anewarray();
	static void arraylength();
	static void athrow();

	static void wide();
	static void multianewarray();
	static void ifnull();
	static void ifnonnull();
	static void goto_w();
	static void jsr_w();

	// TODO: move these functions to another class
	
	static int checkFloat (float);

	static int checkDouble (double);
	
};

#endif