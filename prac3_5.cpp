#include <iostream>
#include <string>
using namespace std;

int superDigit(string n, int k) {
    long long sum = 0;
    for (char c : n)
        sum += c - '0';
    sum *= k;
    if (sum < 10)
        return sum;
    return superDigit(to_string(sum), 1);
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    cout << superDigit(n, k) << endl;
    return 0;
}
