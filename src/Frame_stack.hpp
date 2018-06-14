#ifndef FRAME_STACK
#define FRAME_STACK
#include <vector>
#include <stack>
#include "Reader.hpp"
#include "Typed_element.hpp"
#include "Frame.hpp"

using namespace std;

class Frame_stack {
public:
	stack<Frame> threads;
	bool next_instruction();
	int opcode;
	int current_PC;
	void set_start_PC(Frame);
	Frame_stack(Reader*);
	void set_arguments(vector<Typed_element>);
	void execute();
	void add_frame(Method_info, vector<Cp_info>);
	// void add_frame(Method_info*, Cp_info*);
	void pop();
};

#endif