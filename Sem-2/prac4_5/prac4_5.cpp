#include<iostream>
#include<string>
using namespace std;

class computegrades
{

    virtual void computegrade() = 0;

};
class undergraduate : public computegrades
{
    private:
    string name;
    int rollno;
    int marks[5];
    public:
    void getdata()
    {
        cout << "Enter name of student: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollno;
        cout << "Enter marks in 5 subjects: ";
        for (int i = 0; i < 5; i++)
            cin >> marks[i];
    }
    void computegrade()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        float avg = sum / 5.0;
        cout << "Average marks of undergraduate student " << name << " is: " << avg << endl;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
};
class Postgraduate : public computegrades
{
    private:
    string name;
    int rollno;
    int marks[5];
    public:
    void getdata()
    {
        cout << "Enter name of student: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollno;
        cout << "Enter marks in 5 subjects: ";
        for (int i = 0; i < 5; i++)
            cin >> marks[i];
    }
    void computegrade()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        float avg = sum / 5.0;
        cout << "Average marks of postgraduate student " << name << " is: " << avg << endl;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
};
int main()
{
    undergraduate u;
    Postgraduate p;
    u.getdata();
    u.computegrade();
    u.display();
    p.getdata();
    p.computegrade();
    p.display();
    return 0;
}