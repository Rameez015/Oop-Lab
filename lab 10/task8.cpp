#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Step 1
    ofstream outFile("config.txt");
    outFile << "AAAAABBBBBCCCCC";
    outFile.close();

    // Step 2
    fstream file("config.txt", ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    // Step 3
    file.seekp(5);
    file << "XXXXX";
    file.close();

    return 0;
}
