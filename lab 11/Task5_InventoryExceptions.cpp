#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <typename T>
class InventoryItem {
    T stock;
    T maxStock;
public:
    InventoryItem(T max) : maxStock(max), stock(0) {}
    void setStock(T value) {
        if (value < 0) {
            throw NegativeStockException();
        } else if (value > maxStock) {
            throw OverCapacityException();
        }
        stock = value;
    }
};

int main() {
    InventoryItem<int> item(100);
    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    } catch (NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): std::exception" << endl;
    }

    try {
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    } catch (OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): std::exception" << endl;
    }

    return 0;
}