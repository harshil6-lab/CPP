#include <iostream>
#include <string>
using namespace std;

class Item {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    Item() {
        id = 0;
        name = "Unknown";
        price = 0.0;
        quantity = 0;
    }

    void setItem(int i, string n, double p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
    }

    void addStock(int q) {
        quantity += q;
    }

    void sellItem(int q) {
        if (q <= quantity) {
            quantity -= q;
        } else {
            cout << "Not enough stock for item ID " << id << endl;
        }
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Price: $" << price << ", Quantity: " << quantity << endl;
    }
};

int main() {
    Item inventory[100];
    int choice, j, id, quantity;
    string name;
    double price;

    do {
        cout << "\n1. Set Item\n2. Add Stock\n3. Sell Item\n4. Display Item\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter index (0-99): ";
                cin >> j;
                if (j >= 0 && j < 100) {
                    cout << "Enter ID, Name, Price, Quantity: ";
                    cin >> id >> name >> price >> quantity;
                    inventory[j].setItem(id, name, price, quantity);
                }
                break;

            case 2:
                cout << "Enter index (0-99): ";
                cin >> j;
                if (j >= 0 && j < 100) {
                    cout << "Enter quantity to add: ";
                    cin >> quantity;
                    inventory[j].addStock(quantity);
                }
                break;

            case 3:
                cout << "Enter index (0-99): ";
                cin >> j;
                if (j >= 0 && j < 100) {
                    cout << "Enter quantity to sell: ";
                    cin >> quantity;
                    inventory[j].sellItem(quantity);
                }
                break;

            case 4:
                cout << "Enter index (0-99): ";
                cin >> j;
                if (j >= 0 && j < 100) {
                    inventory[j].display();
                }
                break;

            case 5:
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
      cout<<"\n24CE049_Harshil";
    return 0;
}
