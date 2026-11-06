#include <iostream>
#include "apply.h"

int main(int argc, char* argv[]) {
    frame_t* frame = new frame_t;

    frame->set(new symbol_t { "a" }, new integer_t { 666 });
    frame->set(new symbol_t { "b" }, new integer_t { 21 });
    frame->set(new symbol_t { "a" }, new integer_t { 42 });

    std::cout << frame->to_string() << ": a=" << frame->get(new symbol_t { "a" })->to_string() << std::endl;
    return 0;
}

