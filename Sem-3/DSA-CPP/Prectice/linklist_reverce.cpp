#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

Node first;

Node* create(int n)
{
    Node* temp=new Node;
    temp->data=n;
    temp->link=nullptr;
    return temp;
}

void insert_end(int n)
{
    Node* temp=create(n);
    if (first.link==nullptr)
    {
        first.link=temp;
    } else {
        Node* current=first.link;
        while (current->link!=nullptr)
        {
            current=current->link;
        }
        current->link=temp;
    }
}

void display() {
    Node* current=first.link;
    if (current==nullptr)
    {
        cout << "List is Empty" << endl;
        return;
    }
    while (current!=nullptr)
    {
        cout << current->data << " ";
        current=current->link;
    }
    cout << endl;
}

void Reverse_linked_list()
{
    Node* prev=nullptr;
    Node* current=first.link;
    Node* next=nullptr;

    while (current!=nullptr)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    first.link=prev;
}

int main()
{
    int n, data;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> data;
        insert_end(data);
    }

    Reverse_linked_list();
    display();

    return 0;
}
