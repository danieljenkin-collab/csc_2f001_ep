#include <iostream>
#include "apply.h"

int main(int argc, char* argv[]) {
    list_t* ast = new list_t;
   

    std::cout << ast->to_string() << std::endl; // should output (1 2 3)
    return 0;
}

