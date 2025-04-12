#include <iostream>
using namespace std;

int recursiveSum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

int iterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int sumRecursive = recursiveSum(arr, size);
    int sumIterative = iterativeSum(arr, size);

    cout << "Sum using Recursive approach: " << sumRecursive << endl;
    cout << "Sum using Iterative approach: " << sumIterative << endl;

    delete[] arr;
    cout<<"\n24CE049_Harshil";
    return 0;
}
