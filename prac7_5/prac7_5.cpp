#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// Custom currency manipulator that adds flexibility
ostream& currency(ostream& os, const string& symbol = "$", int width = 10) {
    os << symbol;
    os.width(width - symbol.length());  // Adjust width for the symbol
    return os;
}

int main() {
    vector<pair<string, double>> v = {
        {"Alice", 12345.67}, 
        {"Bob", 890.12}, 
        {"Charlie", 1234.56},
        {"Diana", 7890.12}
    };

    // Table header
    cout << left << setw(15) << "Name" 
         << right << setw(15) << "Fee" << endl;
    cout << string(30, '-') << endl;

    // Table rows
    for (auto &p : v) {
        cout << left << setw(15) << p.first 
             << right << setw(1);
        currency(cout) << fixed << setprecision(2) << setw(14) << p.second << endl;
    }

    // Calculate and display total
    double total = 0;
    for (auto &p : v) {
        total += p.second;
    }
    cout << string(30, '-') << endl;
    cout << left << setw(15) << "Total" 
         << right << setw(1);
    currency(cout) << fixed << setprecision(2) << setw(14) << total << endl;

    return 0;
}