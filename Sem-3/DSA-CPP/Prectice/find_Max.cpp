#include<iostream>
#include<vector>
using namespace std;

// Function to find max value using vector
int find_max(const vector<int>& a) {
    int max = a[0];
    for(int i = 1; i < a.size(); i++) {
        if(max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s = find_max(a);
    cout << "Maximum element is: " << s << endl;

    return 0;
}
