#include <iostream>
#include <cmath>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    float loanAmount;
    float annualInterestRate;
    int tenureMonths;

public:
    Loan() {
        loanID = 0;
        applicantName = "Unknown";
        loanAmount = 0;
        annualInterestRate = 0;
        tenureMonths = 0;
    }

    Loan(int id, string name, float amount, float rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    float calculateEMI() const {
        float monthlyRate = (annualInterestRate / 12) / 100;
        float emi = (loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths)) / (pow(1 + monthlyRate, tenureMonths) - 1);
        return emi;
    }

    void displayLoanDetails() const {
        cout << "\nLoan ID: " << loanID
             << "\nApplicant Name: " << applicantName
             << "\nLoan Amount: $" << loanAmount
             << "\nAnnual Interest Rate: " << annualInterestRate << "%"
             << "\nTenure (Months): " << tenureMonths
             << "\nCalculated EMI: $" << calculateEMI() << endl;
    }
};

int main() {
    int id, tenure;
    float amount, rate;
    string name;

    cout << "Enter Loan ID: ";
    cin >> id;
    cout << "Enter Applicant Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Loan Amount: ";
    cin >> amount;
    cout << "Enter Annual Interest Rate (%): ";
    cin >> rate;
    cout << "Enter Loan Tenure (Months): ";
    cin >> tenure;

    Loan customerLoan(id, name, amount, rate, tenure);

    customerLoan.displayLoanDetails();

    return 0;
}
