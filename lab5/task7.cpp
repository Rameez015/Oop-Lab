#include <iostream>
#include <cstring>

class Product {
public:
    int id;
    char name[50];
    int quantity;

    Product(int i, const char* n, int q) : id(i), quantity(q) {
        strcpy(name, n);
    }

    void display() {
        std::cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << "\n";
    }
};

int main() {
    Product p1(101, "Laptop", 10);
    Product p2(102, "Chair", 20);

    p1.display();
    p2.display();

    return 0;
}