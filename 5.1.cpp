// Topic : Polymorphism : 5.1
#include <iostream>
#include <vector>

using namespace std;

// Calculator class demonstrating function overloading
class Calculator {
private:
    vector<double> results;  // To store results for analysis

public:
    // Overloaded add functions

    // Add two integers
    int add(int a, int b) {
        int result = a + b;
        results.push_back(result);
        return result;
    }

    // Add two floats
    float add(float a, float b) {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    // Add one int and one float
    float add(int a, float b) {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    // Add one float and one int
    float add(float a, int b) {
        float result = a + b;
        results.push_back(result);
        return result;
    }

    // Display all stored results
    void displayResults() const {
        cout << "\nStored Results:\n";
        for (size_t i = 0; i < results.size(); ++i) {
            cout << "Result " << i + 1 << ": " << results[i] << endl;
        }
    }
};

int main() {
    Calculator calc;

    cout << "Testing Overloaded Add Functions:\n";

    // Test with int + int
    int intResult = calc.add(5, 10);
    cout << "Addition of 5 and 10 (int): " << intResult << endl;

    // Test with float + float
    float floatResult = calc.add(3.5f, 2.5f);
    cout << "Addition of 3.5 and 2.5 (float): " << floatResult << endl;

    // Test with int + float
    float mix1Result = calc.add(7, 4.3f);
    cout << "Addition of 7 (int) and 4.3 (float): " << mix1Result << endl;

    // Test with float + int
    float mix2Result = calc.add(6.2f, 8);
    cout << "Addition of 6.2 (float) and 8 (int): " << mix2Result << endl;

    // Display all stored results
    calc.displayResults();

    cout<<"\n24CE049_Harshil\n";
    return 0;
}
