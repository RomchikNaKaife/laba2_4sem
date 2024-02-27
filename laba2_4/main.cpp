// main.cpp

#include "matrix.h"
#include <iostream>

int main() {
    Matrix matrix1(3, 3);
    matrix1.randomMatrix();
    std::cout << "Матрица 1:\n" << matrix1 << std::endl;

    Matrix matrix2(3, 3);
    matrix2.randomMatrix();
    std::cout << "Матрица 2:\n" << matrix2 << std::endl;

    Matrix addition = matrix1 + matrix2;
    std::cout << "Матрица 1 + Матрица 2:\n" << addition << std::endl;
    
    Matrix sum = matrix1;
    sum += matrix2;
    std::cout << "Матрица 1 += Матрица 2:\n" << sum << std::endl;

    Matrix subtraction = matrix1 - matrix2;
    std::cout << "Матрица 1 - Матрица 2:\n" << subtraction<< std::endl;
        
    Matrix minus = matrix1;
    minus -= matrix2;
    std::cout << "Матрица 1 -= Матрица 2:\n" << minus << std::endl;
    
    Matrix multiplication = matrix1 * matrix2;
    std::cout << "Матрица 1 * Матрица 2:\n" << multiplication << std::endl;
    
    bool equality = matrix1 == matrix2;
    if (equality) {
        std::cout << "Матрица 1 равна Матрице 2:\n" << std::endl;
    }
    
    bool unequality = matrix1 != matrix2;
    if (unequality) {
        std::cout << "Матрица 1  не равна Матрице 2\n" << std::endl;
    }
    

    

    return 0;
}
