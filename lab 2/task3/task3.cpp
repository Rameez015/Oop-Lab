// Employee salary calculator
#include <iostream>
#include <string>
using namespace std;

struct employees
{
    string name;
    int hoursworked;
    int hourlyrate;
};

int main()
{
    employees employee;
    int n;
    cout << "state the number of employees: ";
    cin >> n;
    employees *arr = new employees[n];

    for (int i = 0; i < n; i++)
    {
        cout << "enter the [" << i + 1 << "] employee details: " << endl;
        cout << "Name: ";
        cin >> arr[i].name;
        cout << "hourly rate: ";
        cin >> arr[i].hourlyrate;
        cout << "hours worked: ";
        cin >> arr[i].hoursworked;
    }
    int totalsalary;
    for (int i = 0; i < n; i++)
    {
        totalsalary = arr[i].hourlyrate * arr[i].hoursworked;
        cout << "total salary for the [" << i + 1 << "] employee is:" << totalsalary << endl;
    }
    delete arr;
}
