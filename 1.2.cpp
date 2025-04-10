#include <iostream>
#include <string>
using namespace std;

class inventry {
    int id;
    string name;
    float quantity;
    float price;

public:
    void add_products();
    void update_product(inventry pro[], int size);
    void total_value_of_product(inventry pro[], int size);
    void display_product_details(inventry pro[], int size);

    int getId() { return id; }
    string getName() { return name; }
    float getQuantity() { return quantity; }
    float getPrice() { return price; }

    void setQuantity(float q) { quantity = q; }
};

int j = 0;

void inventry::add_products() {
    cout << "Enter Name of Product : ";
    cin >> name;
    cout << "Enter ID Of Product : ";
    cin >> id;
    cout << "Enter Quantity Of Product : ";
    cin >> quantity;
    cout << "Enter Price of Product  :  " << endl;
    cin >> price;
}

void inventry::update_product(inventry pro[], int size) {
    int idp;
    cout << "Enter ID of Product : ";
    cin >> idp;
    int a=0;
    for (int k = 0; k < size; k++) {
        if (pro[k].getId() == idp) {
            float newQty;
            cout << "Update A Quantity : ";
            cin >> newQty;
            pro[k].setQuantity(newQty);
            cout << "Quantity Updated Successfully!" << endl;
            a =1;
            break;
        }
    }
    if (!a)
        cout << "Product ID not found!" << endl;
}

void inventry::total_value_of_product(inventry pro[], int size) {
    int idn;
    cout << "Enter Product Id: ";
    cin >> idn;
    int a=0;
    for (int k = 0; k < size; k++) {
        if (pro[k].getId() == idn) {
            float total = pro[k].getQuantity() * pro[k].getPrice();
            cout << "Product Total Value Is : " << total << endl;
            a = 1;
            break;
        }
    }
    if (!a)
        cout << "Product ID not found!" << endl;
}

void inventry::display_product_details(inventry pro[], int size) {
    int ids;
    cout << "Enter Id Of Product : ";
    cin >> ids;
    int a=0;
    for (int k = 0; k < size; k++) {
        if (pro[k].getId() == ids) {
            cout << "Name : " << pro[k].getName() << endl;
            cout << "ID   : " << pro[k].getId() << endl;
            cout << "Price: " << pro[k].getPrice() << endl;
            cout << "Total Value : " << (pro[k].getQuantity() * pro[k].getPrice()) << endl << endl;
            cout << "Thank You !!" << endl;
            a=1;
            break;
        }
    }
    if (!a)
        cout << "Product ID not found!" << endl;
}

int main() {
    int choice;
    inventry pro[100];

    cout << "\nFollow This Number System : \n";
    cout << "1 for Add a Product \n";
    cout << "2 for Update Quantity \n";
    cout << "3 for Total Value Of Product \n";
    cout << "4 for Display Product Details \n";
    cout << "0 for Exit \n";

    do {
        cout << "\nEnter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                pro[j].add_products();
                j++;
                cout << "Thank You !!" << endl;
                break;
            case 2:
                pro[0].update_product(pro, j);
                cout << "Thank you !!" << endl;
                break;
            case 3:
                pro[0].total_value_of_product(pro, j);
                cout << "Thank You !!" << endl;
                break;
            case 4:
                pro[0].display_product_details(pro, j);
                cout << "Thank You !!" << endl;
                break;
            case 0:
                cout << "Thank You !!" << endl;
                break;
            default:
                cout << "ERROR :::: Enter Numbers In Range of (0 - 4) !!" << endl;
        }
    } while (choice != 0);

    cout << "24CE049_Harshil" << endl;
    return 0;
}
