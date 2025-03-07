#include <iostream>
#include <cstring>

class Apartment {
private:
    int id;
    std::string address;
    char* ownerName;

public:

    Apartment(int id, std::string address, const char* owner) : id(id), address(address) {
        ownerName = new char[strlen(owner) + 1];
        strcpy(ownerName, owner);
    }

    Apartment(const Apartment& other) : id(other.id), address(other.address) {
        ownerName = new char[strlen(other.ownerName) + 1];
        strcpy(ownerName, other.ownerName);
    }

    void display() {
        std::cout << "Apartment ID: " << id << "\nAddress: " << address << "\nOwner: " << ownerName << "\n\n";
    }

    ~Apartment() {
        delete[] ownerName;
    }
};

int main() {
    Apartment apt1(101, "123 Main St", "John Doe");
    Apartment apt2 = apt1; // Copy

    apt1.display();
    apt2.display();

    return 0;
}