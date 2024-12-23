#include <iostream>
#include <string>
#include <vector>
#include "calc.hpp"

int main() {
    while (true) {
        try {
            std::cout << "Enter expression: ";
            std::string expression;
            std::getline(std::cin, expression);

            std::vector<double> numbers;
            std::vector<char> operators;

            parseExpression(expression, numbers, operators);

            double result = evaluate(numbers, operators);

            std::cout << "Result: " << result << std::endl;

        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
