#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    // Constructor
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Method to move the point
    Point* move(double dx, double dy) {
        x += dx;
        y += dy;
        return this; // Return the pointer to the current object for chaining
    }

    // Utility function to print the point
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// Example Usage
int main() {
    Point p(1.0, 2.0);
    p.move(3.0, 4.0)->move(-2.0, 5.0)->move(0.0, -1.0);
    p.print(); // Should print the final coordinates
    return 0;
}
