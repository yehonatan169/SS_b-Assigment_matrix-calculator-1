#include "doctest.h"
#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>

using namespace zich;
using namespace std;

TEST_CASE ("Arithmetic operators and increment/decrement")
{
    std::vector<double> arr1 = {1,2,3,4,5,6,7,8,9};
    std::vector<double> arr2 = {1,0,0,0,1,0,0,0,1};
    std::vector<double> arr3 = {1,3,5,7,9,11};
    std::vector<double> arr4 = {2,2,3,4,6,6,7,8,10};


    Matrix m1{arr1, 3, 3};
    Matrix m2{arr2, 3, 3};
    Matrix m3{arr3, 3, 2};
    Matrix m4{arr4, 3, 3};

            SUBCASE("Bad Case") {
        CHECK_THROWS(m1 + m3);
        CHECK_THROWS(m3 += m2);
        CHECK_THROWS(m1 - m3);
        CHECK_THROWS(m2 -= m3);
        CHECK_THROWS(m4 + m3);
        CHECK_THROWS(m3 += m4);
        CHECK_THROWS(m4 - m3);

    }
            SUBCASE("Good Case") {
        CHECK_NOTHROW(m1 + m2);
        CHECK_NOTHROW(m1 += m2);
        CHECK_NOTHROW(m2 += m1);
        CHECK_NOTHROW(m2 - m1);
        CHECK_NOTHROW(m2 -= m1);
        CHECK_NOTHROW(-m1);
                CHECK_EQ(m4 == m1, true);
        CHECK_NOTHROW(+m1);
                CHECK_EQ(+m1 == m1 , true);
        CHECK_NOTHROW(++m2);
        CHECK_NOTHROW(--m2);
    }



}

TEST_CASE ("Input and Output operators")
{
    std::vector<double> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<double> arr2 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix m1{arr1, 3, 3};
    Matrix m2{arr2, 3, 3};
    CHECK_NOTHROW(cout << m1 + m2);
    CHECK_NOTHROW(cout << m2);

}

TEST_CASE ("Comparison operators operators")
{
    std::vector<double> arr1 = {1,2,3,4,5,6,7,8,9};
    std::vector<double> arr2 = {1,0,0,0,1,0,0,0,1};
    std::vector<double> arr3 = {2,2,3,4,6,6,7,8,10};
    std::vector<double> arr4 = {1,0,0,0,1,0,0,0,1};
    std::vector<double> arr5 = {1,0,0,1,0,0,0,1};

    Matrix m1{arr1, 3, 3};
    Matrix m2{arr2, 3, 3};
    Matrix m3{arr3, 3, 3};
    Matrix m4{arr4, 3, 3};
    Matrix m5{arr5, 4, 2};

            SUBCASE("Bad Case") {
                CHECK_EQ(m1 < m2, false);
                CHECK_EQ(m1 <= m2, false);
                CHECK_EQ(m2 > m3, false);
                CHECK_EQ(m3 <= m2, false);

                CHECK_EQ(m2 == m1, false);
                CHECK_EQ(m4 != m2, false);
                CHECK_EQ(m2 == m4, false);
                CHECK_EQ(m4 != m2, false);
            }
            SUBCASE("Bad Case") {
                CHECK_EQ(m1 > m2, true);
                CHECK_EQ(m1 >= m2, true);
                CHECK_EQ(m1 < m2, false);
                CHECK_EQ(m1 <= m2, false);
                CHECK_EQ(m1 == m2, false);
                CHECK_EQ(m1 != m2, false);
            }

}

TEST_CASE ("Multiplication operations")
{
    std::vector<double> arr1 = {1,2,3,4,5,6,7,8,9,11,12,13};
    std::vector<double> arr2 = {1, 0, 0, 0, 1, 0, 0, 0, -1};
    std::vector<double> arr3 = {3, 0, 0, 0, 3, 0};
    Matrix m1{arr1, 3, 4};
    Matrix m2{arr3, 3, 2};
    Matrix m3{arr2, 3, 3};
    CHECK_THROWS(m1 * m2);
    CHECK_THROWS(m1 *= m2);
    CHECK_NOTHROW(3 * m2);
    CHECK_NOTHROW(m3 *= 3);
    CHECK_NOTHROW(m3 *= m2);
}