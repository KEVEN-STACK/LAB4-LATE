/** \file driver.cpp
* \brief Small matrix manipulation program
* \details This program..
* \author keven aggrey
* \version 0.1
* \date 2022
* \copyright University of Nicosia.
*/

#include <iostream>
#include "Matrix.h"
using namespace std;

/**
* The driver of the program
* @return Returns 0
*/
int main() {
    const int MAX_ROW = 5;
    double matrix[MAX_ROW][MAX_COL] = { 0 };
    int choice;
    double* sums;

    do {
        cout << "\n1)Print matrix";
        cout << "\n2)Sum a row in matrix";
        cout << "\n3)Sum a column in matrix";
        cout << "\n4)Fill matrix with random numbers";
        cout << "\n5)Sum all numbers in matrix";
        cout << "\n6)Find the biggest number in matrix";
        cout << "\n7)Initialize all values in matrix to a number";
        cout << "\n8)Sum all rows";
        cout << "\n9)Sum all columns";
        cout << "\n10)Quit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printMatrix(matrix, MAX_ROW);
                break;
            case 2:
                int r;
                do {
                    cout << "\nEnter row number: ";
                    cin >> r;
                } while (r<0 || r>MAX_ROW-1);
                cout << "\nThe sum is: " << sumOfRow(matrix, r, MAX_ROW) << endl;
                break;
            case 3:
                int c;
                do {
                    cout << "\nEnter column number: ";
                    cin >> c;
                } while (c<0 || c>MAX_COL - 1);
                cout << "\nThe sum is: " << sumOfCol(matrix, c, MAX_ROW) << endl;
                break;
            case 4:
                fillWithRandomNum(matrix, MAX_ROW);
                break;
            case 5:
                cout << "\nThe sum is: " << sumAll(matrix, MAX_ROW) << endl;
                break;
            case 6:
                cout << "\nThe biggest number is: " << maxNum(matrix, MAX_ROW) << endl;
                break;
            case 7:
                double num;
                do {
                    cout << "\nEnter a number: ";
                    cin >> num;
                } while (num < 0);
                fillWithNum(matrix, num, MAX_ROW);
                break;
            case 8:
                sums = sumOfRows(matrix, MAX_ROW);
                for (int i = 0; i < MAX_ROW;i++) {
                    cout << "\nSum of row " << i << ": " << sums[i];
                }
                delete[] sums;
                break;
            case 9:
                sums = sumOfCols(matrix, MAX_ROW);
                for (int i = 0; i < MAX_COL;i++) {
                    cout << "\nSum of column " << i << ": " << sums[i];
                }
                delete[] sums;
                break;
            case 10:
                break;
            default:
                cout << "\nWrong choice\n";
                break;
        }
    } while (choice!=10);
}

