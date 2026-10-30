#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int rows;
    int cols;
    int* data;

public:
    Matrix(int rows, int cols, int value);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);
    ~Matrix();

    int& operator()(int row, int col);
    const int& operator()(int row, int col) const;
};

#endif
