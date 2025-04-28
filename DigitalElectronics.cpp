#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Printing table header
    cout << "\nLogical Operations Table" << endl;
    cout << "+---+---+---+---+----+----+---+----+\n";
    cout << "| A | B |AND| OR |NAND| NOR|XOR|XNOR|\n";
    cout << "+---+---+---+---+----+----+---+----+\n";
    
    // Loop through all possible values of A and B
    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            cout << "| " << A << " | " << B << " | "
                 << (A & B) << " | " << (A | B) << " | "
                 << !(A & B) << "  | " << !(A | B) << "  | "
                 << (A ^ B) << " | " << !(A ^ B) << "  |" << endl;
        }
    }
    
    cout << "+---+---+---+---+----+----+---+----+\n";
    return 0;
}
