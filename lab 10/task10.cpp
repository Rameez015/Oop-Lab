#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("data_records.txt");
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    int offset = 2 * 9; // Skips first 2 records
    file.seekg(offset, ios::beg);

    string record;
    getline(file, record);
    cout << "Third record: " << record << endl;

    file.close();
    return 0;
}
