// Copyright[2023]<Copyright Arthea Valderrama>
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

using std::string;

class Matrix {
 public:
    Matrix();
    Matrix(size_t h, size_t w);
    Matrix(const Matrix& m);
    Matrix(Matrix&& m) noexcept;
    ~Matrix() { delete [] matrix; }

    Matrix& operator=(const Matrix& m);
    Matrix& operator=(Matrix&& m) noexcept;

    size_t setheight(size_t r) { return rows = r;}
    size_t setwidth(size_t c) { return cols = c; }

    size_t height() const { return rows; }
    size_t width() const { return cols; }
    size_t size() const { return height() * width(); }

    char& operator()(size_t r, size_t c);
    char& at(size_t r, size_t c);
    char* operator[](size_t r);
    const char& operator()(size_t r, size_t c) const;
    const char& at(size_t r, size_t c) const;
    const char* operator[](size_t r) const;

    Matrix& operator+=(const Matrix& rhs);

 private:
    size_t rows;
    size_t cols;
    char * matrix;
};

