// Car class
#include <iostream>
#include <string>

class Car
{
private:
    std::string brand;
    std::string model;
    double fuelCapacity;
    double currentFuelLevel;

public:
    Car(std::string b, std::string m, double cap) : brand(b), model(m), fuelCapacity(cap), currentFuelLevel(cap) {}

    void drive(double distance)
    {
        double fuelConsumption = distance * 0.1; // Simplified fuel consumption
        if (fuelConsumption <= currentFuelLevel)
        {
            currentFuelLevel -= fuelConsumption;
            std::cout << "Driven " << distance << " km. Remaining fuel: " << currentFuelLevel << " liters." << std::endl;
        }
        else
        {
            std::cout << "Not enough fuel to drive " << distance << " km." << std::endl;
        }
        checkFuelStatus();
    }

    void refuel(double amount)
    {
        if (amount + currentFuelLevel <= fuelCapacity)
        {
            currentFuelLevel += amount;
            std::cout << "Refueled " << amount << " liters. Total fuel: " << currentFuelLevel << " liters." << std::endl;
        }
        else
        {
            std::cout << "Cannot refuel more than " << fuelCapacity - currentFuelLevel << " liters." << std::endl;
        }
    }

    void checkFuelStatus()
    {
        if (currentFuelLevel < 10)
        {
            std::cout << "Warning: Low fuel!" << std::endl;
        }
    }
};

int main()
{
    Car myCar("Toyota", "Corolla", 50);
    myCar.drive(100);
    myCar.refuel(30);
    return 0;
}