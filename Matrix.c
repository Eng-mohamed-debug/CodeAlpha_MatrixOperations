#include "Matrix.h"

Matrix INVALID_MATRIX = {
    0,
    0,
    1,
    NULL
}; // make this matrix to handle errors

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
    Matrix result = createMatrix(A.rows, A.cols);
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
        {
            result.data[i][j] = A.data[i][j] + B.data[i][j];
        }
    }
    return result;
}

Matrix transpose(Matrix mat)
{
    Matrix result = createMatrix(mat.cols, mat.rows);
    for(int i = 0; i < result.rows; i++)
    {
        for(int j = 0; j < result.cols; j++)
        {
            result.data[i][j] = mat.data[j][i];
        }
    }
    return result;
}

void printMatrix(Matrix mat, char* element_sep, char* rows_sep)
{
    for(int i = 0; i < mat.rows; i++)
    {
        for(int j = 0; j < mat.cols; j++)
        {
            printf(element_sep);
        }
        printf(rows_sep);
    }
}

void freeMatrix(Matrix* mat)
{
    for(int i = 0; i < mat->rows; i++)
    {
        free(mat->data[i]);
    }
    free(mat->data);
    mat->data = NULL;
}