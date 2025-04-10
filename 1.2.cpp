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
    void update_product();
    void total_value_of_product();
    void display_product_details();
       
};
inventry pro[100];
int j = 0;

void inventry :: add_products() {
    cout << "Enter Name of Product : " << endl;
    cin >> name;
    cout << "Enter ID Of Product : " << endl;
    cin >> id;
    cout << "Enter Quantity Of Product : " << endl;
    cin >> quantity;
    cout << "Enter Price of Product  :  " << endl;
    cin >> price;
}

void inventry :: update_product() {
    int idp;
    cout << "Enter ID of Product : ";
    cin >> idp;
    for (int j = 0; j < 100; j++) {
        if (pro[j].id == idp) {
            cout << "Update A Quantity : ";
            cin >> pro[j].quantity;
            cout << "Quantity Updated Successfully!" << endl;
        }
    }
    cout << "Product ID not found!" << endl;
}

void inventry :: total_value_of_product() {
        int idn;
        float total[j];
        cout << "Enter Product Id: ";
        cin >> idn;
        for (int j = 0; j < 100 ; j++) {
            if (pro[j].id == idn) {
                total[j] = (pro[j].quantity * pro[j].price);
                cout << "Product Total Value Is : " << total[j] << endl;
            }
        }
        cout << "Product ID not found!" << endl;
    }
    
    void inventry :: display_product_details() {
        int ids;
        cout << "Enter Id Of Product : ";
        cin >> ids;
        for (int j = 0; j < 100; j++) {
            if (pro[j].id == ids) {
                cout << "Name : " << pro[j].name << endl;
                cout << "ID   : " << pro[j].id << endl;
                cout << "Price: " << pro[j].price << endl;
                cout << "Total Value : " << (pro[j].quantity * pro[j].price) << endl << endl;
                cout << "Thank You !!" << endl;
            }
        }
        cout << "Product ID not found!" << endl;
    }


int main() {
    int choice;
    

    cout << "Follow This Number System : \n";
    cout << "1 for Add a Product \n";
    cout << "2 for Update Quantity \n";
    cout << "3 for Total Value Of Product \n";
    cout << "4 for Display Product Details \n";
    cout << "0 for Exit \n";

    do {
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                pro[j].add_products();
                j++;
                cout << "Thank You !!" << endl;
                break;
            case 2:
                pro[j].update_product();
                cout << "Thank you !!" << endl;
                break;
            case 3:
                pro[j].total_value_of_product();
                cout << "Thank You !!" << endl;
                break;
            case 4:
                pro[j].display_product_details();
                cout << "Thank You !!" << endl;
                break;
            case 0:
                cout << "Thank You !!" << endl;
                break;
            default:
                cout << "ERROR :::: Enter Numbers In Range of (0 - 4) !!" << endl;
        }
    } while (choice != 0);
    cout<<"24CE049_Harshil"<<endl;
    return 0;
}