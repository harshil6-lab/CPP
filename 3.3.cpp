#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    static int nextAccountNumber;
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    static int totalAccounts;

    Account() {
        accountNumber = nextAccountNumber++;
        accountHolderName = "Unknown";
        balance = 0.0;
        totalAccounts++;
    }

    void setAccount(string name, double bal) {
        accountHolderName = name;
        balance = bal;
    }

    void displayAccount() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

int Account::nextAccountNumber = 1001;
int Account::totalAccounts = 0;

int main() {
    Account accounts[100];
    int choice, accNo1, accNo2;
    string name;
    double bal, amount;
    int i = 0;

    do {
        cout << "\n1. Create Account\n2. Display Account\n3. Transfer Money\n4. Show Total Accounts\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (i < 100) {
                    cout << "Enter Account Holder Name: ";
                    cin >> name;
                    cout << "Enter Initial Balance: ";
                    cin >> bal;
                    accounts[i] = Account();
                    accounts[i].setAccount(name, bal);
                    cout << "Account created. Account Number: " << accounts[i].getAccountNumber() << endl;
                    i++;
                } else {
                    cout << "Maximum account limit reached." << endl;
                }
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accNo1;
                for (int j = 0; j < i; j++) {
                    if (accounts[j].getAccountNumber() == accNo1) {
                        accounts[j].displayAccount();
                        break;
                    }
                    if (j == i - 1) {
                        cout << "Account not found." << endl;
                    }
                }
                break;

            case 3:
                cout << "Enter Sender Account Number: ";
                cin >> accNo1;
                cout << "Enter Receiver Account Number: ";
                cin >> accNo2;
                cout << "Enter Amount to Transfer: ";
                cin >> amount;

                {
                    int senderIndex = -1, receiverIndex = -1;
                    for (int j = 0; j < i; j++) {
                        if (accounts[j].getAccountNumber() == accNo1) senderIndex = j;
                        if (accounts[j].getAccountNumber() == accNo2) receiverIndex = j;
                    }

                    if (senderIndex != -1 && receiverIndex != -1) {
                        if (accounts[senderIndex].withdraw(amount)) {
                            accounts[receiverIndex].deposit(amount);
                            cout << "Transfer successful." << endl;
                        } else {
                            cout << "Insufficient balance." << endl;
                        }
                    } else {
                        cout << "Invalid account number(s)." << endl;
                    }
                }
                break;

            case 4:
                cout << "Total Accounts Created: " << Account::totalAccounts << endl;
                break;

            case 5:
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    cout<<"\n24CE049_Harshil"<<endl;
    return 0;
}
