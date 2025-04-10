#include <iostream>
#include <string>
using namespace std;

class bank {
    string holder;
    double accnum;
    double balance;
    double totaldeposit;
    double totalwidrawal;
    int password;

public:
    bank() : holder(""), accnum(0), balance(0), totaldeposit(0), totalwidrawal(0), password(0) {}
    bank(string h, double acc, double b, double td, double tw, int ps)
    {
        holder = h;
        accnum = acc;
        balance = b;
        totaldeposit = td;
        totalwidrawal = tw;
        password = ps;
    }

    void create_acc(double accNum);
    void deposit();
    void widraw();
    void summery();
    void validate(double acc, int pass, int *valid);
    double getAccNum() { return accnum; }
};

void bank::create_acc(double accNum)
{
    cout << "Welcome To Bank" << endl;
    cout << "\nEnter Your First Name : ";
    cin >> holder;
    cout << "\nEnter Your Amount (Required Amount : 1000INR) : ";
    cin >> balance;
    while (balance < 1000)
    {
        cout << "Amount must be at least 1000 INR. Try again: ";
        cin >> balance;
    }
    cout << "\nMake Your Own PassWord : ";
    cin >> password;
    accnum = accNum;
    cout << "\nYour Bank Account Number Is : " << accnum << endl;
}

void bank::validate(double acc, int pass, int *valid)
{
    if (accnum == acc && password == pass)
    {
        *valid = 1;
    }
    else
    {
        *valid = 0;
    }
}

void bank::deposit()
{
    double d;
    cout << "\nhow much Money Are You Depositing : ";
    cin >> d;
    balance += d;
    totaldeposit += d;
    cout << "\nDeposit Successful. Current Balance: " << balance << " INR" << endl;
}

void bank::widraw()
{
    double wid;
    cout << "Enter Amount (INR) : ";
    cin >> wid;
    if (balance >= wid)
    {
        balance -= wid;
        totalwidrawal += wid;
        cout << "You Withdrew " << wid << " INR" << endl;
        cout << "\nThank you! Current Balance: " << balance << " INR" << endl;
    }
    else
    {
        cout << "Insufficient Balance!" << endl;
    }
}

void bank::summery()
{
    cout << "\nWelcome To Bank\n\n";
    cout << "Holder Name : " << holder << endl;
    cout << "Account Number : " << accnum << endl;
    cout << "Balance (INR) :  " << balance << endl;
    cout << "Total Withdrawal : " << totalwidrawal << endl;
    cout << "Total Deposit : " << totaldeposit << endl;
    cout << "\nThank You !!\n";
}

int main()
{
    bank person[100];
    int choice, pass, valid;
    double acc;
    double accountNumber = 110011;
    int j = 0;

    cout << "\n Follow Numbers That Given Below";
    cout << "\n1 for Create a Account";
    cout << "\n2 for Withdraw Money";
    cout << "\n3 for Deposit Money";
    cout << "\n4 for Details Of Account";
    cout << "\n0 for Exit\n";

    do
    {
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (j < 100)
            {
                person[j].create_acc(accountNumber);
                accountNumber++;
                j++;
            }
            else
            {
                cout << "Maximum account limit reached!" << endl;
            }
            break;

        case 2:
            cout << "\nEnter Your Bank Account Number : ";
            cin >> acc;
            cout << "Enter Your Password : ";
            cin >> pass;
            for (int i = 0; i < j; i++)
            {
                person[i].validate(acc, pass, &valid);
                if (valid)
                {
                    person[i].widraw();
                    break;
                }
            }
            if (valid == 0)
                cout << "Invalid account number or password!" << endl;
            break;

        case 3:
            cout << "\nEnter Your Bank Account Number : ";
            cin >> acc;
            cout << "Enter Your Password : ";
            cin >> pass;
            for (int i = 0; i < j; i++)
            {
                person[i].validate(acc, pass, &valid);
                if (valid)
                {
                    person[i].deposit();
                    break;
                }
            }
            if (valid == 0)
                cout << "Invalid account number or password!" << endl;
            break;

        case 4:
            cout << "Enter Your Account Number : ";
            cin >> acc;
            cout << "Enter Your Password : ";
            cin >> pass;
            for (int i = 0; i < j; i++)
            {
                person[i].validate(acc, pass, &valid);
                if (valid)
                {
                    person[i].summery();
                    break;
                }
            }
            if (valid == 0)
                cout << "Invalid account number or password!" << endl;
            break;

        case 0:
            cout << "Exiting...";
            return 0;

        default:
            cout << "Enter Valid Choice Between 0 to 4 !!!" << endl;
        }
    } while (choice != 0);
    cout<<"\n\n24CE049_HARSHIL";
    return 0;
}