#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee(string n = "Unknown", double basic = 0.0, double b = 1000.0) {
        name = n;
        basicSalary = basic;
        bonus = b;
    }

    inline double totalSalary() {
        return basicSalary + bonus;
    }

    void setEmployee(string n, double basic, double b = 1000.0) {
        name = n;
        basicSalary = basic;
        bonus = b;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: $" << basicSalary << endl;
        cout << "Bonus: $" << bonus << endl;
        cout << "Total Salary: $" << totalSalary() << endl;
    }
};

int main() {
    Employee employees[100];
    int choice, j;
    string name;
    double basic, bonus;

    do {
        cout << "\n1. Set Employee\n2. Display Employee\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter index (0-99): ";
                cin >> j;
                if (j >= 0 && j < 100) {
                    cout << "Enter Name: ";
                    cin >> name;
                    cout << "Enter Basic Salary: ";
                    cin >> basic;
                    cout << "Enter Bonus (or -1 for default 1000): ";
                    cin >> bonus;
                    if (bonus == -1)
                        employees[j].setEmployee(name, basic);
                    else
                        employees[j].setEmployee(name, basic, bonus);
                }
                break;

            case 2:
                cout << "Enter index (0-99): ";
                cin >> j;
                if (j >= 0 && j < 100) {
                    employees[j].display();
                }
                break;

            case 3:
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 3);
    cout<<"\n24CE049_Harshil"<<endl;
    return 0;
}
