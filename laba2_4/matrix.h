// matrix.h

#ifndef matrix_h
#define matrix_h

#include <iostream>

class Matrix {
public:
    Matrix(unsigned int m, unsigned int n);
    ~Matrix();
    

    int& operator()(unsigned int row, unsigned int col);
    const int& operator()(unsigned int row, unsigned int col) const;

    void randomMatrix();
    
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix operator+(const Matrix& other) const;
    Matrix& operator-=(const Matrix& other);
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
    unsigned int m;
    unsigned int n;
    int** data;
};

#endif
