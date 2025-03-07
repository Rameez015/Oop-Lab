#include <iostream>
#include <cstring>

class Vehicle {
protected:
    std::string brand;
    int speed;

public:
    Vehicle(std::string brand, int speed) : brand(brand), speed(speed) {}

    virtual void displayDetails() {
        std::cout << "Brand: " << brand << "\nSpeed: " << speed << " km/h\n";
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(std::string brand, int speed, int seats) : Vehicle(brand, speed), seats(seats) {}

    void displayDetails() override {
        Vehicle::displayDetails();
        std::cout << "Seats: " << seats << "\n";
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(std::string brand, int speed, int seats, int batteryLife) 
        : Car(brand, speed, seats), batteryLife(batteryLife) {}

    void displayDetails() override {
        Car::displayDetails();
        std::cout << "Battery Life: " << batteryLife << " hours\n";
    }
};

int main() {
    ElectricCar eCar("Tesla", 200, 5, 12);
    eCar.displayDetails();
    return 0;
}