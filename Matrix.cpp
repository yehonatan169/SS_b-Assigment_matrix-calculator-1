
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdexcept>
#include "Matrix.hpp"

using namespace std;

namespace zich {
    // void checkThrows(const Matrix &matrix1, const Matrix &matrix2)
    // {
    //     if (matrix1.columns != matrix2.columns || matrix1.rows != matrix2.rows)
    //     {
    //         throw invalid_argument("matrix is with different size");
    //     }
    // }
    // void checkMul(const Matrix &matrix1, const Matrix &matrix2)
    // {
    //     if (matrix1.columns != matrix2.rows)
    //     {
    //         throw invalid_argument("matrix is with different size");
    //     }
    // }
    /* Input and Output operators*/


    Matrix::Matrix(vector<double> vec, int rows, int columns) {
        this->row = rows;
        this->column = columns;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                this->mat[i][j] = vec[(double) (j + i * (this->column))];
            }
        }

    }

    ostream &operator<<(ostream &out, const Matrix &matrix) {
        return out;
    }

    istream &operator>>(istream &in, Matrix &matrix) {
        return in;
    }

    /* Arithmetic operators */
    Matrix Matrix::operator+(const Matrix &mat) {
        return mat;
    }

    Matrix Matrix::operator+()// unari
    {
        return *this;
    }

    Matrix Matrix::operator+=(const Matrix &mat2) {
        return mat2;
    }

    Matrix Matrix::operator-(const Matrix &mat2) {
        return mat2;
    }

    Matrix Matrix::operator-()// unari
    {
        return *this;
    }

    Matrix Matrix::operator-=(const Matrix &mat2) {
        return mat2;
    }

    /* comparison operators */
    bool Matrix::operator>(const Matrix &mat2) {
        return true;
    }

    bool Matrix::operator>=(const Matrix &mat2) {
        return true;
    }

    bool Matrix::operator<(const Matrix &mat2) {
        return true;
    }

    bool Matrix::operator<=(const Matrix &mat2) {
        return true;
    }

    bool Matrix::operator==(const Matrix &mat2) {
        return true;
    }

    bool Matrix::operator!=(const Matrix &mat2) {
        return false;
    }

    /* Increment operations */
    Matrix Matrix::operator++() {
        return *this;
    }

    Matrix Matrix::operator--() {
        return *this;
    }

    /* Multiplication operations */
    Matrix Matrix::operator*(const Matrix &mat2) {
        return mat2;
    }

    Matrix operator*(double num, Matrix &mat) {
        return mat;
    }

    Matrix Matrix::operator*=(const Matrix &mat2) {
        return *this;
    }

    Matrix Matrix::operator*=(double num) {
        return *this;
    }
}