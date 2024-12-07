#include <iostream>
#include "Evaluator.h"
 
int main() {
    Evaluator eval;
 
    try {
        std::cout << "Result of 1+2*3: " << eval.eval("1+2*3") << std::endl;
        std::cout << "Result of (1+2)*3: " << eval.eval("(1+2)*3") << std::endl;
        std::cout << "Result of 2+2^2*3: " << eval.eval("2+2^2*3") << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
 
    return 0;
}