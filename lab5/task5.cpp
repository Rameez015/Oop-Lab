#include <iostream>
#include <cstring>

class Doctor {
public:
    char name[50];
    char specialization[50];

    Doctor(const char* n, const char* s) {
        strcpy(name, n);
        strcpy(specialization, s);
    }
};

class Hospital {
private:
    Doctor* doctors[10];
    int numDoctors;

public:
    Hospital() : numDoctors(0) {}

    void addDoctor(Doctor* d) {
        if (numDoctors < 10) {
            doctors[numDoctors++] = d;
        }
    }

    void display() {
        std::cout << "Hospital Doctors List:\n";
        for (int i = 0; i < numDoctors; i++) {
            std::cout << doctors[i]->name << " (" << doctors[i]->specialization << ")\n";
        }
        std::cout << "\n";
    }
};

int main() {
    Doctor d1("Dr. Smith", "Cardiology"), d2("Dr. Brown", "Neurology");
    Hospital h;
    
    h.addDoctor(&d1);
    h.addDoctor(&d2);
    
    h.display();

    return 0;
}