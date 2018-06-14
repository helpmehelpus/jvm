#ifndef METHOD_AREA
#define METHOD_AREA

class Method_area;

#include <algorithm>
#include <map>
#include <string>

#include "Base_types.hpp"
#include "Constant_pool.hpp"
#include "Frame_stack.hpp"
#include "Reader.hpp"
#include "Static_class.hpp"

using namespace std;

class Method_area {
private:
	static map<string, Static_class*> classes;
	static Frame_stack *frame_stack;
	
public:
	static string path;
	static Static_class *get_class(string);
    // static bool add_class(string);
    static bool add_class(Reader*);
    static void set_frame_stack(Frame_stack*);
};

#endif