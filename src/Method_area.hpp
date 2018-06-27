#ifndef METHOD_AREA
#define METHOD_AREA

#include <algorithm>
#include <map>
#include <string>

#include "Base_types.hpp"
#include "Constant_pool.hpp"
#include "Frame_stack.hpp"
#include "Reader.hpp"
#include "Static_class.hpp"
#include "Displayer.hpp"


using namespace std;
class Reader;
class Static_class;
class Frame_stack;


class Method_area {
public:

	static string path;
	static map<string, Static_class*> classes;
	static Frame_stack *frame_stack;
	static Static_class *get_class(string);
    static bool add_class(string);
    static bool add_class(Reader*);
    static void set_frame_stack(Frame_stack*);
};

#endif