// 6.4 : TOPIC : DAM
#include <iostream>
using namespace std;

// Base class
class Base {
public:
    // Virtual destructor to ensure proper cleanup
    virtual ~Base() {
        cout << "Base destructor called." << endl;
    }
};

// Derived class
class Derived : public Base {
    int* data;
public:
    // Constructor: allocate dynamic memory
    Derived() {
        data = new int[5]; // allocate memory
        cout << "Derived constructor: memory allocated." << endl;
    }

    // Destructor: free the allocated memory
    ~Derived() {
        delete[] data; // clean up
        cout << "Derived destructor: memory released." << endl;
    }
};

// Main function
int main() {
    // Create a derived object using a base class pointer
    Base* ptr = new Derived();

    // Delete the object through base pointer
    delete ptr;

    // If destructor in Base wasn't virtual, Derived destructor wouldn't be called
    
    cout<<"\n24CE049_Harshil\n";
    return 0;
}
