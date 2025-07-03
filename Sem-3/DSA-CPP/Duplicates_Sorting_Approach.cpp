#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {4, 2, 3, 2, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    cout << "Duplicates using Sorting: ";
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            cout << arr[i] << " ";
            while (i < n - 1 && arr[i] == arr[i + 1])
                i++;
        }
    }
}
// O(n log n), O(1) if in-place