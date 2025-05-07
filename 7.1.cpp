// 7.1 : Topic : File Management
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

// Function to convert a string to lowercase
void toLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

int main() {
    string paragraph;
    
    // Read entire paragraph
    cout << "Enter a paragraph:\n";
    getline(cin, paragraph);  // Use getline to capture the entire paragraph

    // Initialize a map to store word frequencies
    map<string, int> wordCount;

    // Use a string stream to break the paragraph into words
    istringstream stream(paragraph);
    string word;

    // Split the paragraph into words, count frequencies
    while (stream >> word) {
        toLowerCase(word);  // Convert the word to lowercase
        wordCount[word]++;   // Increment the frequency count for the word
    }

    // Output the word frequencies
    cout << "\nWord Frequency:\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout<<"\n24CE049_Harshil\n";

    return 0;
}
