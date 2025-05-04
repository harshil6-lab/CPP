// 4.2 Topic : Inheritance

#include <iostream>
using namespace std;

// Base class: Person
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Employee
class Employee : public Person {
protected:
    int employeeID;
public:
    Employee(string n, int a, int id) : Person(n, a) {
        employeeID = id;
    }
    void displayEmployee() {
        displayPerson(); // Call base display
        cout << "Employee ID: " << employeeID << endl;
    }
};

// Derived class: Manager
class Manager : public Employee {
private:
    string department;
public:
    Manager(string n, int a, int id, string dept) : Employee(n, a, id) {
        department = dept;
    }

    void displayManager() {
        displayEmployee(); // Call intermediate display
        cout << "Department: " << department << endl;
    }

    int getID() {
        return employeeID;
    }
};

int main() {
    const int MAX = 100;
    Manager* managers[MAX];
    int n;

    cout << "Enter number of managers (max " << MAX << "): ";
    cin >> n;

    if(n <= 0 || n > MAX) {
        cout << "Invalid number!" << endl;
        return 1;
    }

    // Input manager details
    for(int i = 0; i < n; i++) {
        string name, department;
        int age, id;

        cout << "\nEnter details for Manager " << i+1 << ":\n";
        cout << "Name: ";
        cin >> name;
        cout << "Age: ";
        cin >> age;
        cout << "Employee ID: ";
        cin >> id;
        cout << "Department: ";
        cin >> department;

        managers[i] = new Manager(name, age, id, department);
    }

    // Display all managers
    cout << "\nAll Manager Details:\n";
    for(int i = 0; i < n; i++) {
        cout << "\nManager " << i+1 << ":\n";
        managers[i]->displayManager();
    }

    // Optional: Retrieve manager by ID (simulate efficient search)
    int searchID;
    cout << "\nEnter employee ID to search for a manager: ";
    cin >> searchID;
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(managers[i]->getID() == searchID) {
            cout << "Manager found:\n";
            managers[i]->displayManager();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No manager found with ID " << searchID << endl;
    }

    // Clean up dynamic memory
    for(int i = 0; i < n; i++) {
        delete managers[i];
    }
    
    cout<<"\n24CE049_Harshil\n";

    return 0;
}
