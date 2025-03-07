#include <iostream>

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

    virtual void displayDetails() {
        std::cout << "Device ID: " << deviceID << "\nStatus: " << (status ? "On" : "Off") << "\n";
    }
};

class SmartPhone : public Device {
protected:
    float screenSize;

public:
    SmartPhone(int deviceID, bool status, float screenSize) 
        : Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails() override {
        Device::displayDetails();
        std::cout << "Screen Size: " << screenSize << " inches\n";
    }
};

class SmartWatch : public Device {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int deviceID, bool status, bool heartRateMonitor) 
        : Device(deviceID, status), heartRateMonitor(heartRateMonitor) {}

    void displayDetails() override {
        Device::displayDetails();
        std::cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << "\n";
    }
};

class SmartWearable : public SmartWatch {
private:
    int stepCounter;

public:
    SmartWearable(int deviceID, bool status, bool heartRateMonitor, int stepCounter) 
        : SmartWatch(deviceID, status, heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails() override {
        SmartWatch::displayDetails();
        std::cout << "Step Counter: " << stepCounter << " steps\n";
    }
};

int main() {
    SmartWearable sw(1001, true, true, 5000);
    sw.displayDetails();
    return 0;
}