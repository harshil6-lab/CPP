#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cout << "Enter number of transaction IDs: ";
    cin >> n;

    set<int> transactions;
    cout << "Enter " << n << " transaction IDs: ";
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        transactions.insert(id); // Automatically avoids duplicates
    }

    cout << "\nUnique Transaction IDs (Sorted): ";
    for (auto it = transactions.begin(); it != transactions.end(); ++it) {
        cout << *it << " ";
    }

    cout << "\n\n24CE049_Harshil\n";
    return 0;
}
