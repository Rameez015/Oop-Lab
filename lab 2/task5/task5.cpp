// Pointers and arrays
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }

    cout << "Sum of array elements: " << sum << endl;

    delete[] arr;

    return 0;
}