
#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;
public:
    MenuItem(string name, double pr) : dishName(name), price(pr) {}
    virtual void showDetails() = 0;
    virtual void prepare() = 0;
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double pr) : MenuItem(name, pr) {}
    void showDetails() override {
        cout << "Appetizer: " << dishName << ", Price: $" << price << endl;
    }
    void prepare() override {
        cout << "Preparing appetizer: " << dishName << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double pr) : MenuItem(name, pr) {}
    void showDetails() override {
        cout << "Main Course: " << dishName << ", Price: $" << price << endl;
    }
    void prepare() override {
        cout << "Preparing main course: " << dishName << endl;
    }
};

int main() {
    MenuItem* m1 = new Appetizer("Spring Rolls", 4.99);
    MenuItem* m2 = new MainCourse("Grilled Chicken", 12.99);

    m1->showDetails();
    m1->prepare();

    m2->showDetails();
    m2->prepare();

    delete m1;
    delete m2;
    return 0;
}
