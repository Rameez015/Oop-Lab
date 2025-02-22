//Wallet class
#include <iostream>
#include <vector>
#include <string>

class Wallet
{
private:
    std::string ownerName;
    double totalBalance;
    std::vector<std::string> transactionHistory;

public:
    Wallet(std::string name, double balance) : ownerName(name), totalBalance(balance) {}

    void addMoney(double amount)
    {
        totalBalance += amount;
        transactionHistory.push_back("Added: " + std::to_string(amount));
    }

    void spendMoney(double amount)
    {
        if (amount <= totalBalance)
        {
            totalBalance -= amount;
            transactionHistory.push_back("Spent: " + std::to_string(amount));
        }
        else
        {
            std::cout << "Insufficient balance!" << std::endl;
        }
    }

    void displayTransactionHistory()
    {
        for (const auto &transaction : transactionHistory)
        {
            std::cout << transaction << std::endl;
        }
    }

    double getBalance() const
    {
        return totalBalance;
    }
};

int main()
{
    Wallet myWallet("Saad", 1000);
    myWallet.addMoney(500);
    myWallet.spendMoney(200);
    myWallet.displayTransactionHistory();
    std::cout << "Current Balance: " << myWallet.getBalance() << std::endl;
    return 0;
}