#ifndef METHOD_AREA
#define METHOD_AREA

class Method_area;


#include "Reader.hpp"
#include "Base_types.hpp"
#include "Constant_pool.hpp"
#include "Static_class.hpp"
#include "Frame_stack.hpp"
// #include "frame.h"
// #include "classe.h"
#include <map>
#include <algorithm>
#include <string>

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