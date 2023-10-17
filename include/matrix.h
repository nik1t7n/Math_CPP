//
// Created by Nikita Nosov on 21/9/23.
//

#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H


#include <iostream>
#include <memory>

class Matrix {
public:
    int rows, cols;
    std::unique_ptr<std::unique_ptr<float[]>[]> matrix;

    Matrix(int r, int c): rows(r), cols(c) {
        matrix = std::make_unique<std::unique_ptr<float[]>[]>(rows);
        for (int i = 0; i < rows; i++) {
            matrix[i] = std::make_unique<float[]>(cols);
        }
    }

    void inputMatrix() const;
    void printMatrix() const;
    void fill(std::vector<float> values) const;


    [[nodiscard]] Matrix transpose() const;
    [[nodiscard]] Matrix scaleMatrix(float num) const;
    Matrix inverse_2_2() const;

    [[nodiscard]] float determinant_2_2() const;
    [[nodiscard]] float determinant_3_3() const;
    [[nodiscard]] float determinant_4_4() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator|(const Matrix& other) const;

    float* operator[](int index) const;
};


#endif //MATH_MATRIX_H
