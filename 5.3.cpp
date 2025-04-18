#include<iostream>
#include<string>
#include<stack> 
using namespace std;


class Point {
    
    // Here Declared Two points In Public
public:
    int x, y;    // Two Numbers

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Here Creates One unary Operator - for negative.
    Point operator-() const {
        return Point(-x, -y);
    }


    // Add two points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }


    // Compare two points for equality
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }


    // To display points
    void display() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

// This class performs operations.
class Operation {
    
    // Here we perform various types of operations.
public:
    Point result;
    string type;

    Operation(Point result, string type) : result(result), type(type) {}
};

int main() {

    stack<Operation> his; // here his is history

    int x1, y1, x2, y2;

    // Take input of first coordinates
    cout << "Enter coordinates (x1 , y1): ";
    cin >> x1 >> y1;
    Point p1(x1, y1);   // Create object p1
    

    // Take input of second coordinates
    cout << "Enter coordinates (x2 , y2): ";
    cin >> x2 >> y2;
    Point p2(x2, y2);   // Create object p2
    

    // Performing operations
    cout << "\nPerform Operations !\n";

    Point addResult = p1 + p2;       // Add results
    

    cout << "Addition result: ";
    addResult.display();
    his.push(Operation(addResult, "add"));   // Saved all performance


    Point negResult = -p1;       // Saved -p1 in neg
    cout << "Negation of Point 1: ";
    negResult.display();
    his.push(Operation(negResult, "negate"));
    

    if (p1 == p2) {      // It checks p1 and p2 are equal or not
        cout << "Point one and Point two are equal.\n";
    } else {
        cout << "Point one and Point two are not equal.\n";
    }

    // This part performing action for undo
    cout << "\nUndoing operations:\n";
    while (!his.empty()) {
        Operation op = his.top();    // Top recent perform saved in op
        his.pop();                   // Rest all pop
        cout << "Undoing " << op.type << " => ";
        op.result.display();         // Display result
    }

    cout << "\n24CE049_Harshil" << endl;
    return 0;
}
