#ifndef LOCAL_VARIABLE
#define LOCAL_VARIABLE

#include <vector>

#include "Base_types.hpp"
#include "Element.hpp"
#include "Typed_element.hpp"
#include "Operand_stack.hpp"

using namespace std;



class Local_variable {
    public:
        vector<Element> elements;
        vector<U1> types;
        const U2 max;
        // const U2 real_max;
        // const bool two_slots;
    // Local_variable(U2);
    // Local_variable(U2);
    // Local_variable(U2, bool);
    // ~Local_variable();
    int Local_variable::get_max() const;
    void display_all() const;
    void insert_typed_element(Typed_element, int);
    Typed_element get_typed_element(int);
};


#endif