#include "Matrix.h"

int main(void)
{
    double A_data[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    double B_data[3][2] = {
        {7, 8},
        {9, 10},
        {11, 12}};

    double C_data[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    Matrix A = createMatrixFromArray(2, 3, A_data);
    Matrix B = createMatrixFromArray(3, 2, B_data);
    Matrix C = createMatrixFromArray(2, 3, C_data);

    printf("Matrix A:\n");
    printMatrix(A, " ", "\n");

    printf("\n**************************************************\n\n");

    printf("Matrix B:\n");
    printMatrix(B, " ", "\n");

    printf("\n**************************************************\n\n");

    printf("A + transpose(B):\n");
    Matrix add_result = addMatrices(A, transpose(B));
    printMatrix(add_result, " ", "\n");

    printf("\n**************************************************\n\n");

    printf("transpose(A):\n");
    Matrix transposed_A = transpose(A);
    printMatrix(transposed_A, " ", "\n");

    printf("\n**************************************************\n\n");

    printf("A x B:\n");
    Matrix mul_result = multiplyMatrices(A, B);
    printMatrix(mul_result, " ", "\n");

    printf("\n**************************************************\n\n");

    printf("A before scalar multiplication:\n");
    printMatrix(A, " ", "\n");

    multiplyScalar(A, 2);

    printf("\nA after scalar multiplication by 2:\n");
    printMatrix(A, " ", "\n");

    printf("\n**************************************************\n\n");

    printf("A == C ? ");
    printf("%s\n", areEqual(A, C) ? "TRUE" : "FALSE");

    multiplyScalar(C, 2);

    printf("A == C after scaling C by 2 ? ");
    printf("%s\n", areEqual(A, C) ? "TRUE" : "FALSE");

    printf("\n**************************************************\n\n");

    Matrix invalid_add = addMatrices(A, B);

    printf("Invalid addition test:\n");
    if (invalid_add.data == NULL)
    {
        printf("INVALID MATRIX\n");
    }

    printf("\n**************************************************\n\n");

    Matrix invalid_mul = multiplyMatrices(B, B);

    printf("Invalid multiplication test:\n");
    if (invalid_mul.data == NULL)
    {
        printf("INVALID MATRIX\n");
    }

    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&add_result);
    freeMatrix(&transposed_A);
    freeMatrix(&mul_result);

    return 0;
}