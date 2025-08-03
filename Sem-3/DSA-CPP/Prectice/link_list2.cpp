#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor to free memory
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at beginning" << endl;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " (first element)" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " at end" << endl;
    }

    // Delete a value
    void deleteValue(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        // If head needs to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << endl;
            return;
        }

        // Search for the value
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value " << value << " not found" << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Deleted " << value << endl;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        cout << "List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }

    // Search for a value
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Get size of list
    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

// Function to display menu
void showMenu() {
    cout << "\n=== Linked List Operations ===" << endl;
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Delete a value" << endl;
    cout << "4. Display list" << endl;
    cout << "5. Search for a value" << endl;
    cout << "6. Get list size" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

// Main function with user input
int main() {
    LinkedList list;
    int choice, value;

    cout << "=== Welcome to Linked List Program ===" << endl;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteValue(value);
                break;

            case 4:
                list.display();
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (list.search(value)) {
                    cout << "Value " << value << " found in the list!" << endl;
                } else {
                    cout << "Value " << value << " not found in the list." << endl;
                }
                break;

            case 6:
                cout << "List size: " << list.size() << endl;
                break;

            case 7:
                cout << "Thank you for using the Linked List program!" << endl;
                return 0;

            default:
                cout << "Invalid choice! Please enter a number between 1-7." << endl;
                break;
        }

        // Small pause for better user experience
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
