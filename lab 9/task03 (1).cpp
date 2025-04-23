
// Task 03 - Course Grading System

#include <iostream>
#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;
public:
    Course(string code, int credit) : courseCode(code), credits(credit) {}
    virtual void calculateGrade() = 0;
    virtual void displayInfo() = 0;
    virtual ~Course() {}
};

class LectureCourse : public Course {
public:
    LectureCourse(string code, int credit) : Course(code, credit) {}
    void calculateGrade() override {
        cout << "Calculating grade for lecture course: " << courseCode << endl;
    }
    void displayInfo() override {
        cout << "Lecture Course: " << courseCode << ", Credits: " << credits << endl;
    }
};

class LabCourse : public Course {
public:
    LabCourse(string code, int credit) : Course(code, credit) {}
    void calculateGrade() override {
        cout << "Calculating grade for lab course: " << courseCode << endl;
    }
    void displayInfo() override {
        cout << "Lab Course: " << courseCode << ", Credits: " << credits << endl;
    }
};
