#include<iostream>
#include<vector>
using namespace std;

class Employee {
    string name;
    double basicSalary, bonus;

public:
    Employee(string n, double salary, double b = 500):name(n),basicSalary(salary),bonus(b){}
    inline double calculateTotalSalary() {return basicSalary + bonus;}
    void getData() {
        cout<<"Enter Name :: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter Basic Salary: ";cin>>basicSalary;
        cout<<"Enter Bonus (default 500) :: ";cin>>bonus;
    }
    void displayData() {
        cout<<"Name :: "<<name<<"\n | Basic Salary :: "<<basicSalary<<"\n | Bonus :: "<<bonus<<"\n | Total Salary :: "<<calculateTotalSalary()<<endl;
    }
};

int main() {
    vector<Employee> employees;
    int n;
    cout<<"Enter number of employees :: ";cin>>n;
    
    for(int i=0;i<n;i++) {
        Employee emp("",0,0);
        emp.getData();
        employees.push_back(emp);
    }
    
    for(auto &emp : employees)emp.displayData();
    
    return 0;
}
