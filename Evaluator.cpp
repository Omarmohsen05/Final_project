#include "Evaluator.h"
#include <stack>
#include <stdexcept>
#include <cmath>   
 
bool Evaluator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ||
           c == '<' || c == '>' || c == '=' || c == '&' || c == '|';
}
 
int Evaluator::getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    if (op == '<' || op == '>' || op == '=') return 0;
    return -1;
}
 
bool Evaluator::isLeftAssociative(char op) {
    return op != '^'; // Power operator is right-associative
}
 
std::string Evaluator::convertToPostfix(const std::string &expression) {
    std::stack<char> operators;
    std::string postfix;
 
    for (size_t i = 0; i < expression.size(); i++) {
        char c = expression[i];
 
        if (isdigit(c)) {
            // Append numbers directly to postfix
            while (i < expression.size() && isdigit(expression[i])) {
                postfix += expression[i++];
            }
            postfix += ' '; // Space to separate numbers
            i--; // Adjust for overshoot
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            if (!operators.empty()) operators.pop();
        } else if (isOperator(c)) {
            while (!operators.empty() &&
                   getPrecedence(operators.top()) >= getPrecedence(c) &&
                   isLeftAssociative(operators.top())) {
                postfix += operators.top();
                postfix += ' ';
                operators.pop();
            }
            operators.push(c);
        }
    }
 
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += ' ';
        operators.pop();
    }
 
    return postfix;
}
 
int Evaluator::evaluatePostfix(const std::string &postfix) {
    std::stack<int> operands;
 
    for (size_t i = 0; i < postfix.size(); i++) {
        char c = postfix[i];
 
        if (isdigit(c)) {
            int num = 0;
            while (i < postfix.size() && isdigit(postfix[i])) {
                num = num * 10 + (postfix[i++] - '0');
            }
            operands.push(num);
        } else if (isOperator(c)) {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
 
            switch (c) {
                case '+': operands.push(a + b); break;
                case '-': operands.push(a - b); break;
                case '*': operands.push(a * b); break;
                case '/': 
                    if (b == 0) throw std::runtime_error("Division by zero");
                    operands.push(a / b); 
                    break;
                case '^': operands.push(pow(a, b)); break;
            }
        }
    }
 
    return operands.top();
}
 
int Evaluator::eval(const std::string &expression) {
    std::string postfix = convertToPostfix(expression);
    return evaluatePostfix(postfix);
}

