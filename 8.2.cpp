#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);  // Read entire line

    map<string, int> wordFrequency;  // Stores word -> frequency

    stringstream ss(input);
    string word;

    // Tokenize input and count frequencies
    while (ss >> word) {
        ++wordFrequency[word];  // Increments count for each word
    }

    // Display word frequencies using iterator
    cout << "\nWord Frequency Distribution:\n";
    for (auto it = wordFrequency.begin(); it != wordFrequency.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }

    cout << "\n24CE049_Harshil\n";
    return 0;
}
