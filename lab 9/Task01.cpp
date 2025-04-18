
#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;
public:
    Patient(string n, string i) : name(n), id(i) {}
    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}
    void displayTreatment() override {
        cout << "InPatient Treatment for " << name << endl;
    }
    double calculateCost() override {
        return 5000.0; // example fixed cost
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}
    void displayTreatment() override {
        cout << "OutPatient Treatment for " << name << endl;
    }
    double calculateCost() override {
        return 1500.0; // example fixed cost
    }
};

int main() {
    Patient* p1 = new InPatient("John Doe", "IP001");
    Patient* p2 = new OutPatient("Jane Smith", "OP001");

    p1->displayTreatment();
    cout << "Cost: " << p1->calculateCost() << endl;

    p2->displayTreatment();
    cout << "Cost: " << p2->calculateCost() << endl;

    delete p1;
    delete p2;
    return 0;
}
