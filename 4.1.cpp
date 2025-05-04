// 4.1 Topic : Inheritance . 

#include <iostream>
#define PI 3.14159
using namespace std;

// Base class
class Shape {
protected:
    float radius;
public:
    void setRadius(float r) {
        radius = r;
    }
    float getRadius() {
        return radius;
    }
};

// Derived class
class Circle : public Shape {
public:
    float calculateArea() {
        return PI * radius * radius;
    }

    void displayArea() {
        cout << "Radius: " << getRadius() << " -> Area: " << calculateArea() << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of circles: ";
    cin >> n;

    if(n <= 0) {
        cout << "Invalid number!" << endl;
        return 1;
    }

    Circle* circles = new Circle[n];

    for(int i = 0; i < n; i++) {
        float r;
        cout << "Enter radius of circle " << (i + 1) << ": ";
        cin >> r;
        circles[i].setRadius(r);
    }

    cout << "\nAreas of Circles:\n";
    for(int i = 0; i < n; i++) {
        circles[i].displayArea();
    }

    delete[] circles; // Free memory
    cout<<"\n24CE049_Harshil\n";
    return 0;
}
