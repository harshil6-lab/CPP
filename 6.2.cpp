// 6.2 : DAM TOPIC // 
#include <iostream>
using namespace std;

// Point class to represent coordinates
class Point {
    int x, y;

public:
    // Constructor
    Point(int xVal = 0, int yVal = 0) {
        x = xVal;
        y = yVal;
    }

    // Move the point by dx and dy
    Point* move(int dx, int dy) {
        x += dx;
        y += dy;
        return this; // return current object pointer for chaining
    }

    // Display the current coordinates
    void display() {
        cout << "Point coordinates: (" << x << ", " << y << ")" << endl;
    }
};

// Main function
int main() {
    // Create a point dynamically (pointer-based memory management)
    Point* p = new Point(5, 10);

    // Move the point using method chaining
    p->move(2, 3)->move(-1, 4)->move(0, -5);

    // Display final position
    p->display(); // Expected output: (6, 12)

    // Free the allocated memory
    delete p;
    cout<<"\n24CE049_Harshil\n";
    return 0;
}
