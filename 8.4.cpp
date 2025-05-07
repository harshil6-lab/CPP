#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom comparator for sorting in descending order by score
bool compareScores(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second; // descending
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<pair<string, int>> students;
    cout << "Enter name and score for each student:\n";
    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cin >> name >> score;
        students.push_back({name, score});
    }

    // Sort using custom comparator
    sort(students.begin(), students.end(), compareScores);

    // Display ranked list
    cout << "\nRanked Student List:\n";
    int rank = 1;
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << "Rank " << rank++ << ": " << it->first << " - " << it->second << endl;
    }

    cout << "\n24CE049_Harshil\n";
    return 0;
}
