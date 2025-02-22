// car rental system
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Task 01:
class Car
{
private:
    string brand, model;
    double rentalPrice;
    bool available;
    int carID;
    double totalRevenue;
    static int idCounter;

public:
    Car() : carID(++idCounter), brand("Unknown"), model("Generic"), rentalPrice(0.0), available(true), totalRevenue(0.0) {}

    Car(string b, string m, double price, bool avail) : carID(++idCounter), brand(b), model(m), rentalPrice(price), available(avail), totalRevenue(0.0) {}

    Car(const Car &c) : carID(c.carID), brand(c.brand), model(c.model), rentalPrice(c.rentalPrice), available(c.available), totalRevenue(c.totalRevenue) {}

    ~Car() {}

    void updateDetails(string b, string m, double price)
    {
        brand = b;
        model = m;
        rentalPrice = price;
    }

    // Task 02:
    bool processRentalRequest(int days)
    {
        if (!available)
        {
            cout << "Car is not available for rent.\n";
            return false;
        }
        available = false;
        applyDiscount(days);
        totalRevenue += rentalPrice * days;
        return true;
    }

    void applyDiscount(int days)
    {
        if (days > 10)
            rentalPrice *= 0.9;
        else if (days > 5)
            rentalPrice *= 0.95;
    }

    void returnCar()
    {
        available = true;
    }

    // Task 03:
    void displayDetails()
    {
        cout << "Car ID: " << carID << "\nBrand: " << brand << "\nModel: " << model << "\nRental Price: " << rentalPrice << "\nAvailability: " << (available ? "Yes" : "No") << "\nTotal Revenue: " << totalRevenue << "\n";
    }
};

int Car::idCounter = 0;

int main()
{
    // Task 04:
    Car car1("Toyota", "Corolla", 50.0, true);
    car1.displayDetails();

    car1.processRentalRequest(7);
    car1.displayDetails();

    // Task 05:
    Car car2 = car1;
    car2.displayDetails();

    return 0;
}
