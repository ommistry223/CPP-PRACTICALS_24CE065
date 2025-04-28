#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    float price;

public:
    Product(int pid, string pname, int qty, float pprice)
        : id(pid), name(pname), quantity(qty), price(pprice) {}

    int getId() const {
        return id;
    }

    void updateQuantity(int qtyChange) {
        quantity += qtyChange;
        if (quantity < 0) quantity = 0;
    }

    float getTotalValue() const {
        return quantity * price;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Quantity: " << quantity
             << ", Price: $" << price << endl;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(int id, string name, int quantity, float price) {
        products.push_back(Product(id, name, quantity, price));
    }

    void updateProductQuantity(int id, int qtyChange) {
        for (auto& product : products) {
            if (product.getId() == id) {
                product.updateQuantity(qtyChange);
                cout << "Quantity updated.\n";
                return;
            }
        }
        cout << "Product ID not found.\n";
    }

    void displayInventory() const {
        cout << "\nInventory:\n";
        for (const auto& product : products) {
            product.display();
        }
    }

    float calculateTotalValue() const {
        float total = 0;
        for (const auto& product : products) {
            total += product.getTotalValue();
        }
        return total;
    }
};

int main() {
    Inventory store;
    int choice;

    do {
        cout << "\n1. Add Product\n2. Update Quantity\n3. Display Inventory\n4. Total Inventory Value\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, quantity;
            float price;
            string name;
            cout << "Product ID: ";
            cin >> id;
            cout << "Product Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Quantity: ";
            cin >> quantity;
            cout << "Price: ";
            cin >> price;
            store.addProduct(id, name, quantity, price);
        }
        else if (choice == 2) {
            int id, qtyChange;
            cout << "Product ID: ";
            cin >> id;
            cout << "Quantity Change: ";
            cin >> qtyChange;
            store.updateProductQuantity(id, qtyChange);
        }
        else if (choice == 3) {
            store.displayInventory();
        }
        else if (choice == 4) {
            cout << "Total Inventory Value: $" << store.calculateTotalValue() << endl;
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
