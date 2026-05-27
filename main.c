#include "Matrix.h"

int main(void)
{
    double A_data[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    double B_data[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    Matrix A = createMatrixFromArray(2, 3, A_data);
    Matrix B = createMatrixFromArray(3, 2, B_data);

    printf("Matrix A + B equals: \n");
    printMatrix(addMatrices(A, transpose(B)), " ", "\n");

    printf("**************************************************\n");

    printf("Transposed A equals: \n");
    printMatrix(transpose(A), " ", "\n");

    printf("**************************************************\n");


    printf("A x B = \n");
    printMatrix(multiplyMatrices(A, B), " ", "\n");

    return 0;
}