#include "Matrix.h"

Matrix createMatrix(int rows, int cols)
{
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.is_square = (rows == cols);

    mat.data = malloc(rows * sizeof(double *)); // Each row will be a pointer to an array (double pointer)
    for (int i = 0; i < rows; i++)
    {
        mat.data[i] = calloc(cols, sizeof(double)); // all elements will be initialized to zero
    }
    return mat;
};

int areEqual(Matrix A, Matrix B)
{
    if (A.rows != B.rows || A.cols != B.cols)
    {
        return 0;
    }
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            if (A.data[i][j] != B.data[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void multiplyScalar(Matrix mat, double scalar)
{
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            mat.data[i][j] *= scalar;
        }
    }
}

Matrix addMatrices(Matrix A, Matrix B)
{
    if (A.rows != B.rows || A.cols != B.cols)
    {
        return INVALID_MATRIX;
    }
    Matrix result = A;
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            A.data[i][j] += B.data[i][j];
        }
    }
    return result;
}