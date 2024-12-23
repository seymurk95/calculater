#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <string>
#include <vector>
#include <stdexcept>

// Определяет приоритет операций
int precedence(char op);

// Применяет операцию к двум числам
double applyOperation(double a, double b, char op);

// Разбирает строку выражения на числа и операторы
void parseExpression(const std::string& expression, std::vector<double>& numbers, std::vector<char>& operators);

// Вычисляет результат выражения
double evaluate(const std::vector<double>& numbers, const std::vector<char>& operators);

#endif // CALCULATOR_HPP

