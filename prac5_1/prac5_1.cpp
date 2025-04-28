#include <iostream>
#include <vector>

using namespace std;

class Calculator {
private:
    vector<double> results; // Store results as double for generality

public:
    // Overloaded add functions

    int add(int a, int b) {
        int result = a + b;
        results.push_back(result);
        return result;
    }

    double add(double a, double b) {
        double result = a + b;
        results.push_back(result);
        return result;
    }

    double add(int a, double b) {
        double result = a + b;
        results.push_back(result);
        return result;
    }

    double add(double a, int b) {
        double result = a + b;
        results.push_back(result);
        return result;
    }

    // Method to display all stored results
    void displayResults() const {
        cout << "Stored Results:" << endl;
        for (size_t i = 0; i < results.size(); ++i) {
            cout << i + 1 << ": " << results[i] << endl;
        }
    }
};

// Example usage
int main() {
    Calculator calc;

    calc.add(5, 3);           // int + int
    calc.add(4.5, 2.3);       // double + double
    calc.add(7, 2.5);         // int + double
    calc.add(3.5, 6);         // double + int

    calc.displayResults();    // Show all stored outcomes

    return 0;
}
