#ifndef FRAME_STACK
#define FRAME_STACK
#include <vector>
#include <stack>
#include "Reader.hpp"
#include "Typed_element.hpp"
#include "Frame.hpp"

using namespace std;

class Frame_stack {
private:
	stack<Frame*> threads;
	bool next_instruction();
	int opcode;
	void start_PC(Frame*);
public:
	Frame_stack (Reader*);
	void set_arguments(vector<Typed_element>);
	void execute();
	void add_frame(Method_info, Cp_info*);
	void add_frame(Method_info*, Cp_info*);
	void pop();
};

#endif