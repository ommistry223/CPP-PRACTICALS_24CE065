#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // for transform
#include <cctype>    // for tolower
using namespace std;

void addItem() {
    string name;
    int qty;
    double price;
    
    cout << "Enter item name: ";
    getline(cin, name);
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price: ";
    cin >> price;
    cin.ignore(); // Clear the newline character
    
    ofstream file("inventory.txt", ios::app);
    if (file.is_open()) {
        file << name << "," << qty << "," << price << "\n";
        cout << "Item added successfully!\n";
        file.close();
    } else {
        cout << "Error opening file!\n";
    }
}

void viewItems() {
    ifstream file("inventory.txt");
    string line;
    
    if (!file.is_open()) {
        cout << "No inventory found or unable to open file!\n";
        return;
    }
    
    cout << "\nCurrent Inventory:\n";
    cout << "-----------------\n";
    while (getline(file, line)) {
        cout << line << "\n";
    }
    file.close();
}

void searchItem() {
    ifstream file("inventory.txt");
    string line, searchTerm;
    
    cout << "Enter item name to search: ";
    getline(cin, searchTerm);
    
    // Convert search term to lowercase for case-insensitive search
    transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
    
    bool found = false;
    
    if (file.is_open()) {
        while (getline(file, line)) {
            string lineLower = line;
            transform(lineLower.begin(), lineLower.end(), lineLower.begin(), ::tolower);
            
            if (lineLower.find(searchTerm) != string::npos) {
                cout << "Found: " << line << "\n";
                found = true;
            }
        }
        file.close();
        
        if (!found) {
            cout << "Item not found in inventory.\n";
        }
    } else {
        cout << "Unable to open inventory file!\n";
    }
}

int main() {
    while (true) {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. View All Items\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        cin.ignore(); // Clear the newline character
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}