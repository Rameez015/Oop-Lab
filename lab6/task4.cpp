#include <iostream>

class Account {
protected:
    int accountNumber;
    float balance;

public:
    Account(int accountNumber, float balance) : accountNumber(accountNumber), balance(balance) {}

    virtual void displayDetails() {
        std::cout << "Account Number: " << accountNumber << "\nBalance: $" << balance << "\n";
    }
};

class SavingsAccount : public Account {
private:
    float interestRate;

public:
    SavingsAccount(int accountNumber, float balance, float interestRate) 
        : Account(accountNumber, balance), interestRate(interestRate) {}

    void displayDetails() override {
        Account::displayDetails();
        std::cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CheckingAccount : public Account {
private:
    float overdraftLimit;

public:
    CheckingAccount(int accountNumber, float balance, float overdraftLimit) 
        : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    void displayDetails() override {
        Account::displayDetails();
        std::cout << "Overdraft Limit: $" << overdraftLimit << "\n";
    }
};

int main() {
    SavingsAccount sa(1001, 5000, 2.5);
    CheckingAccount ca(2001, 3000, 1000);

    std::cout << "Savings Account:\n";
    sa.displayDetails();
    std::cout << "\nChecking Account:\n";
    ca.displayDetails();

    return 0;
}
