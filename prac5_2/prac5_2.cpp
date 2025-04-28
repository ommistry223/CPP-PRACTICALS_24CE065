#include <iostream>
#include <vector>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }

    // Overload >> operator for input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

int main() {
    Complex c1, c2, sum, diff;

    cout << "Enter first complex number:" << endl;
    cin >> c1;
    cout << "Enter second complex number:" << endl;
    cin >> c2;

    sum = c1 + c2;
    diff = c1 - c2;

    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    // Batch operation: Working with a collection
    vector<Complex> complexList;
    int n;
    cout << "\nHow many complex numbers do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Complex temp;
        cout << "Enter complex number " << i + 1 << ":" << endl;
        cin >> temp;
        complexList.push_back(temp);
    }

    // Sum all complex numbers
    Complex totalSum;
    for (const auto& c : complexList) {
        totalSum = totalSum + c;
    }

    cout << "\nTotal Sum of all complex numbers: " << totalSum << endl;

    return 0;
}
