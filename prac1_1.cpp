#include <iostream>
using namespace std;

class BankAccount {
private:
    char accountHolderName[50]; // Using character array instead of string
    int accountNumber;
    double balance;

public:
    BankAccount(const char name[], int accNumber, double initialBalance) {
        int i = 0;
        while (name[i] != '\0' && i < 49) {  // Copy name manually (basic string copy)
            accountHolderName[i] = name[i];
            i++;
        }
        accountHolderName[i] = '\0'; // Null terminator for safety
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        } else if (amount > balance) {
            cout << "Error: Insufficient balance." << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void display_balance() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount account1("Urval", 123456, 1000.0);
    BankAccount account2("Heet", 654321, 500.0);

    cout << "--- Account 1 Operations ---" << endl;
    account1.display_balance();
    account1.deposit(200.0);
    account1.withdraw(150.0);
    account1.withdraw(1200.0);

    cout << "\n--- Account 2 Operations ---" << endl;
    account2.display_balance();
    account2.deposit(300.0);
    account2.withdraw(700.0);
    account2.withdraw(200.0);

    return 0;
}
