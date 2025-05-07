
#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse

using namespace std;

// Function to manually reverse vector using iterators
void reverseWithIterators(vector<int>& v) {
    auto left = v.begin();
    auto right = v.end() - 1;

    while (left < right) {
        iter_swap(left, right);
        ++left;
        --right;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> data;
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        data.push_back(x);
    }

    // Approach 1: Using std::reverse
    vector<int> reversed1 = data;
    reverse(reversed1.begin(), reversed1.end());

    cout << "\nReversed using std::reverse(): ";
    for (auto val : reversed1) {
        cout << val << " ";
    }

    // Approach 2: Using manual iterators
    vector<int> reversed2 = data;
    reverseWithIterators(reversed2);

    cout << "\nReversed using manual iterators: ";
    for (auto val : reversed2) {
        cout << val << " ";
    }

    cout << "\n\n24CE049_Harshil\n";
    return 0;
}
