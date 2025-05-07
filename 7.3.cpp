// 7.3 : Topic : File Management . 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Structure to store product details
struct Product {
    string name;
    int quantity;
    float price;

    // Function to display product details
    void display() const {
        cout << "Product Name: " << name << "\n";
        cout << "Quantity: " << quantity << "\n";
        cout << "Price: $" << price << "\n\n";
    }
};

// Function to add product to file
void addProduct(const string& filename, const Product& product) {
    ofstream file(filename, ios::app); // Open in append mode
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << product.name << "," << product.quantity << "," << product.price << endl;
    file.close();
    cout << "Product added successfully.\n";
}

// Function to display all products in the inventory
void viewInventory(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int quantity;
        float price;

        getline(ss, name, ',');
        ss >> quantity;
        ss.ignore(1, ','); // Skip the comma
        ss >> price;

        Product p = {name, quantity, price};
        p.display();
    }
    file.close();
}

// Function to search for a product by name
void searchProduct(const string& filename, const string& productName) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        int quantity;
        float price;

        getline(ss, name, ',');
        ss >> quantity;
        ss.ignore(1, ',');
        ss >> price;

        if (name == productName) {
            Product p = {name, quantity, price};
            p.display();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found!\n";
    }
    file.close();
}

int main() {
    string filename = "inventory.txt";
    int choice;
    do {
        cout << "Inventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline left by cin

        switch (choice) {
            case 1: {
                string name;
                int quantity;
                float price;

                cout << "Enter product name: ";
                getline(cin, name);
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter price: ";
                cin >> price;

                Product p = {name, quantity, price};
                addProduct(filename, p);
                break;
            }
            case 2:
                viewInventory(filename);
                break;
            case 3: {
                string productName;
                cout << "Enter product name to search: ";
                cin.ignore();  // To clear the buffer
                getline(cin, productName);
                searchProduct(filename, productName);
                break;
            }
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
                break;
        }
    } while (choice != 4);
    cout<<"\n24CE049_Harshil\n";

    return 0;
}
