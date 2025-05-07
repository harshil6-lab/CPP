// 5.2. : topic : polymorphism.
#include <iostream>
#include <vector>
#include <cmath>  // for abs()

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload + operator for addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator for subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload >> operator for input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << abs(c.imag) << "i";
        return out;
    }
};

// Function to add a list of complex numbers
Complex batchAdd(const vector<Complex>& list) {
    Complex total;
    for (const auto& c : list) {
        total = total + c;
    }
    return total;
}

// Function to subtract a list of complex numbers
Complex batchSubtract(const vector<Complex>& list) {
    if (list.empty()) return Complex();
    Complex result = list[0];
    for (size_t i = 1; i < list.size(); ++i) {
        result = result - list[i];
    }
    return result;
}

// Main program to test the Complex class
int main() {
    int n;
    cout << "How many complex numbers do you want to enter? ";
    cin >> n;

    vector<Complex> complexList;

    for (int i = 0; i < n; ++i) {
        Complex c;
        cout << "\nEnter Complex Number " << i + 1 << ":\n";
        cin >> c;  // Uses overloaded >>
        complexList.push_back(c);
    }

    cout << "\n--- You Entered ---\n";
    for (int i = 0; i < n; ++i) {
        cout << "Complex[" << i + 1 << "] = " << complexList[i] << endl;  // Uses overloaded <<
    }

    Complex totalSum = batchAdd(complexList);
    Complex totalDiff = batchSubtract(complexList);

    cout << "\nSum of all complex numbers: " << totalSum << endl;
    cout << "Subtraction of all complex numbers: " << totalDiff << endl;
    cout<<"\n24CE049_Harshil\n";
    return 0;
}
