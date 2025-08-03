#include <bits/stdc++.h>
using namespace std;

int Binary_search(vector<int> &a, int x, int l, int h) {
    while (l <= h) {
        int m = l + (h - l) / 2;  // Correct way to avoid overflow
        if (a[m] == x) {
            return m;
        } else if (a[m] > x) {
            h = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> a(n);

    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    cout << "Enter the element to find: ";
    cin >> x;

    int an = Binary_search(a, x, 0, n - 1);
    if (an == -1) {
        cout << "Not found\n";
    } else {
        cout << an << " - Element found.\n";
    }

    return 0;
}
