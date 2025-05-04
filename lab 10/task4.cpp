#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("vehicles.txt");
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        stringstream ss(line);
        string Type, ID, Name, YearStr, ExtraData, Cert;
        getline(ss, Type, ',');
        getline(ss, ID, ',');
        getline(ss, Name, ',');
        getline(ss, YearStr, ',');
        getline(ss, ExtraData, ',');
        getline(ss, Cert);

        if (Type == "AutonomousCar") {
            size_t pos = ExtraData.find(':');
            if (pos != string::npos) {
                float version = stof(ExtraData.substr(pos + 1));
                cout << "ID: " << ID << ", Software Version: " << version << endl;
            }
        } else if (Type == "ElectricVehicle") {
            size_t pos = ExtraData.find(':');
            if (pos != string::npos) {
                int battery = stoi(ExtraData.substr(pos + 1));
                cout << "ID: " << ID << ", Battery Capacity: " << battery << endl;
            }
        }
    }

    file.close();
    return 0;
}
