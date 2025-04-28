#include <iostream>
#include <cstring> // For strncpy
using namespace std;

class InventoryItem {
private:
    int itemID;
    char itemName[50];
    double price;
    int quantity;

public:
    InventoryItem() : itemID(0), price(0.0), quantity(0) {
        itemName[0] = '\0';
    }

    void getData() {
        cout<<"Enter Item ID :: ";cin>>itemID;
        cout<<"Enter Item Name :: ";
        cin.ignore();
        cin.getline(itemName, sizeof(itemName));
        cout<<"Enter Price :: ";
        cin>>price;
        cout<<"Enter Quantity :: ";
        cin>>quantity;
    }

    void addStock(int qty) {
        if (qty > 0) {
            quantity += qty;
            cout<<qty<<"items added to stock."<< endl;
        } else {
            cout<<"Invalid quantity!"<<endl;
        }
    }

    void sellItem(int qty) {
        if (qty > 0 && qty <= quantity) {
            quantity -= qty;
            cout<<qty<<"items sold."<< endl;
        } else {
            cout<<"Insufficient stock or invalid quantity!"<<endl;
        }
    }

    void displayData()const{
        cout<<"Item ID :: "<<itemID<<endl;
        cout<<"Item Name :: "<<itemName<<endl;
        cout<<"Price: Rupees "<<price<<endl;
        cout<<"Quantity :: "<<quantity<<endl;
    }
};

int main() {
    InventoryItem items[3];

    cout<<"Enter details for 3 inventory items :: "<<endl;
    for (int i=0;i<3;i++) {
        cout<<"\nItem"<<(i + 1)<<":: "<<endl;
        items[i].getData();
    }

    cout<<"\nInitial Inventory :: "<<endl;
    for (int i=0;i<3;i++) {
        cout<<"\nItem "<<(i + 1)<<":: "<<endl;
        items[i].displayData();
    }

    cout<<endl<<"Adding stock to Item 1..."<<endl;
    items[0].addStock(20);

    cout<<endl<<"Selling items from Item 2..."<<endl;
    items[1].sellItem(30);

    cout<<endl<<"Updated Inventory :: "<<endl;
    for (int i=0;i<3;i++) {
        cout<<"\nItem "<<(i + 1)<<":: "<< endl;
        items[i].displayData();
    }

    return 0;
}
