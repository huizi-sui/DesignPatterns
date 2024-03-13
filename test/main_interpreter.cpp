
#include "Interpreter.hpp"

int main() {
    Context context(10);
    PlusExpression plusExpression;
    MinusExpression minusExpression;

    Expression& expression1 = plusExpression;
    Expression& expression2 = minusExpression;

    expression1.interpreter(context);
    std::cout << context.get_num() << std::endl;

    expression2.interpreter(context);
    std::cout << context.get_num() << std::endl;

    return 0;
}