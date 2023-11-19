# Overview

This project implements a calculator application with support for basic arithmetic operations, matrix math, and probability distributions.

## Main Components

### text.h/.cpp
Contains Text class with methods to print menus and execute math operations.

- `matrix_menu()` - Prints menu for matrix operations
- `matrix_sum()` - Adds two matrices
- `matrix_diff()` - Subtracts two matrices
- `matrix_prod()` - Multiplies two matrices
- `matrix_transpose()` - Transposes a matrix
- `matrix_scale()` - Multiplies a matrix by a scalar
- `matrix_det()` - Calculates determinant of a matrix
- `basic_menu()` - Prints menu for basic arithmetic
- `bye()` - Prints goodbye message

### matrix.h/.cpp
Contains Matrix class to represent matrices and perform operations.

- `inputMatrix()` - Inputs matrix values from user
- `printMatrix()` - Prints matrix contents
- `transpose()` - Returns transpose of matrix
- `scaleMatrix()` - Returns matrix multiplied by scalar
- `determinant_2_2()` - 2x2 determinant
- `determinant_3_3()` - 3x3 determinant
- `determinant_4_4()` - 4x4 determinant
- `fill()` - Fills matrix from vector
- `inverse_2_2()` - Finds inverse of 2x2 matrix
- `operator+` - Overloaded + for matrix addition
- `operator-` - Overloaded - for matrix subtraction
- `operator|` - Overloaded | for matrix multiplication
- `operator[]` - Overloaded [] for element access

### crammer.h/.cpp
Implements Cramer's rule for solving a system of linear equations.

- `get_ratio()` - Parses equation string into coefficient ratios
- `is_correct()` - Checks format of equation
- `start_crammer()` - Implements Cramer's rule

### probSolver.h/.cpp
Computes probability mass functions for various discrete distributions.

- `factorial()` - Computes factorial
- `bernoulli()` - Bernoulli distribution PMF
- `poisson()` - Poisson distribution PMF
- `laplace_local()` - Localized Laplace distribution PMF

### main.cpp
Entry point and main application loop.

- Sets up signal handler for keyboard interrupt
- Prints operation menus and reads user input
- Calls appropriate functions based on input
- Loops until the user quits

The code demonstrates good practices like separating interface and implementation (text vs matrix), overloading operators, and using const correctness. Overall, it provides a useful set of math utilities in an easy-to-use application.
