#ifndef METHOD_AREA
#define METHOD_AREA

class Method_area;
class Static_class;
class Frame_stack;

#include "Reader.hpp"
#include "Base_types.hpp"
#include "Constant_pool.hpp"
// #include "frame.h"
// #include "classe.h"
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Method_area {
private:
	static map<string, Static_class*> classes;
	static Frame_stack *fs;
public:
	static string path;
	static Static_class *getClass(string);
    static bool add_class(string);
    static bool add_class(Reader*);
    static void setFrameStack(Frame_stack*);
};

#endif