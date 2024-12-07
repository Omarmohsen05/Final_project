# Final_project

1. Utility Functions

- **`isOperator(char c)`**: Checks if a character is a valid operator, such as `+`, `-`, `*`, `/`, etc.
- **`getPrecedence(char op)`**: Assigns precedence to operators to determine their execution order (e.g., `^` has the highest precedence, followed by `*` and `/`, then `+` and `-`).
- **`isLeftAssociative(char op)`**: Determines if an operator is left-associative. Most operators are, except for the power operator (`^`), which is right-associative.

2. Conversion from Infix to Postfix

- `convertToPostfix(const std::string &expression)`:
  - Converts an infix mathematical expression (e.g., `3 + 5 * 2`) into postfix notation (e.g., `3 5 2 * +`).
  - Uses a stack to temporarily hold operators while processing the input.
  - Digits are directly added to the resulting postfix string, separated by spaces for clarity.
  - Operators are added to the result based on precedence and associativity rules.
  - Parentheses are managed by pushing `(` onto the stack and popping operators until `)` is encountered.

3. Postfix Evaluation

- `evaluatePostfix(const std::string &postfix)`:
  - Evaluates a postfix expression using a stack to store intermediate results.
  - Numbers are pushed onto the stack when encountered.
  - When an operator is encountered, two operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack.
  - Handles basic operators (`+`, `-`, `*`, `/`, `^`), with division checking for zero to avoid runtime errors.

4. End-to-End Evaluation

- `eval(const std::string &expression)`:
  - Combines the above steps to evaluate a full mathematical expression.
  - First converts the input string to postfix notation using `convertToPostfix`.
  - Then evaluates the postfix expression using `evaluatePostfix`.
  - Returns the final computed result.

Key Concepts Used:

- **Stack Data Structure**: Used for both operator precedence management in infix-to-postfix conversion and for evaluating postfix expressions.
- **Operator Precedence and Associativity**: Ensures operations are performed in the correct order.
- **Error Handling**: Includes runtime checks for division by zero.

This implementation effectively separates the parsing (conversion to postfix) and computation (evaluation of postfix) steps, making it easier to debug and extend.
