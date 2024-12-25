 Calculator

The program realizes simple calculator that supports basic arithmetic operations, including addition, subtraction, multiplication, division, and exponentiation. The program is split into a main executable for user interaction and a library for the calculator's core logic.

## Features

- Supports operations: `+`, `-`, `*`, `/`, `^`
- Handles operator precedence correctly (e.g., multiplication and division before addition and subtraction)
- Includes input validation to ensure valid expressions
- Throws informative error messages for invalid inputs or operations (e.g., division by zero)
- Unit tested using the [doctest](https://github.com/doctest/doctest) library

## Structure

The project consists of the following files:
- `main.cpp`: Contains the user interface logic (input/output).
- `calculator.hpp`: Header file defining the calculator's functions.
- `calculator.cpp`: Implementation of the calculator's core logic.
- `test.cpp`: Unit tests for the calculator logic using `doctest`(https://github.com/doctest/doctest).
- `CMakeLists.txt`: Build configuration for CMake.

## Steps to compile:

Clone the repository or copy the files.
Create a CMakeLists.txt file for easier compilation (the example is added in this repository ( CMakeLists.txt file))

## Example Output

Enter expression:4+-8*-1^3

Result: 12

Enter expression:4/0

Error: Division by zero

