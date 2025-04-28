#include<iostream>
using namespace std;
class student{
    int roll_no;
    string name;
    public:
    student(){
        cout<<"Default Constructor Called...!"<<endl;
        roll_no = 0;
        name = "Default Name";
    }
    student(int r,string n){
        cout<<"Parametrised Constructor Called...!"<<endl;
        roll_no = r;
        name = n;
    }
    void putdata(){
        cout<<"Roll No is :: "<<roll_no<<endl;
        cout<<"The Name is :: "<<name<<endl;
    }

};
int main(){
    student s1;
    s1.putdata();
    student s2(143,"Urval Kheni");
    s2.putdata();
    student s3(69,"Aryan Parikh");
    s3.putdata();
    return 0;
}