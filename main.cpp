/** \file Matrix.cpp
* \brief Implementation for Matrix library
* \details Library for ..
* \author keven aggrey
* \version 0.1
* \date 2022
* \copyright University of Nicosia.
*/
#include "Matrix.h"
#include<iostream>
#include <cassert>
using namespace std;

/**
* Function <code>printMatrix</code> displays the matrix
* <BR>
* @param mat The matrix to be printed
* @param maxRow The number of rows in the matrix
*/
void printMatrix(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    for (int i = 0;i < maxRow;i++) {
        for (int j = 0;j < MAX_COL;j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

/**
* Function <code>sumOfRow</code> sums the numbers in a given row
* <BR>
* @param mat The matrix
* @param row The row whose numbers will be summed up
* @param maxRow The number of rows in the matrix
* @return returns the sum of a row
*/
double sumOfRow(const double mat[][MAX_COL], const int row, const int maxRow) {
    assert(maxRow > 0);
    assert(row >= 0 && row < maxRow);

    double sum = 0;
    for (int i = 0; i < MAX_COL; i++)
        sum += mat[row][i];

    return sum;
}

/**
* Function <code>sumOfCol</code> sums the numbers in a given column
* <BR>
* @param mat The matrix
* @param column The column whose numbers will be summed up
* @param maxRow The number of rows in the matrix
* @return returns the sum of a column
*/
double sumOfCol(const double mat[][MAX_COL], const int column, const int maxRow) {
    assert(maxRow > 0);
    assert(column >= 0 && column < MAX_COL);

    double sum = 0;

    for (int i = 0; i < maxRow; i++)
        sum += mat[i][column];

    return sum;
}

/**
* Function <code>fillWithRandomNum</code> fills the matrix with random values
* <BR>
* @param mat The matrix to fill
* @param maxRow The number of rows in the matrix
*/
void fillWithRandomNum(double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    srand(time(0));
    for (int i = 0;i < maxRow;i++)
        for (int j = 0;j < MAX_COL;j++)
            mat[i][j] = (double)(rand()%1000) / 10;
}

/**
* Function <code>sumAll</code> sums the numbers in matrix
* <BR>
* @param mat The matrix
* @param maxRow The number of rows in the matrix
* @return the sum of all numbers in matrix
*/
double sumAll(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    double sum=0;

    for (int i = 0;i < maxRow;i++)
        for (int j = 0;j < MAX_COL;j++)
            sum += mat[i][j];
    return sum;
}

/**
* Function <code>maxNum</code> finds the biggest number in matrix
* <BR>
* @param mat The matrix
* @param maxRow The number of rows in the matrix
* @return the biggest number in the matrix
*/
double maxNum(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    int i = 0, j = 0;
    double max = mat[i][j];

    for (i = 0;i < maxRow;i++)
        for (j = 0;j < MAX_COL;j++)
            if (max < mat[i][j]) max = mat[i][j];

    return max;
}

/**
* Function <code>fillWithNum</code> fills matrix with one given value
* <BR>
* @param mat The matrix to be filled
* @param maxRow The number of rows in the matrix
*/
void fillWithNum(double mat[][MAX_COL], const double num, const int maxRow) {
    assert(maxRow > 0);

    for (int i = 0;i < maxRow;i++)
        for (int j = 0;j < MAX_COL;j++)
            mat[i][j] = num;
}

/**
* Function <code>sumOfRows</code> sums up all the elements in all of the rows seperately
* <BR>
* @param mat The matrix
* @param maxRow The number of rows in the matrix
* @return Returns a vector containing the sum of each row
*/
double* sumOfRows(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    double* const sums = new double[maxRow];

    for (int i = 0; i < maxRow; i++)
        sums[i] = sumOfRow(mat, i, maxRow);

    return sums;
}

/**
* Function <code>sumOfCols</code> sums up all the elements in all of the columns seperately
* WARNING: Collee MUST use <code>delete[]</code> on return ptr
* <BR>
* @param mat The matrix
* @param maxRow The number of rows in the matrix
* @return Returns a vector containing the sum of each column
*/
double* sumOfCols(const double mat[][MAX_COL], const int maxRow) {
    assert(maxRow > 0);

    double * const sums = new double[MAX_COL];

    for (int i = 0; i < MAX_COL; i++)
        sums[i] = sumOfCol(mat, i, maxRow);

    return sums;
}

