#include <iostream>
#include <string>
using namespace std;

int superDigit(string n) {
    if(n.length() == 1)
        return n[0] - '0';
    long long sum = 0;
    for(char ch : n) {
        sum += ch - '0';
    }
    return superDigit(to_string(sum));
}

int main(){
    string n;
    int k;
    cout << "Enter number as string: ";
    cin >> n;
    cout << "Enter number of concatenations (k): ";
    cin >> k;
    long long initialSum = 0;
    for(char ch : n) {
        initialSum += ch - '0';
    }
    initialSum *= k;
    int result = superDigit(to_string(initialSum));
    cout << "Super digit is: " << result << endl;
    return 0;
}