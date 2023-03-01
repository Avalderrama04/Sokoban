// Copyright[2023]<Copyright Arthea Valderrama>
#include "matrix.hpp"
#include <algorithm>
#include <stdexcept>

Matrix::Matrix() {
    rows = 0;
    cols = 0;
}

Matrix::Matrix(size_t h, size_t w):
        rows(h), cols(w), matrix(new char[h * w]) {}

Matrix::Matrix(const Matrix& m):
        rows(m.rows), cols(m.cols), matrix(new char[m.size()]) {
    std::copy(m.matrix, m.matrix + m.size(), this->matrix);
}

Matrix::Matrix(Matrix&& m) noexcept:
        rows(m.rows), cols(m.cols), matrix(m.matrix) {
    m.matrix = nullptr;
}

Matrix& Matrix::operator=(const Matrix& m) {
    if (this != &m) {
        char* data = new char[m.size()];
        delete [] this->matrix;
        this->matrix = data;
        this->rows = m.rows;
        this->cols = m.cols;
        std::copy(m.matrix, m.matrix + m.size(), this->matrix);
    }
    return *this;
}

Matrix& Matrix::operator=(Matrix&& m) noexcept {
    if (this != &m) {
        this->rows = m.rows;
        this->cols = m.cols;
        delete [] this->matrix;
        this->matrix = m.matrix;
        m.matrix = nullptr;
    }
    return *this;
}

char& Matrix::operator()(size_t r, size_t c) {
    return matrix[r * cols + c];
}

char& Matrix::at(size_t r, size_t c) {
    if (r >= rows || c >= cols) {
        throw std::out_of_range("Parameters out of bounds!");
    }
    return matrix[r * cols + c];
}

char* Matrix::operator[](size_t r) {
    return &matrix[r * cols];
}

const char& Matrix::operator()(size_t r, size_t c) const {
    return matrix[r * cols + c];
}

const char& Matrix::at(size_t r, size_t c) const {
    if (r >= rows || c >= cols) {
        throw std::out_of_range("Parameters out of bounds!");
    }
    return matrix[r * cols + c];
}

const char* Matrix::operator[](size_t r) const {
    return &matrix[r * cols];
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.height() != rhs.height() || lhs.width() != rhs.width()) {
        throw std::invalid_argument("Matrix dimensions don't match");
    }
    Matrix result(lhs.height(), lhs.width());
    for (size_t r = 0; r < lhs.height(); r++) {
        for (size_t c = 0; c < lhs.width(); c++) {
            result(r, c) = lhs(r, c) + rhs(r, c);
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& rhs) {
    if (height() != rhs.height() || width() != rhs.width()) {
        throw std::invalid_argument("Matrix dimensions don't match");
    }
    for (size_t r = 0; r < height(); r++) {
        for (size_t c = 0; c < width(); c++) {
            (*this)(r, c) += rhs(r, c);
        }
    }
    return *this;
}

