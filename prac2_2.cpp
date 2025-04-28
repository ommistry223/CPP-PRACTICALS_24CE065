#include <iostream>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks[3];
    
public:
    Student() : rollNumber(0), name("Default Name") {
        marks[0] = marks[1] = marks[2] = 0.0;
    }
    
    Student(int roll, string studentName, float m1, float m2, float m3) : rollNumber(roll), name(studentName) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
    
    float calculateAverage() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }
    void getData() {
        cout<<"Enter Roll Number :: ";
        cin>>rollNumber;
        cout<<"Enter Name :: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter Marks for 3 subjects :: ";
        cin>>marks[0]>>marks[1]>>marks[2];
    }
    void displayDetails() {
        cout<<"Roll Number :: "<<rollNumber<<endl;
        cout<<"Name :: "<<name<<endl;
        cout<<"Marks :: "<<marks[0]<<", "<<marks[1]<<", "<<marks[2]<<endl;
        cout<<"Average Marks :: "<<calculateAverage()<<endl;
        cout<<"-----------------------------------"<<endl;
    }
};

int main() {
    int n;
    cout<<"Enter How many Student You Want :: ";cin>>n;
    Student students[n];

     for (int i = 0; i < n; i++) {
        students[i].getData();
    }
    for (int i = 0; i < n; i++) {
        students[i].displayDetails();
    }
    
    return 0;
}
