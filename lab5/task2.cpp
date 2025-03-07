#include <iostream>
#include <cstring>

class Student {
private:
    int id;
    char name[50];
    int* scores;
    int numScores;

public:

    Student(int id, const char* name, int scores[], int numScores) : id(id), numScores(numScores) {
        strcpy(this->name, name);
        this->scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            this->scores[i] = scores[i];
        }
    }

    Student(const Student& other) : id(other.id), numScores(other.numScores) {
        strcpy(this->name, other.name);
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = other.scores[i];
        }
    }

    void display() {
        std::cout << "Student ID: " << id << "\nName: " << name << "\nScores: ";
        for (int i = 0; i < numScores; i++) {
            std::cout << scores[i] << " ";
        }
        std::cout << "\n\n";
    }

    ~Student() {
        delete[] scores;
    }
};

int main() {
    int scores[] = {90, 85, 78};
    Student s1(1, "Alice", scores, 3);
    Student s2 = s1; // Copy

    s1.display();
    s2.display();

    return 0;
}