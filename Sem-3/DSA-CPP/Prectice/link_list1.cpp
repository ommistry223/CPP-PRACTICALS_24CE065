#include <iostream>
using namespace std;

// Simple Node
struct Node {
    int data;
    Node* next;
};

// Global head pointer
Node* head = nullptr;

// Add element to list
void add(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Added " << value << endl;
}

// Display all elements
void display() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    cout << "List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Delete an element
void deleteElement(int value) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    // If first element to delete
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted " << value << endl;
        return;
    }

    // Find element to delete
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Not found" << endl;
    } else {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Deleted " << value << endl;
    }
}

int main() {
    int choice, value;

    cout << "Simple Linked List" << endl;

    while (true) {
        cout << "\n1. Add  2. Display  3. Delete  4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number: ";
            cin >> value;
            add(value);
        }
        else if (choice == 2) {
            display();
        }
        else if (choice == 3) {
            cout << "Delete which number: ";
            cin >> value;
            deleteElement(value);
        }
        else if (choice == 4) {
            cout << "Bye!" << endl;
            break;
        }
        else {
            cout << "Wrong choice!" << endl;
        }
    }

    return 0;
}
