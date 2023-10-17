//
// Created by Nikita Nosov on 21/9/23.
//

#include "../include/text.h"
#include <iostream>
#include "../include/matrix.h"

const std::string RED_COLOR = "\x1B[31m";
const std::string GREEN_COLOR = "\x1B[32m";
const std::string PURPLE_COLOR = "\x1B[35m";
const std::string RESET_COLOR = "\x1B[0m";

///These functions are all about matrix
void Text::matrix_menu() {
    std::cout << PURPLE_COLOR << "[MATRIX CALCULATOR] " << RESET_COLOR << "Choose an option:\n";
    std::cout << GREEN_COLOR << "[" << RESET_COLOR << "1" << GREEN_COLOR << "]." << RESET_COLOR << " Sum\n"
              << GREEN_COLOR << "[" << RESET_COLOR << "2" << GREEN_COLOR << "]." << RESET_COLOR
              << " Difference\n"
              << GREEN_COLOR << "[" << RESET_COLOR << "3" << GREEN_COLOR << "]." << RESET_COLOR << " Product\n"
              << GREEN_COLOR << "[" << RESET_COLOR << "4" << GREEN_COLOR << "]." << RESET_COLOR
              << " Transpose\n"
              << GREEN_COLOR << "[" << RESET_COLOR << "5" << GREEN_COLOR << "]." << RESET_COLOR << " Multiply on a number\n"
              << GREEN_COLOR << "[" << RESET_COLOR << "6" << GREEN_COLOR << "]." << RESET_COLOR << " Equation system by Crammer\n"
              << GREEN_COLOR << "[" << RESET_COLOR << "7" << GREEN_COLOR << "]." << RESET_COLOR << " Determinant\n"
              << GREEN_COLOR << "[" << RESET_COLOR << "8" << GREEN_COLOR << "]." << RESET_COLOR << " Quit\n"
              << RED_COLOR << "\n[ELSE]. Test" << RESET_COLOR << "\n";

    std::cout << "\nOption: ";
}

void Text::matrix_sum() {
    int rows, cols;
    std::cout << "Rows: ";
    std::cin >> rows;
    std::cout << "Cols: ";
    std::cin >> cols;
    std::cout << "\n";

    Matrix mtx1(rows, cols);
    mtx1.inputMatrix();

    std::cout << "\n";

    Matrix mtx2(rows, cols);
    mtx2.inputMatrix();

    Matrix res = mtx1 + mtx2;
    std::cout << "\nResult:\n";
    res.printMatrix();
    std::cout << "\n";
}

void Text::matrix_diff() {
    int rows, cols;
    std::cout << "Rows: ";
    std::cin >> rows;
    std::cout << "Cols: ";
    std::cin >> cols;
    std::cout << "\n";

    Matrix mtx1(rows, cols);
    mtx1.inputMatrix();

    std::cout << "\n";

    Matrix mtx2(rows, cols);
    mtx2.inputMatrix();

    Matrix res = mtx1 - mtx2;
    std::cout << "\nResult:\n";
    res.printMatrix();
    std::cout << "\n";
}

void Text::matrix_prod() {
    int rows1, cols1;
    std::cout << "\n[FIRST MATRIX]\n";
    std::cout << "Rows: ";
    std::cin >> rows1;
    std::cout << "Cols: ";
    std::cin >> cols1;
    std::cout << "\n";

    int rows2, cols2;
    std::cout << "\n[SECOND MATRIX]\n";
    std::cout << "Rows: ";
    std::cin >> rows2;
    std::cout << "Cols: ";
    std::cin >> cols2;
    std::cout << "\n";

    Matrix mtx1(rows1, cols1);
    mtx1.inputMatrix();

    std::cout << "\n";

    Matrix mtx2(rows2, cols2);
    mtx2.inputMatrix();

    Matrix res = mtx1 | mtx2;
    std::cout << "\nResult:\n";
    res.printMatrix();
    std::cout << "\n";
}

void Text::matrix_transpose() {
    int rows, cols;
    std::cout << "Rows: ";
    std::cin >> rows;
    std::cout << "Cols: ";
    std::cin >> cols;
    std::cout << "\n";

    Matrix mtx1(rows, cols);
    mtx1.inputMatrix();

    std::cout << "\nResult:\n";

    Matrix res = mtx1.transpose();
    res.printMatrix();
    std::cout << "\n";
}

void Text::matrix_scale() {
    float num;
    std::cout << "\nInput a number: "; std::cin >> num;
    int rows, cols;
    std::cout << "Rows: ";
    std::cin >> rows;
    std::cout << "Cols: ";
    std::cin >> cols;
    std::cout << "\n";

    Matrix mtx1(rows, cols);
    mtx1.inputMatrix();

    std::cout << "\nResult:\n";

    Matrix res = mtx1.scaleMatrix(num);
    res.printMatrix();
    std::cout << "\n";
}

void Text::matrix_det() {
    int rows, cols;
    std::cout << "Rows: ";
    std::cin >> rows;
    std::cout << "Cols: ";
    std::cin >> cols;
    std::cout << "\n";

    Matrix mtx1(rows, cols);
    mtx1.inputMatrix();

    if (rows == 2 and cols == 2)
    {

        std::cout << "\nResult:\n";

        float res = mtx1.determinant_2_2();
        std::cout << res;
        std::cout << "\n\n";
    }
    else if (rows == 3 and cols == 3)
    {
        std::cout << "\nResult:\n";

        float res = mtx1.determinant_3_3();
        std::cout << res;
        std::cout << "\n\n";
    }
    else if (rows == 4 and cols == 4)
    {
        std::cout << "\nResult:\n";

        float res = mtx1.determinant_4_4();
        std::cout << res;
        std::cout << "\n\n";
    }
}

void Text::bye() {
    std::cout << PURPLE_COLOR << "\n[SEE YOU SOON BUDDY ^_^]\n" << RESET_COLOR;
}


///These functions are all about basics

void Text::basic_menu() {
    std::cout << PURPLE_COLOR << "[CALCULATOR] " << RESET_COLOR << "Choose an option:\n";
    std::cout << GREEN_COLOR << "[1]." << RESET_COLOR << " Addition\n"
              << GREEN_COLOR << "[2]." << RESET_COLOR << " Subtraction\n"
              << GREEN_COLOR << "[3]." << RESET_COLOR << " Multiplication\n"
              << GREEN_COLOR << "[4]." << RESET_COLOR << " Division\n"
              << GREEN_COLOR << "[5]." << RESET_COLOR << " Square\n"
              << GREEN_COLOR << "[6]." << RESET_COLOR << " Cube\n"
              << GREEN_COLOR << "[7]." << RESET_COLOR << " Remainder\n"
              << GREEN_COLOR << "[8]." << RESET_COLOR << " Quit\n"
              << RED_COLOR << "\n[ELSE]. Test" << RESET_COLOR << "\n";

    std::cout << "\nOption: ";
}