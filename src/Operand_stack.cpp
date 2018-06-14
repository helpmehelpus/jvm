#include "Operand_stack.hpp"

Operand_stack::Operand_stack(int maximum_size) : max_size(maximum_size), real_max_size(2*maximum_size) {
    typed_element_pushed = false;
};

