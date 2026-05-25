#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
typedef struct {
    unsigned int rows;
    unsigned int cols;
    int is_square;
    double** data;
} Matrix;


Matrix createMatrix(int rows, int cols);      // Create a matrix  
void printMat(Matrix mat);                   // function to print the matrix
Matrix addMatrices(Matrix A, Matrix B);      // to add two matrices together
Matrix transpose(Matrix mat);                // transpose a matrix 
int areEqual(Matrix A,  Matrix B);           // Checks if two matrices are equal
void multiplyScalar(Matrix mat, double scalar); // scalar multiplication
#endif