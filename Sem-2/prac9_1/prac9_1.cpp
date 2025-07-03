#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to safely get a positive double input from the user
double getPositiveInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive numerical value.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            return value;
        }
    }
}

int main() {
    cout << "============================================\n";
    cout << "   Loan-to-Income Ratio Calculator\n";
    cout << "============================================\n\n";

    // Get user inputs with validation
    double loanAmount = getPositiveInput("Enter the total loan amount ($): ");
    double annualIncome = getPositiveInput("Enter your annual income ($): ");

    // Calculate the ratio
    double ratio = loanAmount / annualIncome;
    double percentage = ratio * 100;

    // Display results with formatting
    cout << fixed << setprecision(2);
    cout << "\n--------------------------------------------\n";
    cout << "Loan Amount:        $" << setw(10) << loanAmount << endl;
    cout << "Annual Income:      $" << setw(10) << annualIncome << endl;
    cout << "--------------------------------------------\n";
    cout << "Loan-to-Income Ratio: " << setw(10) << ratio << " (or " << percentage << "%)\n";
    cout << "--------------------------------------------\n";

    // Add ratio interpretation
    cout << "\nRatio Interpretation:\n";
    if (ratio < 0.3) {
        cout << "This is considered a very safe ratio.\n";
    } else if (ratio < 0.5) {
        cout << "This is a manageable ratio for most borrowers.\n";
    } else {
        cout << "Warning: This ratio may be considered high by many lenders.\n";
    }

    cout << "\nThank you for using the calculator!\n";
    return 0;
}