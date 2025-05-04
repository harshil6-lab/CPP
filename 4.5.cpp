// 4.5 : Topic : Inheritance
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract base class: GradingSystem
class GradingSystem {
protected:
    string studentName;
    double marks;

public:
    // Constructor to initialize student data
    GradingSystem(const string& name, double marks)
        : studentName(name), marks(marks) {}

    // Pure virtual function for computing grade
    virtual char computeGrade() const = 0;

    // Function to view student details and grade
    void viewStudentInfo() const {
        cout << "Student Name: " << studentName << "\n";
        cout << "Marks: " << marks << "\n";
        cout << "Grade: " << computeGrade() << "\n";
    }
};

// Derived class: Undergraduate
class Undergraduate : public GradingSystem {
public:
    // Constructor to initialize undergraduate student data
    Undergraduate(const string& name, double marks)
        : GradingSystem(name, marks) {}

    // Implementing the grade computation for undergraduate students
    char computeGrade() const override {
        if (marks >= 85) return 'A';
        else if (marks >= 70) return 'B';
        else if (marks >= 50) return 'C';
        else return 'F';
    }
};

// Derived class: Postgraduate
class Postgraduate : public GradingSystem {
public:
    // Constructor to initialize postgraduate student data
    Postgraduate(const string& name, double marks)
        : GradingSystem(name, marks) {}

    // Implementing the grade computation for postgraduate students
    char computeGrade() const override {
        if (marks >= 90) return 'A';
        else if (marks >= 75) return 'B';
        else if (marks >= 60) return 'C';
        else return 'F';
    }
};

// Function to get valid input for marks
double getValidMarks(const string& prompt) {
    double marks;
    while (true) {
        cout << prompt;
        cin >> marks;
        if (cin.fail() || marks < 0 || marks > 100) {
            cin.clear();  // Clear error flag
            cin.ignore(10000, '\n');  // Ignore bad input
            cout << "Invalid input. Please enter marks between 0 and 100.\n";
        } else {
            return marks;
        }
    }
}

// Main function
int main() {
    vector<GradingSystem*> students;  // Vector to store student records
    int choice;

    do {
        cout << "\nGrading System Menu:\n";
        cout << "1. Add Undergraduate Student\n";
        cout << "2. Add Postgraduate Student\n";
        cout << "3. View All Student Records\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string name;
        double marks;

        switch (choice) {
            case 1:
                cout << "Enter name of Undergraduate Student: ";
                cin >> ws;  // To handle leading whitespaces
                getline(cin, name);
                marks = getValidMarks("Enter marks for Undergraduate Student: ");
                students.push_back(new Undergraduate(name, marks));  // Create and store object
                break;
            case 2:
                cout << "Enter name of Postgraduate Student: ";
                cin >> ws;  // To handle leading whitespaces
                getline(cin, name);
                marks = getValidMarks("Enter marks for Postgraduate Student: ");
                students.push_back(new Postgraduate(name, marks));  // Create and store object
                break;
            case 3:
                cout << "\nStudent Records:\n";
                for (const auto& student : students) {
                    student->viewStudentInfo();
                    cout << "-----------------------------\n";
                }
                break;
            case 4:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }

    } while (choice != 4);

    // Clean up dynamically allocated memory
    for (auto student : students) {
        delete student;  // Deleting each student object
    }
    
    cout<<"\n24CE049_Harshil\n";

    return 0;
}
