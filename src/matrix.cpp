//
// Created by Nikita Nosov on 21/9/23.
//

#include "../include/matrix.h"

const std::string RED_COLOR = "\x1B[31m";
const std::string GREEN_COLOR = "\x1B[32m";
const std::string PURPLE_COLOR = "\x1B[35m";
const std::string RESET_COLOR = "\x1B[0m";

void Matrix::inputMatrix() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Element: (" << i + 1 << ", " << j + 1 << "): ";
            std::cin >> matrix[i][j];
        }
    }
}

void Matrix::printMatrix() const {
    std::cout << GREEN_COLOR;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << RESET_COLOR;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = matrix[j][i];
        }
    }
    return result;
}

Matrix Matrix::scaleMatrix(float num) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = matrix[i][j] * num;
        }
    }
    return result;
}

float Matrix::determinant_2_2() const {
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

float Matrix::determinant_3_3() const {
    return (matrix[0][0] * matrix[1][1] * matrix[2][2] +
            matrix[0][1] * matrix[1][2] * matrix[2][0] +
            matrix[0][2] * matrix[1][0] * matrix[2][1] -
            matrix[0][1] * matrix[1][0] * matrix[2][2] -
            matrix[0][0] * matrix[1][2] * matrix[2][1] -
            matrix[0][2] * matrix[1][1] * matrix[2][0]
            );
}

float Matrix::determinant_4_4() const {
    float det = 0.0;
    float sign = 1;

    for (int i = 0; i < 4; i++) {
        Matrix minor(3,3);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                minor.matrix[j][k] = matrix[j + 1][(i + k) % 4];
            }
        }
        float minor_det = minor.determinant_3_3();
        det += sign * matrix[0][1] * minor_det;
        sign = -sign;
    }
    return det;
}

void Matrix::fill(std::vector<float> values) const {

    if (rows + cols < values.size() || rows + cols < values.size())
    {
        std::cout << RED_COLOR << "\n[Incorrect quantity of matrix elements]\n" << RESET_COLOR;
        std::cout << PURPLE_COLOR << "Program is going to work in a wrong way!\n\n" << RESET_COLOR;
    }

    int vec_ind = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = values[vec_ind];
            vec_ind++;
        }
    }
}

Matrix Matrix::inverse_2_2() const {
    float det = determinant_2_2();
    Matrix inv(2,2);
    inv.fill({matrix[1][1], -matrix[1][0], -matrix[0][1], matrix[0][0]});
    Matrix inv_t = inv.transpose();
    return inv_t.scaleMatrix((1/det));
}

Matrix Matrix::operator+(const Matrix &other) const {
    if (rows != other.rows || cols != other.cols) {
        std::cout << RED_COLOR; std::cout << "\n[Matrix must be identical]\n"; std::cout << RESET_COLOR;
        return {0,0};
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
    if (rows != other.rows || cols != other.cols) {
        std::cout << RED_COLOR; std::cout << "\n[Matrix must be identical]\n"; std::cout << RESET_COLOR;
        return {0, 0};
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator|(const Matrix &other) const {
    if (cols != other.rows) {
        std::cout << RED_COLOR; std::cout << "\n[Cannot multiply these matrices]\n"; std::cout << RESET_COLOR;
        return {0, 0};
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

float *Matrix::operator[](int index) const {
    return matrix[index].get();
}


