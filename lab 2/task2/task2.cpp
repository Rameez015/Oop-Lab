// Pointer to Pointer for matrix operations
#include <iostream>
using namespace std;

int main()
{
    int row1, col1, row2, col2;
    cout << "enter the number of rows for the first matrix: ";
    cin >> row1;
    cout << "enter the number of columns for the first matrix: ";
    cin >> col1;
    cout << "enter the number of rows for the second matrix: ";
    cin >> row2;
    cout << "enter the number of columns for the second matrix: ";
    cin >> col2;

    int **matrix1 = new int *[row1];
    for (int i = 0; i < row1; i++)
    {
        matrix1[i] = new int[col1];
    }
    int **matrix2 = new int *[row2];
    for (int i = 0; i < row2; i++)
    {
        matrix2[i] = new int[col2];
    }
    cout << "enter the first matrix's elements: " << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << "enter the [" << i << "][" << j << "]th element: ";
            cin >> matrix1[i][j];
        }
    }
    cout << "enter the second matrix's elements: " << endl;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cout << "enter the [" << i << "][" << j << "]th element: ";
            cin >> matrix2[i][j];
        }
    }
    if (row1 == row2 && col1 == col2)
    {
        int addition[row1][col1];
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                addition[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        int subtraction[row1][col1];
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                addition[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        cout << "matrices addition: " << endl;
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                cout << addition[i][j];
            }
            cout << endl;
        }
        cout << "matrices substraction: " << endl;
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                cout << subtraction[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "the matrices cannot be added or subtracted from each other their dimensions fo not match";
    }
    delete matrix1, matrix2;
}