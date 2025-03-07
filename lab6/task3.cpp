#include <iostream>
#include <cstring>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string name, int age) : name(name), age(age) {}

    virtual void displayDetails() {
        std::cout << "Name: " << name << "\nAge: " << age << "\n";
    }
};

class Teacher : public Person {
protected:
    std::string subject;

public:
    Teacher(std::string name, int age, std::string subject) : Person(name, age), subject(subject) {}

    void displayDetails() override {
        Person::displayDetails();
        std::cout << "Subject: " << subject << "\n";
    }
};

class Researcher : public Person {
protected:
    std::string researchArea;

public:
    Researcher(std::string name, int age, std::string researchArea) : Person(name, age), researchArea(researchArea) {}

    void displayDetails() override {
        Person::displayDetails();
        std::cout << "Research Area: " << researchArea << "\n";
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(std::string name, int age, std::string subject, std::string researchArea, int publications) 
        : Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}

    void displayDetails() override {
        Teacher::displayDetails();
        Researcher::displayDetails();
        std::cout << "Publications: " << publications << "\n";
    }
};

int main() {
    Professor prof("Dr. Smith", 45, "Mathematics", "Artificial Intelligence", 20);
    prof.displayDetails();
    return 0;
}
