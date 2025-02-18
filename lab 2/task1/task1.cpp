// Dynamic Array structures
#include<iostream>
#include<string>
using namespace std;

struct books {
    string title;
    string author;
    int year;

};

int main () {
    books Books;
    int a;

    cout << "enter the number of books: ";
    cin>> a;
    books *arr = new books[a];

    for (int i = 0; i < a; i++){
        cout << "enter the book title: ";
        cin >> arr[i].title ;
        cout << "enter the book author: ";
        cin >> arr[i].author ;
        cout << "enter the book year: ";
        cin >> arr[i].year ;
        cout << endl;
    }
    int yearrange;
    cout << "enter the start year range: ";
    cin >> yearrange;

    for (int i = 0; i < a; i ++){
        if(arr[i].year>yearrange){
            cout << "title: " << arr[i].title << endl;
            cout << "author: " << arr[i].author << endl;
            cout << "year: " << arr[i].year << endl;
        }
    }
    delete arr;
}