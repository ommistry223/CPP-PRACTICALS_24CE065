#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

struct Student {
    string name;
    int marks;
    string grade;
};

int main() {
    ifstream fin("students.txt");
    if (!fin) {
        cerr << "Error opening file!\n";
        return 1;
    }

    vector<Student> students;
    string name, grade;
    int marks;

    while (fin >> name >> marks >> grade) {
        students.push_back({name, marks, grade});
    }

    // Table header
    cout << left 
         << setw(20) << "NAME" 
         << setw(10) << "MARKS" 
         << setw(10) << "GRADE" << "\n"
         << string(40, '-') << "\n";

    // Table data
    for (const auto& s : students) {
        cout << setw(20) << s.name 
             << setw(10) << s.marks 
             << setw(10) << s.grade << "\n";
    }

    return 0;
}