// Dynamic memory allocations for student records
#include <iostream>
#include <string>
using namespace std;

struct students
{
    string name;
    int rollno;
    int marks;
};

int main()
{
    students student;
    int n;
    cout << "enter the number of students: ";
    cin >> n;

    students *arr = new students[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter the [" << i + 1 << "] student details: " << endl;
        cout << "name: ";
        cin >> arr[i].name;
        cout << "rollno: ";
        cin >> arr[i].rollno;
        cout << "marks: ";
        cin >> arr[i].marks;
    }
    int totalmarks;
    for (int i = 0; i < n; i++)
    {
        totalmarks += arr[i].marks;
    }
    int avgmarks;
    avgmarks = totalmarks / n;

    cout << "the average marks of the students is:" << avgmarks << endl;

    delete arr;
}