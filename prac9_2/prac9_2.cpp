#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <ctime>
using namespace std;

// Utility function to get current timestamp
string getCurrentTimestamp() {
    time_t now = time(nullptr);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;
    vector<string> transactionHistory;

    void logTransaction(const string& transaction) {
        string entry = "[" + getCurrentTimestamp() + "] " + transaction;
        transactionHistory.push_back(entry);
    }

    string formatCurrency(double amount) const {
        stringstream ss;
        ss << fixed << setprecision(2) << "$" << amount;
        return ss.str();
    }

public:
    BankAccount(const string& name, double initialBalance) 
        : accountHolderName(name), balance(max(0.0, initialBalance)) {
        
        // Generate a simple account number (in real system, this would be more sophisticated)
        accountNumber = "ACC" + to_string(rand() % 9000 + 1000);
        
        if (initialBalance < 0) {
            logTransaction("WARNING: Initial balance was negative, set to 0");
        }
        logTransaction("Account opened with initial balance: " + formatCurrency(balance));
    }

    void deposit(double amount) {
        if (amount <= 0) {
            logTransaction("FAILED: Attempted invalid deposit of " + formatCurrency(amount));
            cout << "Error: Deposit amount must be positive.\n";
            return;
        }
        
        balance += amount;
        logTransaction("Deposited " + formatCurrency(amount) + 
                      ". New balance: " + formatCurrency(balance));
        cout << "Successfully deposited " << formatCurrency(amount) << ".\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logTransaction("FAILED: Attempted invalid withdrawal of " + formatCurrency(amount));
            cout << "Error: Withdrawal amount must be positive.\n";
            return;
        }
        
        if (amount > balance) {
            logTransaction("FAILED: Insufficient funds for withdrawal of " + formatCurrency(amount));
            cout << "Error: Insufficient funds. Available balance: " 
                 << formatCurrency(balance) << "\n";
            return;
        }
        
        balance -= amount;
        logTransaction("Withdrew " + formatCurrency(amount) + 
                      ". New balance: " + formatCurrency(balance));
        cout << "Successfully withdrew " << formatCurrency(amount) << ".\n";
    }

    void displayAccountDetails() const {
        cout << "\n=== Account Details ===\n";
        cout << left << setw(20) << "Account Holder:" << accountHolderName << "\n";
        cout << setw(20) << "Account Number:" << accountNumber << "\n";
        cout << setw(20) << "Current Balance:" << formatCurrency(balance) << "\n";
        cout << "======================\n";
    }

    void displayTransactionHistory() const {
        cout << "\n=== Transaction History ===\n";
        if (transactionHistory.empty()) {
            cout << "No transactions recorded.\n";
        } else {
            for (const string& transaction : transactionHistory) {
                cout << transaction << "\n";
            }
        }
        cout << "==========================\n";
    }

    double getBalance() const { return balance; }
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getValidAmount(const string& prompt) {
    double amount;
    while (true) {
        cout << prompt;
        cin >> amount;
        
        if (cin.fail() || amount <= 0) {
            cout << "Invalid amount. Please enter a positive number.\n";
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return amount;
        }
    }
}

int main() {
    srand(time(nullptr)); // Seed for account number generation
    
    cout << "================================\n";
    cout << "      BANKING SYSTEM v2.0\n";
    cout << "================================\n\n";

    // Account setup
    cout << "Opening a new account:\n";
    string name;
    cout << "Enter account holder name: ";
    getline(cin, name);
    
    double initialBalance = getValidAmount("Enter initial deposit amount: $");
    
    BankAccount account(name, initialBalance);
    cout << "\nAccount created successfully!\n";
    account.displayAccountDetails();

    // Main menu
    int choice;
    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. View Account Details\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "=====================\n";
        cout << "Enter your choice (1-5): ";
        
        cin >> choice;
        clearInputBuffer();
        
        switch (choice) {
            case 1: {
                double amount = getValidAmount("Enter deposit amount: $");
                account.deposit(amount);
                break;
            }
            case 2: {
                double amount = getValidAmount("Enter withdrawal amount: $");
                account.withdraw(amount);
                break;
            }
            case 3:
                account.displayAccountDetails();
                break;
            case 4:
                account.displayTransactionHistory();
                break;
            case 5:
                cout << "\nThank you for using our banking system!\n";
                cout << "Final balance: " << account.getBalance() << "\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}