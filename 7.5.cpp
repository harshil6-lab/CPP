#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Structure to store student info
struct Student {
    string name;
    int marks;
    double tuitionFee;
};

// User-defined manipulator for currency formatting
ostream& currency(ostream& os) {
    os << "₹";
    return os;
}

int main() {
    vector<Student> students = {
        {"Harshil", 88, 45235.75},
        {"Jenil", 92, 50120.00},
        {"Harsh", 79, 38500.5},
        {"Aryan", 85, 41000.99},
        {"John", 90, 47000}
    };

    // Display header
    cout << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;
    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    // Display student data
    for (const auto& s : students) {
        cout << left << setw(15) << s.name
             << setw(10) << s.marks
             << currency << fixed << setprecision(2) << s.tuitionFee << endl;
    }

    cout << "\n24CE049_Harshil\n";

    return 0;
}
