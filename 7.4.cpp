#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Structure to store student data
struct Student {
    string name;
    int marks;
    char grade;
};

// Function to pad string to fixed width
string padRight(const string& str, int width) {
    if (str.length() >= width) return str;
    return str + string(width - str.length(), ' ');
}

// Function to display header
void displayHeader() {
    cout << padRight("Name", 20)
         << padRight("Marks", 10)
         << padRight("Grade", 10) << endl;
    cout << string(40, '-') << endl;
}

// Function to display a student record
void displayStudent(const Student& s) {
    cout << padRight(s.name, 20)
         << padRight(to_string(s.marks), 10)
         << padRight(string(1, s.grade), 10) << endl;
}

int main() {
    string filename = "students.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Cannot open file '" << filename << "'!" << endl;
        return 1;
    }

    vector<Student> students;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int marks;
        char grade;

        getline(ss, name, ',');
        ss >> marks;
        ss.ignore(); // skip comma
        ss >> grade;

        students.push_back({name, marks, grade});
    }

    file.close();

    cout << "\nStudent Performance Report:\n";
    displayHeader();

    for (const auto& s : students) {
        displayStudent(s);
    }

    cout << "\n24CE049_Harshil\n";
    return 0;
}
