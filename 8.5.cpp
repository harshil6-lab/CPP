#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    map<string, vector<string>> directory;
    int choice;

    do {
        cout << "\nDirectory Management System";
        cout << "\n1. Add Folder";
        cout << "\n2. Add File to Folder";
        cout << "\n3. Display Directory Structure";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle input buffer

        if (choice == 1) {
            string folder;
            cout << "Enter folder name: ";
            getline(cin, folder);
            if (directory.find(folder) == directory.end()) {
                directory[folder] = {}; // Create new folder with empty file list
                cout << "Folder '" << folder << "' created.\n";
            } else {
                cout << "Folder already exists.\n";
            }

        } else if (choice == 2) {
            string folder, file;
            cout << "Enter folder name: ";
            getline(cin, folder);
            auto it = directory.find(folder);
            if (it != directory.end()) {
                cout << "Enter file name to add: ";
                getline(cin, file);
                it->second.push_back(file);
                cout << "File '" << file << "' added to folder '" << folder << "'.\n";
            } else {
                cout << "Folder not found. Please add the folder first.\n";
            }

        } else if (choice == 3) {
            cout << "\nDirectory Structure:\n";
            for (auto it = directory.begin(); it != directory.end(); ++it) {
                cout << "[" << it->first << "]\n";
                for (auto fileIt = it->second.begin(); fileIt != it->second.end(); ++fileIt) {
                    cout << "  - " << *fileIt << endl;
                }
            }

        } else if (choice == 4) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    cout << "\n24CE049_Harshil\n";
    return 0;
}
