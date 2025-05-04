//4.4 Topic : Inheritance
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class: BankAccount
class BankAccount {
protected:
    string accountNumber;
    double balance;
    vector<string> transactionHistory;

public:
    // Constructor
    BankAccount(const string &accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {}

    // Destructor
    virtual ~BankAccount() {}

    // Deposit operation
    void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back("Deposited: " + to_string(amount));
    }

    // Withdraw operation
    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            transactionHistory.push_back("Withdrawn: " + to_string(amount));
        }
    }

    // View balance
    void viewBalance() const {
        cout << "Account Balance: " << balance << endl;
    }

    // Undo last transaction
    void undoTransaction() {
        if (!transactionHistory.empty()) {
            string lastTransaction = transactionHistory.back();
            transactionHistory.pop_back();
            if (lastTransaction.substr(0, 8) == "Deposited") {
                // Reverse deposit: subtract the amount
                size_t pos = lastTransaction.find(": ");
                double amount = stod(lastTransaction.substr(pos + 2));
                balance -= amount;
                cout << "Undo Deposit of " << amount << endl;
            } else if (lastTransaction.substr(0, 8) == "Withdrawn") {
                // Reverse withdrawal: add the amount back
                size_t pos = lastTransaction.find(": ");
                double amount = stod(lastTransaction.substr(pos + 2));
                balance += amount;
                cout << "Undo Withdrawal of " << amount << endl;
            }
        } else {
            cout << "No transactions to undo!" << endl;
        }
    }

    // View transaction history
    void viewTransactionHistory() const {
        cout << "Transaction History for Account " << accountNumber << ":\n";
        for (const string &trans : transactionHistory) {
            cout << trans << endl;
        }
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Constructor for SavingsAccount
    SavingsAccount(const string &accountNumber, double balance, double interestRate)
        : BankAccount(accountNumber, balance), interestRate(interestRate) {}

    // Apply interest
    void applyInterest() {
        double interest = balance * (interestRate / 100);
        deposit(interest);
        transactionHistory.push_back("Interest Applied: " + to_string(interest));
    }

    // Overriding withdraw method (specific to Savings Account)
    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds in Savings Account!" << endl;
        } else {
            BankAccount::withdraw(amount);
        }
    }
};

// Derived class: CurrentAccount
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    // Constructor for CurrentAccount
    CurrentAccount(const string &accountNumber, double balance, double overdraftLimit)
        : BankAccount(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    // Overriding withdraw method (specific to Current Account)
    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Insufficient funds and overdraft limit reached!" << endl;
        } else {
            BankAccount::withdraw(amount);
        }
    }
};

// Function to get valid double input from user
double getValidAmount(const string& prompt) {
    double amount;
    while (true) {
        cout << prompt;
        cin >> amount;
        if (cin.fail() || amount <= 0) {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Ignore the bad input in the buffer
            cout << "Invalid input. Please enter a valid positive number." << endl;
        } else {
            return amount;
        }
    }
}

// Function to get valid string input (e.g., account type)
string getValidStringInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (input != "savings" && input != "current") {
            cout << "Invalid input. Please enter 'savings' or 'current'." << endl;
        } else {
            return input;
        }
    }
}

// Main function
int main() {
    string accountType;
    string accountNumber;
    double balance, interestRate, overdraftLimit;
    
    cout << "Welcome to the Banking System!" << endl;

    // Get account type from user
    accountType = getValidStringInput("Enter account type (savings or current): ");

    cout << "Enter account number: ";
    cin >> accountNumber;

    balance = getValidAmount("Enter initial balance: ");

    // Create the account based on the user's choice
    BankAccount* account;
    if (accountType == "savings") {
        interestRate = getValidAmount("Enter interest rate for Savings Account: ");
        account = new SavingsAccount(accountNumber, balance, interestRate);
    } else if (accountType == "current") {
        overdraftLimit = getValidAmount("Enter overdraft limit for Current Account: ");
        account = new CurrentAccount(accountNumber, balance, overdraftLimit);
    } else {
        cout << "Invalid account type. Exiting." << endl;
        return 1;
    }

    int choice;
    do {
        // Menu for user actions
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. View Balance\n";
        cout << "4. View Transaction History\n";
        cout << "5. Undo Last Transaction\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        double amount;
        switch (choice) {
        case 1:
            amount = getValidAmount("Enter deposit amount: ");
            account->deposit(amount);
            break;
        case 2:
            amount = getValidAmount("Enter withdrawal amount: ");
            account->withdraw(amount);
            break;
        case 3:
            account->viewBalance();
            break;
        case 4:
            account->viewTransactionHistory();
            break;
        case 5:
            account->undoTransaction();
            break;
        case 6:
            cout << "Thank you for using the Banking System. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);

    // Clean up
    delete account;
    cout<<"\n24CE049_Harshil\n";
    return 0;
}
