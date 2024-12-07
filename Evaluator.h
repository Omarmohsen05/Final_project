#ifndef EVALUATOR_H
#define EVALUATOR_H
 
#include <string> // For std::string
 
class Evaluator {
public:
    // Public method to evaluate an infix expression
    int eval(const std::string &expression);
 
private:
    // Private helper methods
    bool isOperator(char c);
    int getPrecedence(char op);
    bool isLeftAssociative(char op);
    std::string convertToPostfix(const std::string &expression);
    int evaluatePostfix(const std::string &postfix);
};
 
#endif // EVALUATOR_H