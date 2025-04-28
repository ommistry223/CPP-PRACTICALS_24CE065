#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
protected:
    double radius;
public:
    void setRadius(double r) {
        radius = r;
    }
    double getRadius() {
        return radius;
    }
};

class Circle : public Shape {
public:
    double calculateArea() {
        return M_PI * radius * radius;
    }
};

int main() {
    int choice;
    cout << "Choose storage method:\n1. Dynamic (vector)\n2. Static (array)\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        int n;
        cout << "Enter number of circles: ";
        cin >> n;

        vector<Circle> circles(n);
        for (int i = 0; i < n; i++) {
            double r;
            cout << "Enter radius for circle " << i + 1 << ": ";
            cin >> r;
            circles[i].setRadius(r);
        }

        cout << "\nAreas of circles (Dynamic Storage):\n";
        for (int i = 0; i < n; i++) {
            cout << "Circle " << i + 1 << ": " << circles[i].calculateArea() << endl;
        }

    } else if (choice == 2) {
        const int MAX = 100;
        int n;
        cout << "Enter number of circles (max " << MAX << "): ";
        cin >> n;

        Circle circles[MAX];
        for (int i = 0; i < n; i++) {
            double r;
            cout << "Enter radius for circle " << i + 1 << ": ";
            cin >> r;
            circles[i].setRadius(r);
        }

        cout << "\nAreas of circles (Static Storage):\n";
        for (int i = 0; i < n; i++) {
            cout << "Circle " << i + 1 << ": " << circles[i].calculateArea() << endl;
        }

    } else {
        cout << "Invalid choice.";
    }

    return 0;
}
