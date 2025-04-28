#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    static int totalAccounts;
    int accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount() : accountNumber(0), accountHolder(""), balance(0.0) {}
    BankAccount(string name, double initialBalance) {
        totalAccounts++;
        accountNumber = totalAccounts;
        accountHolder = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: Rs." << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: Rs." << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    void transfer(BankAccount &recipient, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transfer successful! Rs." << fixed << setprecision(2) << amount << " transferred to " << recipient.accountHolder << "'s account." << endl;
        } else {
            cout << "Transfer failed! Invalid amount or insufficient balance." << endl;
        }
    }

    void displayAccount() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: Rs." << fixed << setprecision(2) << balance << endl;
        cout << "--------------------------" << endl;
    }

    int getAccountNumber() const { return accountNumber; }
    static int getTotalAccounts() { return totalAccounts; }
};

int BankAccount::totalAccounts = 0;

void displayAllAccounts(const map<int, BankAccount> &accounts) {
    cout << "Displaying all accounts:" << endl;
    for (const auto &pair : accounts) {
        pair.second.displayAccount();
    }
}

int main() {
    map<int, BankAccount> accounts;
    int choice;
    while (true) {
        cout << "\nBank Management System" << endl;
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Transfer\n5. Display All Accounts\n6. Delete Account\n7. Exit\nEnter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            string name;
            double balance;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter initial balance: ";
            cin >> balance;
            int accNum = BankAccount::getTotalAccounts() + 1;
            accounts[accNum] = BankAccount(name, balance);
            cout << "Account created successfully! Account Number: " << accNum << endl;
        } else if (choice == 2) {
            int accNum;
            double amount;
            cout << "Enter account number: ";
            cin >> accNum;
            if (accounts.find(accNum) != accounts.end()) {
                cout << "Enter deposit amount: ";
                cin >> amount;
                accounts[accNum].deposit(amount);
            } else {
                cout << "Account not found!" << endl;
            }
        } else if (choice == 3) {
            int accNum;
            double amount;
            cout << "Enter account number: ";
            cin >> accNum;
            if (accounts.find(accNum) != accounts.end()) {
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                accounts[accNum].withdraw(amount);
            } else {
                cout << "Account not found!" << endl;
            }
        } else if (choice == 4) {
            int sender, receiver;
            double amount;
            cout << "Enter your account number: ";
            cin >> sender;
            cout << "Enter recipient account number: ";
            cin >> receiver;
            if (accounts.find(sender) != accounts.end() && accounts.find(receiver) != accounts.end()) {
                cout << "Enter transfer amount: ";
                cin >> amount;
                accounts[sender].transfer(accounts[receiver], amount);
            } else {
                cout << "One or both accounts not found!" << endl;
            }
        } else if (choice == 5) {
            displayAllAccounts(accounts);
        } else if (choice == 6) {
            int accNum;
            cout << "Enter account number to delete: ";
            cin >> accNum;
            if (accounts.find(accNum) != accounts.end()) {
                accounts.erase(accNum);
                cout << "Account deleted successfully!" << endl;
            } else {
                cout << "Account not found!" << endl;
            }
        } else if (choice == 7) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
