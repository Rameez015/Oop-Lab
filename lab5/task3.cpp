#include <iostream>
#include <cstring>

class Employee {
public:
    char name[50];
    char designation[50];

    Employee(const char* n, const char* d) {
        strcpy(name, n);
        strcpy(designation, d);
    }
};

class Project {
private:
    char title[50];
    Employee* employees[10]; // Fixed array instead of vector
    int numEmployees;

public:
    Project(const char* t) : numEmployees(0) {
        strcpy(title, t);
    }

    void addEmployee(Employee* e) {
        if (numEmployees < 10) {
            employees[numEmployees++] = e;
        }
    }

    void display() {
        std::cout << "Project: " << title << "\nEmployees Assigned:\n";
        for (int i = 0; i < numEmployees; i++) {
            std::cout << employees[i]->name << " (" << employees[i]->designation << ")\n";
        }
        std::cout << "\n";
    }
};

int main() {
    Employee e1("John", "Developer"), e2("Alice", "Manager");
    Project p1("AI Project");

    p1.addEmployee(&e1);
    p1.addEmployee(&e2);
    
    p1.display();

    return 0;
}
