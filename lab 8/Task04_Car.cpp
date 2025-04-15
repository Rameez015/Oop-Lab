#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    double price;

public:
    Car(string m = "", double p = 0.0) {
        model = m;
        price = p;
    }

    friend class InventoryManager;
    friend void comparePrice(const Car& c1, const Car& c2);
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
    }

    void display(const Car& car) {
        cout << "Model: " << car.model << ", Price: " << car.price << endl;
    }
};

void comparePrice(const Car& c1, const Car& c2) {
    if (c1.price > c2.price)
        cout << c1.model << " is more expensive." << endl;
    else if (c1.price < c2.price)
        cout << c2.model << " is more expensive." << endl;
    else
        cout << "Both cars have the same price." << endl;
}

int main() {
    Car c1("Civic", 30000), c2("Corolla", 28000);
    InventoryManager m;

    m.display(c1);
    m.display(c2);

    m.updatePrice(c2, 32000);
    comparePrice(c1, c2);

    return 0;
}