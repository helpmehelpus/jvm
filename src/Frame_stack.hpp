#ifndef FRAME_STACK
#define FRAME_STACK

#include <stack>
#include <vector>

#include "Frame.hpp"
#include "Reader.hpp"
#include "Typed_element.hpp"

using namespace std;

class Frame_stack {
public:
	Frame_stack(Reader*);

	int opcode;
	int current_PC;
	stack<Frame*>* threads;
	
	void execute();
	void set_start_PC(Frame*);
	bool next_instruction();
	void pop();
	void add_frame(Method_info, vector<Cp_info>);
	void set_arguments(vector<Typed_element>);
};

#endif