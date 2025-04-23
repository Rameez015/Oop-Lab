
// Task 05 - Logistics Shipment System

#include <iostream>
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;
public:
    Shipment(string number, double wt) : trackingNumber(number), weight(wt) {}
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(string number, double wt) : Shipment(number, wt) {}
    void estimateDeliveryTime() override {
        cout << "Estimating air delivery time for: " << trackingNumber << endl;
    }
    void showDetails() override {
        cout << "Air Freight - Tracking: " << trackingNumber << ", Weight: " << weight << "kg" << endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string number, double wt) : Shipment(number, wt) {}
    void estimateDeliveryTime() override {
        cout << "Estimating ground delivery time for: " << trackingNumber << endl;
    }
    void showDetails() override {
        cout << "Ground Shipment - Tracking: " << trackingNumber << ", Weight: " << weight << "kg" << endl;
    }
};
