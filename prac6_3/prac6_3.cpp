#include <iostream>
using namespace std;

// Manual sorting function (Bubble Sort)
void manualSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, m;
    
    // Input sizes
    cout << "Enter the size of the first dataset: ";
    cin >> n;
    cout << "Enter the size of the second dataset: ";
    cin >> m;

    // Dynamic memory allocation
    int* a = new int[n];
    int* b = new int[m];

    // Read first array
    cout << "Enter elements of the first dataset:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Read second array
    cout << "Enter elements of the second dataset:\n";
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
    }

    // Allocate memory for merged array
    int* merged = new int[n + m];

    // Copy elements from first array
    for (int i = 0; i < n; ++i)
    {
        merged[i] = a[i];
    }

    // Copy elements from second array
    for (int i = 0; i < m; ++i)
    {
        merged[n + i] = b[i];
    }

    // Now sort the merged array manually
    manualSort(merged, n + m);

    // Output the sorted merged array
    cout << "Merged Sorted Dataset:\n";
    for (int i = 0; i < n + m; ++i)
    {
        cout << merged[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] a;
    delete[] b;
    delete[] merged;

    return 0;
}
