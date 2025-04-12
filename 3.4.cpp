#include <iostream>
using namespace std;

template <typename T>
void printCollection(T* arr, int size) {
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

template <typename T>
T findMax(T* arr, int size) {
	T maxVal = arr[0];
	for (int i = 1; i < size; ++i)
		if (arr[i] > maxVal)
			maxVal = arr[i];
	return maxVal;
}

template <typename T>
void reverseCollection(T* arr, int size) {
	for (int i = 0; i < size / 2; ++i)
		swap(arr[i], arr[size - i - 1]);
}

int main() {
	int intArr[100], intSize;
	float floatArr[100];
	int floatSize;
	char charArr[100];
	int charSize;

	cout << "Enter size of integer array: ";
	cin >> intSize;
	cout << "Enter integer elements: ";
	for (int i = 0; i < intSize; ++i)
		cin >> intArr[i];

	cout << "Enter size of float array: ";
	cin >> floatSize;
	cout << "Enter float elements: ";
	for (int i = 0; i < floatSize; ++i)
		cin >> floatArr[i];

	cout << "Enter size of char array: ";
	cin >> charSize;
	cout << "Enter character elements: ";
	for (int i = 0; i < charSize; ++i)
		cin >> charArr[i];

	cout << "Integer Array: ";
	printCollection(intArr, intSize);
	cout << "Max: " << findMax(intArr, intSize) << endl;
	reverseCollection(intArr, intSize);
	cout << "Reversed: ";
	printCollection(intArr, intSize);

	cout << "Float Array: ";
	printCollection(floatArr, floatSize);
	cout << "Max: " << findMax(floatArr, floatSize) << endl;
	reverseCollection(floatArr, floatSize);
	cout << "Reversed: ";
	printCollection(floatArr, floatSize);

	cout << "Character Array: ";
	printCollection(charArr, charSize);
	cout << "Max: " << findMax(charArr, charSize) << endl;
	reverseCollection(charArr, charSize);
	cout << "Reversed: ";
	printCollection(charArr, charSize);
    
    cout<<"\n24CE049_Harshil\n";
	return 0;
}
