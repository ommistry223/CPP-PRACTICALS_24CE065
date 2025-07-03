#include <iostream>

using namespace std;

class Base {
public:
    Base() {
        cout << "Base constructor\n";
    }

    virtual ~Base() {
        cout << "Base destructor\n";
    }
};

class Derived : public Base {
private:
    int* data;
public:
    Derived() {
        data = new int[100]; // Simulate dynamic resource allocation
        cout << "Derived constructor\n";
    }

    ~Derived() override {
        delete[] data; // Proper cleanup
        cout << "Derived destructor\n";
    }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Correctly calls Derived destructor then Base destructor
    return 0;
}