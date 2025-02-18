// Matrix multiplication using pointers
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
    if (col1 = row2)
    {
        int **matrix3 = new int *[row1];
        for (int i = 0; i < row1; i++)
        {
            matrix3 = new int *[col2];
        }
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                matrix3[i][j] = 0;
            }
        }
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                for (int k = 0; k < col1; k++)
                {
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        cout << "resultant matrix: " << endl;
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                cout << matrix3[i][j] << " ";
            }
            cout << endl;
        }
        delete matrix3;
    }
    delete matrix1, matrix2;
}