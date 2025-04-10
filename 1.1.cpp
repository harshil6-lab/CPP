#include<iostream>
#include<string>
using namespace std;

class bank
{
    string holdername;
    int accnum;
    double balance;

public:
    void createAcc(int);
    void deposit(double);
    void withdraw(double);
    void displaydetails();
    int getAccNum(); 
};

void bank::createAcc(int acc)
{
    double Amount;
    cout << "Enter Your Name : (First Name) => ";
    cin >> holdername;
    cout << "Enter Your Initial Amount  =>  ";
    cin >> Amount;
    balance += Amount;
    accnum = acc;
    cout << "----Your Account Successfully Opened ----\n";
    cout << "Your Account Number Is => " << accnum << "\n";
}

void bank::deposit(double amount)
{
        balance += amount;
        cout << "Your Amount is Successfully Added !\n";
}

void bank::withdraw(double amo)
{
        balance -= amo;
        cout << "Your Amount Is Successfully Withdrawn !\n";
    
}

void bank::displaydetails()
{
        cout << "Name => " << holdername << "\n";
        cout << "Account Number => " << accnum << "\n";
        cout << "Balance => " << balance << "\n";
}

int bank::getAccNum() {
    return accnum;
}

int main()
{
    bank b[100];
    int i = 0;
    int a = 10011, Choice;

    do
    {
        cout << "\n\n\n\n";
        cout << "1 => Create Account\n";
        cout << "2 => Deposit Money\n";
        cout << "3 => Withdraw Money\n";
        cout << "4 => Get Details\n";
        cout << "0 => Exit\n";
        cout << "Enter Your Choice => ";
        cin >> Choice;

        switch (Choice)
        {
        case 1:
            b[i].createAcc(a);
            a++;
            i++;
            break;

        case 2:
            {
                int k;
                cout << "Enter Your Account Number => ";
                cin >> k;
                double Amount;
                cout << "Enter Your Amount => ";
                cin >> Amount;
                int a = 0;
                for (int j = 0; j < i; j++) 
                {
                    if (b[j].getAccNum() == k) {
                        b[j].deposit(Amount);
                        a = 1;
                        break;
                    }
                }
                if(a) cout<<"Enter Valid Account Number !!";
            }
            break;

        case 3:
            {
                int k;
                cout << "Enter Your Account Number => ";
                cin >> k;
                double Amount;
                cout << "Enter Your Amount => ";
                cin >> Amount;
                int b = 0;
                for (int j = 0; j < i; j++) 
                {
                    if (b[j].getAccNum() == k) {
                        b[j].withdraw(Amount);
                        a = 1;
                        break;
                    }
                }
                if(a) cout << "Account not found!\n";
                
            }
            break;

        case 4:
            {
                int k;
                cout << "Enter Your Account Number => ";
                cin >> k;
                int c = 0;
                for (int j = 0; j < i; j++) {
                    if (b[j].getAccNum() == k) {
                        b[j].displaydetails();
                        c =1;
                        break;
                    }
                }
                if(c) cout << "Account not found!\n";
                
            }
            break;

        case 0:
            return 0;

        default:
            cout << "Enter Valid Choice !!!\n";
        }
    } while (Choice != 0);

    return 0;
}
