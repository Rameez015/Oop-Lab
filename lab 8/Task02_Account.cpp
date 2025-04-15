#include <iostream>
using namespace std;

class Account {
private:
    int accNumber;
    double balance;

public:
    Account(int num = 0, double bal = 0.0) {
        accNumber = num;
        balance = bal;
    }

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager {
public:
    void display(const Account& acc) {
        cout << "Account Number: " << acc.accNumber << ", Balance: " << acc.balance << endl;
    }

    void deposit(Account& acc, double amount) {
        acc.balance += amount;
    }

    void withdraw(Account& acc, double amount) {
        if (acc.balance >= amount)
            acc.balance -= amount;
        else
            cout << "Insufficient balance\n";
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
    } else {
        cout << "Insufficient balance for transfer\n";
    }
}

int main() {
    Account a1(101, 5000), a2(102, 3000);
    Manager m;

    m.display(a1);
    m.display(a2);

    m.deposit(a1, 1000);
    m.withdraw(a2, 500);
    transferFunds(a1, a2, 2000);

    m.display(a1);
    m.display(a2);

    return 0;
}