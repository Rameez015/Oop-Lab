// Dynamic array of pointers
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter the no of elements: ";
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "enter the [" << i << "]th element of the array: ";
        cin >> *arr[i];
    }
    cout << "these are the values of your array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << endl;
    }
    delete arr;
}