#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void manual_reverse(vector<int>& vec) {
    auto left = vec.begin();
    auto right = vec.end() - 1;
    while (left < right) {
        swap(*left, *right);
        left++;
        right--;
    }
}

void print_vector(const string& label, const vector<int>& vec) {
    cout << label << ": ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter number of elements: ";
    int n;
    cin >> n;

    vector<int> original(n);
    cout << "Enter " << n << " space-separated numbers: ";
    for (int& num : original) {
        cin >> num;
    }

    vector<int> copy1 = original;
    reverse(copy1.begin(), copy1.end());
    print_vector("STL reverse", copy1);

    vector<int> copy2 = original;
    manual_reverse(copy2);
    print_vector("Manual reverse", copy2);

    return 0;
}