#include <iostream>
using namespace std;
class BankAccount {
private:
    char accountHolderName[100];
    long accountNumber;
    double balance;

public:
    BankAccount() {
        accountHolderName[0] = '\0';
        accountNumber = 0;
        balance = 0.0;
    }

    BankAccount(const char* name, long accNumber, double initialBalance) {
        int i;
        for (i = 0; name[i] != '\0' && i < 99; i++) {
            accountHolderName[i] = name[i];
        }
        accountHolderName[i] = '\0';
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout<<"Deposited: "<<amount<<endl;
        } else {
            cout<<"Invalid deposit amount!"<<endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void displayAccountDetails() {
        cout <<"Account Holder: "<<accountHolderName<<endl;
        cout <<"Account Number: "<<accountNumber<<endl;
        cout <<"Balance: "<<balance<<endl;
    }
};
int main() {
    char name[100];
    long accNumber;
    double initialBalance;

    cout<<"Enter Account Holder Name: ";
    cin.getline(name, 100);
    cout<<"Enter Account Number: ";
    cin>>accNumber;
    cout<<"Enter Initial Balance: ";
    cin>>initialBalance;

    BankAccount account(name, accNumber, initialBalance);

    int choice;
    double amount;
    do {
        cout<<"\n1. Deposit\n2. Withdraw\n3. Display Account Details\n4. Exit\nEnter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter amount to deposit: ";
                cin>>amount;
                account.deposit(amount);
                break;
            case 2:
                cout<<"Enter amount to withdraw: ";
                cin>>amount;
                account.withdraw(amount);
                break;
            case 3:
                account.displayAccountDetails();
                break;
            case 4:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
