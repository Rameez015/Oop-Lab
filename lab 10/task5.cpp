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

        if (Type == "HybridTruck") {
            size_t colonPos = ExtraData.find(':');
            size_t pipePos = ExtraData.find('|');

            if (colonPos != string::npos && pipePos != string::npos) {
                string cargoStr = ExtraData.substr(colonPos + 1, pipePos - colonPos - 1);
                string batteryStr = ExtraData.substr(pipePos + 8); // "Battery:" is 8 chars

                int cargo = stoi(cargoStr);
                int battery = stoi(batteryStr);

                cout << "ID: " << ID << ", Cargo: " << cargo << ", Battery: " << battery << endl;
            }
        }
    }

    file.close();
    return 0;
}
