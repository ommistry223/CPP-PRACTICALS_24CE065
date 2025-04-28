#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace std::chrono;

int recursiveSum(const vector<int>& arr, int n) {
    if (n == 0) return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int iterativeSum(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int main() {
    int n;
    cout<<"Enter the size of the array :: ";
    cin>>n;
    
    vector<int> arr(n);
    cout<<"Enter "<<n<<" elements :: ";
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    auto startRecursive = high_resolution_clock::now();
    int recSum = recursiveSum(arr, n);
    auto stopRecursive = high_resolution_clock::now();
    auto durationRecursive = duration_cast<nanoseconds>(stopRecursive - startRecursive);
    auto startIterative = high_resolution_clock::now();
    int iterSum = iterativeSum(arr);
    auto stopIterative = high_resolution_clock::now();
    auto durationIterative = duration_cast<nanoseconds>(stopIterative - startIterative);
    cout <<"Recursive Sum :: "<<recSum<<"(Time taken :: "<<durationRecursive.count()<< " ns)"<<endl;
    cout <<"Iterative Sum :: "<<iterSum<<"(Time taken :: "<<durationIterative.count()<< " ns)"<<endl;
    
    return 0;
}
