#include<iostream>
using namespace std;
class student{
    int roll_no;
    string name;
    public:
    void student::putdata(){
        cout<<"Roll No is :: "<<roll_no<<endl;
        cout<<"The Name is :: "<<name<<endl;
    }
    student::student(){
        cout<<"Default Constructor Called...!"<<endl;
        roll_no = 0;
        name = "Default Name";
    }

};
int main(){
    student s1;
    s1.putdata();
    return 0;
}