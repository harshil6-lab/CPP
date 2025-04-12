#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    Loan() {
        loanID = 0;
        applicantName = "Unknown";
        loanAmount = 0.0;
        annualInterestRate = 0.0;
        tenureMonths = 0;
    }

    void setLoan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    double calculateEMI() {
        double P = loanAmount;
        double R = annualInterestRate / (12 * 100);
        int T = tenureMonths;
        double emi = (P * R * pow(1 + R, T)) / (pow(1 + R, T) - 1);
        return emi;
    }

    void displayLoanDetails() {
        cout << "Loan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: $" << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Tenure (Months): " << tenureMonths << endl;
        cout << "Monthly EMI: $" << calculateEMI() << endl;
    }
};

int main() {
    Loan loans[100];
    int choice, j, id, tenure;
    string name;
    double amount, rate;

    do {
        cout << "\n1. Set Loan\n2. Display Loan Details\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter index (0-99): ";
                cin >> j;
                if (j >= 0 && j < 100) {
                    cout << "Enter Loan ID: ";
                    cin >> id;
                    cout << "Enter Applicant Name: ";
                    cin >> name;
                    cout << "Enter Loan Amount: ";
                    cin >> amount;
                    cout << "Enter Annual Interest Rate (%): ";
                    cin >> rate;
                    cout << "Enter Tenure in Months: ";
                    cin >> tenure;
                    loans[j].setLoan(id, name, amount, rate, tenure);
                }
                break;

            case 2:
                cout << "Enter index (0-99): ";
                cin >> j;
                if (j >= 0 && j < 100) {
                    loans[j].displayLoanDetails();
                }
                break;

            case 3:
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 3);
    cout<<"\n24CE049_Harshil\n"<<endl;
    return 0;
}
