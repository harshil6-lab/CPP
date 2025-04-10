#include<iostream>
#include<string>
using namespace std;

class bank
{
    string holdername;
    int accnum;
    double balance;
    int password; // for more security 

public:
    void createAcc(int);
    void deposit(double);
    void withdraw(double);
    void displaydetails();
    int getAccNum(); 
    int Ppassword();
};

void bank::createAcc(int acc)
{
    double Amount;
    cout << "\nEnter Your Name : (First Name) => ";
    cin >> holdername;
    cout << "Enter Your Initial Amount  =>  ";
    cin >> Amount;
    balance = Amount; 
    cout<<"Create Your Own Password => ";
    cin>>password;
    accnum = acc;
    cout << "----Your Account Successfully Opened ----\n";
    cout << "Your Account Number Is => " << accnum << "\n";
    cout<<"Your Password is : "<<password<<endl;
}

void bank::deposit(double amount)
{
    balance += amount;
    cout << "Your Amount is Successfully Added !\n";
}

void bank::withdraw(double amo)
{
    if (amo > balance) {
        cout << "Insufficient Balance!\n"; 
    } else {
        balance -= amo;
        cout << "Your Amount Is Successfully Withdrawn !\n";
    }
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
int bank::Ppassword(){
    return password;
}

int main()
{
    bank b[100];
    int i = 0;
    int a = 10011, Choice;

    do
    {
        cout << "\n";
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
            int k,c;
            cout << "Enter Your Account Number => ";
            cin >> k;
            cout<<"Enter Your Password =>";
            cin>>c;
            double Amount;
            int a= 0;
            for (int j = 0; j < i; j++) 
            {
                if (b[j].getAccNum() == k && b[j].Ppassword()){
                    cout << "Enter Your Amount => ";
                     cin >> Amount;
                    b[j].deposit(Amount);
                    a = 1;
                    break;
                }
            }
            if (!a) cout << "Enter Valid Account Number !!";
        }
        break;

        case 3:
        {
            int k,c;
            cout << "Enter Your Account Number => ";
            cin >> k;
            cout<<"Enter Your Password =>";
            cin>>c;
            double Amount;
            int a= 0;
            for (int j = 0; j < i; j++) 
            {
                if (b[j].getAccNum() == k && b[j].Ppassword() == c) {
                    cout << "Enter Your Amount => ";
                     cin >> Amount;
                    b[j].withdraw(Amount);
                    a= 1;
                    break;
                }
            }
            if (!a) cout << "Account not found!\n";
        }
        break;

        case 4:
        {
            int k,c;
            cout << "Enter Your Account Number => ";
            cin >> k;
            cout<<"Enter Your Password =>";
            cin>>c;
            int a= 0;
            for (int j = 0; j < i; j++) {
                if (b[j].getAccNum() == k && b[j].Ppassword()) {
                    b[j].displaydetails();
                    a = 1;
                    break;
                }
            }
            if (!a) cout << "Account not found!\n";
        }
        break;

        case 0:
            return 0;

        default:
            cout << "Enter Valid Choice !!!\n";
        }
    } while (Choice != 0);
    cout<<"\n24ce049_HARSHIL"<<endl;
    return 0;
}
