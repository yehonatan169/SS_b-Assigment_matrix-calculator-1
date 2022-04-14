
#ifndef MATRIX_CALCULATOR_A_MATRIX_H
#define MATRIX_CALCULATOR_A_MATRIX_H
#pragma one

#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;
namespace zich {

    class Matrix {
    private:
        int row;
        int column;
        map<int, map<int, int>> mat;
    public:
        Matrix(vector<double> vec, int rows, int columns);

        /* Input and Output operators Declarations*/
        friend ostream &operator<<(ostream &out, const Matrix &mat);

        friend istream &operator>>(istream &in, Matrix &mat);

        /* Arithmetic operators Declarations */
        Matrix operator+(const Matrix &mat);

        Matrix operator+();// unari

        Matrix operator+=(const Matrix &mat2);

        Matrix operator-(const Matrix &mat2);

        Matrix operator-();//unari

        Matrix operator-=(const Matrix &mat2);

        /* comparison operators Declarations */
        bool operator>(const Matrix &mat2);

        bool operator>=(const Matrix &mat2);

        bool operator<(const Matrix &mat2);

        bool operator<=(const Matrix &mat2);

        bool operator==(const Matrix &mat2);

        bool operator!=(const Matrix &mat2);

        /* Increment operations Declarations */
        Matrix operator++();

        Matrix operator--();

        /* Multiplication operations Declarations */
        Matrix operator*(const Matrix &mat2);

        friend Matrix operator*(double num, Matrix &mat);

        Matrix operator*=(const Matrix &mat2);

        Matrix operator*=(double num);

    };
}

#endif //MATRIX_CALCULATOR_A_MATRIX_H
