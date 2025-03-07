#include <iostream>
#include <cstring>

class AlarmSystem {
public:
    char securityLevel[10];

    AlarmSystem(const char* level) {
        strcpy(securityLevel, level);
    }

    void display() {
        std::cout << "Security Level: " << securityLevel << "\n";
    }
};

class SmartHome {
private:
    AlarmSystem* alarm;

public:
    SmartHome(const char* security) {
        alarm = new AlarmSystem(security);
    }

    void display() {
        std::cout << "Smart Home System Details:\n";
        alarm->display();
    }

    ~SmartHome() {
        delete alarm;
    }
};

int main() {
    SmartHome home("High");
    home.display();

    return 0;
}
