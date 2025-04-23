
// Task 04 - Weather Sensor System

#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading temperature data..." << endl;
    }
    void displayReport() override {
        cout << "Displaying temperature report." << endl;
    }
};

class Barometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading pressure data..." << endl;
    }
    void displayReport() override {
        cout << "Displaying pressure report." << endl;
    }
};
