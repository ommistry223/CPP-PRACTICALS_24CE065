#include <iostream>
#include <algorithm>  // for swap
using namespace std;

int main() {
    int n, d;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[20];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter number of positions to rotate: ";
    cin >> d;

    d = d % n; // Handle d > n

    // Step 1: Reverse first d elements
    for (int i = 0; i < d / 2; i++) {
        swap(arr[i], arr[d - 1 - i]);
    }

    // Step 2: Reverse remaining elements
    for (int i = 0; i < (n - d) / 2; i++) {
        swap(arr[d + i], arr[n - 1 - i]);
    }

    // Step 3: Reverse entire array
    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - 1 - i]);
    }

    cout << "Rotated Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
