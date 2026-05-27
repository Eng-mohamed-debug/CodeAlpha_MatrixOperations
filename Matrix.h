#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <stdio.h>
typedef struct {
    unsigned int rows;
    unsigned int cols;
    int is_square;
    double** data;
} Matrix;


Matrix createMatrix(int rows, int cols);      // Create a matrix  
Matrix createMatrixFromArray(int rows, int cols, double data[rows][cols]);
void printMatrix(Matrix mat, char* element_sep, char* rows_sep);                   // function to print the matrix
Matrix addMatrices(Matrix A, Matrix B);      // to add two matrices together
Matrix multiplyMatrices(Matrix A, Matrix B); // Multiply two Matrices
Matrix transpose(Matrix mat);                // transpose a matrix 
int areEqual(Matrix A,  Matrix B);           // Checks if two matrices are equal
void multiplyScalar(Matrix mat, double scalar); // scalar multiplication
void freeMatrix(Matrix* mat);
#endif