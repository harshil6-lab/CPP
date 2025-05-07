// 6.3 : TOPIC : DAM
#include <iostream>
using namespace std;

// Function to merge two sorted arrays
int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2, int& mergedSize) {
    mergedSize = size1 + size2;
    int* merged = new int[mergedSize]; // allocate memory for merged array

    int i = 0, j = 0, k = 0;

    // Merge logic
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements if any
    while (i < size1) {
        merged[k++] = arr1[i++];
    }

    while (j < size2) {
        merged[k++] = arr2[j++];
    }

    return merged;
}

// Main function
int main() {
    int size1, size2;

    // Input sizes
    cout << "Enter size of first sorted array: ";
    cin >> size1;

    cout << "Enter size of second sorted array: ";
    cin >> size2;

    // Allocate arrays dynamically
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];

    // Input elements for first array
    cout << "Enter " << size1 << " sorted elements for first array:\n";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    // Input elements for second array
    cout << "Enter " << size2 << " sorted elements for second array:\n";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

    int mergedSize = 0;
    int* mergedArray = mergeSortedArrays(arr1, size1, arr2, size2, mergedSize);

    // Output merged array
    cout << "\nMerged Sorted Array:\n";
    for (int i = 0; i < mergedSize; i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    // Clean up memory
    delete[] arr1;
    delete[] arr2;
    delete[] mergedArray;
    cout<<"\n24CE049_Harshil\n";

    return 0;
}
