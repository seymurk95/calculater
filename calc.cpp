#include "calc.hpp"
#include <sstream>
#include <cmath>
#include <string>
#include <cctype>
#include <limits>

void checkOverflow(double value) {
    if (std::isinf(value)) {
        throw std::overflow_error("Value is too large or too small to be represented as a double");
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

double applyOperation(double a, double b, char op) {
    checkOverflow(a);
    checkOverflow(b);
    double result;
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        case '^': return std::pow(a, b);
        default: throw std::invalid_argument("Unknown operator");
    }
    checkOverflow(result);
    return result;
}

void parseExpression(const std::string& expression, std::vector<double>& numbers, std::vector<char>& operators) {
    std::istringstream iss(expression);
    double number;
    char op;

    if (!(iss >> number)) {
        throw std::invalid_argument("Incorrect input: expected number");
    }
    checkOverflow(number);
    numbers.push_back(number);

    while (iss >> op) {
        if (std::string("+-*/^").find(op) == std::string::npos) {
            throw std::invalid_argument("Unknown operator: " + std::string(1, op));
        }
        operators.push_back(op);

        if (!(iss >> number)) {
            throw std::invalid_argument("Incorrect input: expected operator after the number");
        }
        checkOverflow(number);
        numbers.push_back(number);
    }
}

double evaluate(const std::vector<double>& numbers, const std::vector<char>& operators) {
    std::vector<double> nums = numbers;
    std::vector<char> ops = operators;

    for (size_t i = 0; i < ops.size(); ++i) {
        if (ops[i] == '^') {
            nums[i] = applyOperation(nums[i], nums[i + 1], ops[i]);
            nums.erase(nums.begin() + i + 1);
            ops.erase(ops.begin() + i);
            --i;
        }
    }

    for (size_t i = 0; i < ops.size(); ++i) {
        if (ops[i] == '*' || ops[i] == '/') {
            nums[i] = applyOperation(nums[i], nums[i + 1], ops[i]);
            nums.erase(nums.begin() + i + 1);
            ops.erase(ops.begin() + i);
            --i;
        }
    }

    for (size_t i = 0; i < ops.size(); ++i) {
        if (ops[i] == '+' || ops[i] == '-') {
            nums[i] = applyOperation(nums[i], nums[i + 1], ops[i]);
            nums.erase(nums.begin() + i + 1);
            ops.erase(ops.begin() + i);
            --i;
        }
    }


    checkOverflow(nums[0]);
    return nums[0];
}
