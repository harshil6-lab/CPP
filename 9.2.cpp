#include <iostream>
#include <stdexcept>  // For handling exceptions
#include <string>
#include <sstream>    // For string stream to log transaction messages

using namespace std;

// Transaction History class to keep track of logs
class TransactionHistory {
private:
    string* transactions;  // Dynamic array to store transaction logs
    int capacity;
    int size;

    // Function to resize the transaction log array when full
    void resize() {
        capacity *= 2;
        string* new_transactions = new string[capacity];
        for (int i = 0; i < size; ++i) {
            new_transactions[i] = transactions[i];
        }
        delete[] transactions;
        transactions = new_transactions;
    }

public:
    TransactionHistory() : capacity(10), size(0) {
        transactions = new string[capacity];
    }

    ~TransactionHistory() {
        delete[] transactions;
    }

    // Add a transaction log
    void log(const string& transaction) {
        if (size == capacity) {
            resize();
        }
        transactions[size++] = transaction;
    }

    // Print transaction history
    void printHistory() const {
        cout << "\nTransaction History:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << transactions[i] << endl;
        }
    }
};

// Bank Account class
class BankAccount {
private:
    string accountHolder;
    float balance;
    TransactionHistory transactionHistory;

public:
    // Constructor to initialize account holder and balance
    BankAccount(const string& name, float initialBalance = 0.0) 
        : accountHolder(name), balance(initialBalance) {}

    // Deposit funds into the account
    void deposit(float amount) {
        try {
            if (amount <= 0) {
                throw invalid_argument("Error: Deposit amount must be greater than zero.");
            }
            balance += amount;
            stringstream transaction;
            transaction << "Deposited: ₹" << amount;
            transactionHistory.log(transaction.str());
            cout << "Deposit successful!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    // Withdraw funds from the account
    void withdraw(float amount) {
        try {
            if (amount <= 0) {
                throw invalid_argument("Error: Withdrawal amount must be greater than zero.");
            }
            if (amount > balance) {
                throw runtime_error("Error: Insufficient funds.");
            }
            balance -= amount;
            stringstream transaction;
            transaction << "Withdrew: ₹" << amount;
            transactionHistory.log(transaction.str());
            cout << "Withdrawal successful!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    // Get the account balance
    float getBalance() const {
        return balance;
    }

    // Display transaction history
    void printTransactionHistory() const {
        transactionHistory.printHistory();
    }

    // Account details
    void accountDetails() const {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }
};

int main() {
    // Create a Bank Account for "Harshil" with an initial balance
    BankAccount account("Harshil", 5000);

    account.accountDetails();  // Show initial account details

    // Test deposit and withdrawal with valid and invalid amounts
    account.deposit(1500);  // Valid deposit
    account.deposit(-200);  // Invalid deposit
    account.withdraw(2000); // Valid withdrawal
    account.withdraw(10000); // Invalid withdrawal (Insufficient funds)
    account.withdraw(-500);  // Invalid withdrawal amount

    // Show final account details and transaction history
    account.accountDetails();
    account.printTransactionHistory();

    cout << "\nEnd of Program" << endl;
    cout<<"\n24Ce049_Harshil\n";
    return 0;
}
