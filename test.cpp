#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "calc.hpp"
#include "doctest.h"
#include <string>
#include <vector>
TEST_SUITE("calc") {


    TEST_CASE("precedence") {
       CHECK(precedence('+') == 1);
       CHECK(precedence('-')==1);
        CHECK(precedence('*')==2);
        CHECK(precedence('/')==2);
        CHECK(precedence('^')==3);
        CHECK(precedence('&')==0);

    }


    TEST_CASE("operation") {
        CHECK(applyOperation(3, 2, '+') == 5);
        CHECK(applyOperation(3, 2, '-') == 1);
        CHECK(applyOperation(3, 2, '*') == 6);
        CHECK(applyOperation(6, 2, '/') == 3);
        CHECK(applyOperation(2, 3, '^') == doctest::Approx(8));
        CHECK_THROWS_WITH(applyOperation(3, 0, '/'), "Division by zero");
        CHECK_THROWS_WITH(applyOperation(3, 2, 'x'), "Unknown operator");
    }


    TEST_CASE("parseExpression") {
        std::vector<double> numbers;
        std::vector<char> operators;

        parseExpression("3 + 5 * 2", numbers, operators);
        CHECK(numbers == std::vector<double>{3, 5, 2});
        CHECK(operators == std::vector<char>{'+', '*'});

        CHECK_THROWS_WITH(parseExpression("3 & 5", numbers, operators), "Unknown operator: &");

        CHECK_THROWS_WITH(parseExpression("3 +", numbers, operators), "Incorrect input: expected operator after the number");

        CHECK_THROWS_WITH(parseExpression("abc", numbers, operators), "Incorrect input: expected number");

    }


    TEST_CASE("Testing evaluate function") {
        std::vector<double> numbers;
        std::vector<char> operators;

        SUBCASE("Simple addition") {
            parseExpression("3 + 5", numbers, operators);
            CHECK(evaluate(numbers, operators) == 8);
        }

        SUBCASE("Mixed operators") {
            parseExpression("3 + 5 * 2", numbers, operators);
            CHECK(evaluate(numbers, operators) == 13); // 3 + (5 * 2)
        }

        SUBCASE("Exponentiation") {
            parseExpression("2 ^ 3 + 1", numbers, operators);
            CHECK(evaluate(numbers, operators) == 9); // (2 ^ 3) + 1
        }

        SUBCASE("Division and multiplication") {
            parseExpression("10 / 2 * 3", numbers, operators);
            CHECK(evaluate(numbers, operators) == 15); // (10 / 2) * 3
        }
    }
}
