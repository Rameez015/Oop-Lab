#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("vehicles.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open the file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#')
            continue;

        stringstream ss(line);
        string Type, ID, Name, Year, ExtraData, Cert;

        getline(ss, Type, ',');
        getline(ss, ID, ',');
        getline(ss, Name, ',');
        getline(ss, Year, ',');
        getline(ss, ExtraData, ',');
        getline(ss, Cert);

        cout << "Parsed: " << Type << ", " << ID << ", " << Name
             << ", " << Year << ", " << ExtraData << ", " << Cert << endl;
    }

    file.close();
    return 0;
}
