#include "Method_area.hpp"
#include "Displayer.hpp"
Static_class *Method_area::get_class(string s) {
    
    for (map<string, Static_class*>::const_iterator i = classes.begin(); i != classes.end(); i++) {
       if (i->first == s) {
            return i->second;
        }
    }
    return nullptr;
}
bool Method_area::add_class(Reader *reader) {
    Static_class *add = new Static_class(reader);
    classes.insert(pair<string, Static_class*>(Displayer::dereference_index(reader->cp->cp_vector, reader->this_class), add));
    if (reader->has_clinit()) {
        frame_stack->add_frame(reader->clinit_index, reader->cp->cp_vector);
    }

    return true;
}

void Method_area::set_frame_stack(Frame_stack *new_frame_stack) {
    frame_stack = new_frame_stack;
}