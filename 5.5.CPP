#include <iostream>
#include <vector>

using namespace std;

// Define constant PI
const float PI = 3.14;

// Base class
class Shape {
public:
    // Virtual function for area calculation
    virtual float Area() = 0; // pure virtual

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class - Rectangle
class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    // Override area function
    float Area() {
        return length * width;
    }
};

// Derived class - Circle
class Circle : public Shape {
    float radius;
public:
    Circle(float r) {
        radius = r;
    }

    // Override area function
    float Area() {
        return PI * radius * radius;
    }
};

// Main
int main() {
    // Dynamic collection using vector
    vector<Shape*> shapes;

    // Add shapes
    shapes.push_back(new Rectangle(4, 5));
    shapes.push_back(new Circle(3));
    shapes.push_back(new Rectangle(2, 6));
    shapes.push_back(new Circle(1.5));

    cout << "Areas from dynamic collection:" << endl;
    for (int i = 0; i < shapes.size(); i++) {
        cout << "Shape " << i + 1 << " Area: " << shapes[i]->Area() << endl;
    }

    // Clean up memory
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }

    // Static collection (manual handling)
    const int SIZE = 2;
    Shape* staticShapes[SIZE];
    staticShapes[0] = new Rectangle(3, 7);
    staticShapes[1] = new Circle(2.5);

    cout << "\nAreas from static array:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Shape " << i + 1 << " Area: " << staticShapes[i]->Area() << endl;
        delete staticShapes[i]; // Clean up
    }
    cout<<"\n24CE049_HARSHIL";
    return 0;
}
