// matrix.cpp

#include "matrix.h"
#include <random>

Matrix::Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
    data = new int*[m];
    for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];
    }
}

Matrix::~Matrix() {
    for (unsigned int i = 0; i < m; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int& Matrix::operator()(unsigned int row, unsigned int col) {
    return data[row][col];
}

const int& Matrix::operator()(unsigned int row, unsigned int col) const {
    return data[row][col];
}

void Matrix::randomMatrix() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 9);

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] = dist(gen);
        }
    }
}


Matrix& Matrix::operator+=(const Matrix& other) {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            (*this)(i, j) += other(i, j);
        }
    }
    
    return *this;
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(m, n);
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    
    return result;
}



Matrix& Matrix::operator-=(const Matrix& other) {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            (*this)(i, j) -= other(i, j);
        }
    }
    return *this;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(m, n);

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            result(i, j) = (*this)(i, j) - other(i, j);
        }
    }
    return result;
}


Matrix::Matrix(const Matrix& other) : m(other.m), n(other.n) {
    data = new int*[m];
    for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];
        std::copy(other.data[i], other.data[i] + n, data[i]);
    }
}


Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (unsigned int i = 0; i < m; ++i) {
            delete[] data[i];
        }
        delete[] data;
        m = other.m;
        n = other.n;
        data = new int*[m];
        for (unsigned int i = 0; i < m; ++i) {
            data[i] = new int[n];
            std::copy(other.data[i], other.data[i] + n, data[i]);
        }
    }
    return *this;
}


Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(m, other.n);

    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < other.n; ++j) {
            for (unsigned int k = 0; k < n; ++k) {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }

    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            if (data[i][j] != other(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.m; ++i) {
        for (unsigned int j = 0; j < matrix.n; ++j) {
            os << matrix(i, j) << ' ';
        }
        os << std::endl;
    }
    return os;
}
