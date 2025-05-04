#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("sensor_log.txt");
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    file << "Sensor 1: 25.5 C\n";
    cout << "Position after first write: " << file.tellp() << endl;

    file << "Sensor 2: 98.1 %RH\n";
    cout << "Position after second write: " << file.tellp() << endl;

    file.close();
    return 0;
}
