#include <iostream>
#include <stdexcept>  // For standard exceptions
#include <limits>     // For numeric_limits
#include <string>
#include <sstream>    // For stringstream

using namespace std;

// Custom exception for invalid input
class InvalidInputException : public runtime_error {
public:
    InvalidInputException(const string& message) : runtime_error(message) {}
};

// Function to safely get a valid float value from the user
float getValidFloatInput(const string& prompt) {
    string input;
    float value;

    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        
        // Check if the input is a valid float
        if (ss >> value && ss.eof()) {
            return value;
        } else {
            // If input is invalid, clear error flags and prompt user again
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
}

int main() {
    try {
        // Get user inputs for loan amount and annual income
        float loanAmount = getValidFloatInput("Enter the loan amount: ");
        float annualIncome = getValidFloatInput("Enter your annual income: ");

        // Check if the income is zero
        if (annualIncome == 0) {
            throw InvalidInputException("Income cannot be zero. Division by zero is not allowed.");
        }

        // Calculate the loan-to-income ratio
        float ratio = loanAmount / annualIncome;
        
        // Display the result
        cout << "The loan-to-income ratio is: " << ratio << endl;
    }
    catch (const InvalidInputException& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    // Always print this at the end, as requested
    cout << "\n24CE049_Harshil\n";

    return 0;
}
