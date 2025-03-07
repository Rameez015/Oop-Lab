#include <iostream>
#include <cstring>

class Employee {
protected:
    std::string name;
    float salary;

public:
    Employee(std::string name, float salary) : name(name), salary(salary) {}

    virtual void displayDetails() {
        std::cout << "Name: " << name << "\nSalary: " << salary << "\n";
    }
};

class Manager : public Employee {
private:
    float bonus;

public:
    Manager(std::string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}

    void displayDetails() override {
        Employee::displayDetails();
        std::cout << "Bonus: " << bonus << "\n";
    }
};

int main() {
    Manager m("Alice Johnson", 50000, 5000);
    m.displayDetails();
    return 0;
}
