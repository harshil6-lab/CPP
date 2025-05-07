// 7.3 : Topic : File Management .

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Function to count words in a string
int countWords(const string& line) {
    int wordCount = 0;
    bool inWord = false;

    for (char ch : line) {
        if (isalnum(ch)) {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    return wordCount;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    // Open the file
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return 1;  // Exit the program if the file cannot be opened
    }

    int totalLines = 0, totalWords = 0, totalChars = 0;
    vector<string> lines;  // Using vector to store lines

    string line;
    while (getline(file, line)) {
        totalLines++;  // Count the number of lines
        totalChars += line.length();  // Add to the total number of characters

        // Count words in the current line
        totalWords += countWords(line);

        // Store the line in vector (automatic resizing handled by vector)
        lines.push_back(line);
    }

    // Output the statistics
    cout << "\nFile Analysis Results:\n";
    cout << "Total Lines: " << totalLines << endl;
    cout << "Total Words: " << totalWords << endl;
    cout << "Total Characters: " << totalChars << endl;

    // Print the custom message at the end
    cout << "\n24CE049_Harshil\n";

    return 0;
}
