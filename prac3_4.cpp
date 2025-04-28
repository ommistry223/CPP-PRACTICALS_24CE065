#include <iostream>
using namespace std;

template <typename T>
T findMax(T* arr, int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

template <typename T>
void reverseArray(T* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

template <typename T>
void printArray(T* arr, int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int choice, size;
    cout << "Choose data type: 1. Integer 2. Float 3. Character\n";
    cin >> choice;
    cout << "Enter size of collection: ";
    cin >> size;

    if (choice == 1) {
        int* arr = new int[size];
        cout << "Enter " << size << " integers:\n";
        for (int i = 0; i < size; ++i)
            cin >> arr[i];
        cout << "Maximum: " << findMax(arr, size) << endl;
        reverseArray(arr, size);
        cout << "Reversed: ";
        printArray(arr, size);
        delete[] arr;
    } else if (choice == 2) {
        float* arr = new float[size];
        cout << "Enter " << size << " floats:\n";
        for (int i = 0; i < size; ++i)
            cin >> arr[i];
        cout << "Maximum: " << findMax(arr, size) << endl;
        reverseArray(arr, size);
        cout << "Reversed: ";
        printArray(arr, size);
        delete[] arr;
    } else if (choice == 3) {
        char* arr = new char[size];
        cout << "Enter " << size << " characters:\n";
        for (int i = 0; i < size; ++i)
            cin >> arr[i];
        cout << "Maximum: " << findMax(arr, size) << endl;
        reverseArray(arr, size);
        cout << "Reversed: ";
        printArray(arr, size);
        delete[] arr;
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
