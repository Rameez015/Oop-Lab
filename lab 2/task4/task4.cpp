// Dynamic string array
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "input the number of strings";
    cin >> n;
    string *arr = new string[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter the string: ";
        cin >> arr[i];
    }
    cout << "your entered string: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "alphabetically ordered string: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    delete arr;
}