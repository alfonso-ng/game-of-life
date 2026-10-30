#include "Matrix.hpp"
#include <stdexcept>

Matrix::Matrix(int _rows, int _cols, int value)
{
    rows = _rows;
    cols = _cols;
    data = new int[rows*cols]();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i*cols + j] = value;
        }
    }
}

Matrix::Matrix(const Matrix& other)
    : rows(other.rows), cols(other.cols)
{
    data = new int[rows * cols];

    for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this == &other)
        return *this;

    int *newData = new int[other.rows * other.cols];

    for (int i = 0; i < other.rows * other.cols; i++) {
        newData[i] = other.data[i];
    }

    delete [] data;

    rows = other.rows;
    cols = other.cols;
    data = newData;

    return *this;
}

Matrix::~Matrix()
{
    delete [] data;
}


int& Matrix::operator()(int row, int col)
{
    if (row < 0 || row >= rows || col < 0 || cols <= 0)
        throw std::out_of_range("Invalid index");

    return data[row*cols + col];
}

const int& Matrix::operator()(int row, int col) const
{
    if (row < 0 || row >= rows || col < 0 || cols <= 0)
        throw std::out_of_range("Invalid index");

    return data[row*cols + col];
}
