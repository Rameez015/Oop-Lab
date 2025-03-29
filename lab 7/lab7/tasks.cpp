#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void displayTime() {
        cout << hours << "h:" << minutes << "m:" << seconds << "s" << endl;
    }

    bool isEqual(Time t) {
        return (hours == t.hours && minutes == t.minutes && seconds == t.seconds);
    }
};

class Student {
private:
    string name;
    int rollNumber;
    float gpa;

public:
    Student(string n, int r, float g) {
        name = n;
        rollNumber = r;
        gpa = g;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Roll No: " << rollNumber << ", GPA: " << gpa << endl;
    }

    bool isPassed() {
        return gpa >= 2.0;
    }
};

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 0, double w = 0) {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }

    bool isSquare() {
        return length == width;
    }
};

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    void displayBook() {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }

    bool isRecent() {
        return year >= 2020;
    }
};

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    BankAccount(string name, string accNum, double bal = 0.0) {
        accountHolder = name;
        accountNumber = accNum;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance or invalid amount." << endl;
    }

    void displayAccount() {
        cout << "Account Holder: " << accountHolder << ", Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }
};

int main() {
    Time t1(3, 45, 30);
    Time t2;
    t2.setTime(3, 45, 30);
    t1.displayTime();
    t2.displayTime();
    cout << (t1.isEqual(t2) ? "Times are equal." : "Times are not equal.") << endl;

    Student s1("Alice", 101, 3.2);
    Student s2("Bob", 102, 1.8);
    s1.displayInfo();
    cout << "Passed: " << (s1.isPassed() ? "Yes" : "No") << endl;
    s2.displayInfo();
    cout << "Passed: " << (s2.isPassed() ? "Yes" : "No") << endl;

    Rectangle r1(5, 5);
    cout << "Area: " << r1.area() << ", Perimeter: " << r1.perimeter() << endl;
    cout << "Is square: " << (r1.isSquare() ? "Yes" : "No") << endl;

    Book b1("C++ Basics", "John Doe", 2021);
    b1.displayBook();
    cout << "Is recent: " << (b1.isRecent() ? "Yes" : "No") << endl;

    BankAccount acc("Jane Smith", "12345678", 500.0);
    acc.displayAccount();
    acc.deposit(150.0);
    acc.withdraw(100.0);
    acc.displayAccount();

    return 0;
}