// 4.3 : Topic : Inheritance

#include <iostream>
using namespace std;

// Base class 1: FuelType
class FuelType {
protected:
    string fuel;
public:
    FuelType(string f) {
        fuel = f;
    }
    void displayFuel() {
        cout << "Fuel Type: " << fuel << endl;
    }
};

// Base class 2: Brand
class Brand {
protected:
    string brandName;
public:
    Brand(string b) {
        brandName = b;
    }
    void displayBrand() {
        cout << "Brand: " << brandName << endl;
    }
};

// Derived class: Car inherits from both FuelType and Brand
class Car : public FuelType, public Brand {
public:
    Car(string f, string b) : FuelType(f), Brand(b) {
        // Constructor initializes both base classes
    }

    void displayCar() {
        displayBrand();
        displayFuel();
    }
};

int main() {
    int n;
    cout << "Enter number of cars in the service queue: ";
    cin >> n;

    if(n <= 0) {
        cout << "Invalid number!" << endl;
        return 1;
    }

    // Dynamic array of pointers to Car objects
    Car** cars = new Car*[n];

    // Input car details
    for(int i = 0; i < n; i++) {
        string brand, fuel;
        cout << "\nEnter details for car " << i + 1 << ":\n";
        cout << "Brand: ";
        cin >> brand;
        cout << "Fuel Type: ";
        cin >> fuel;

        // Allocate each Car object dynamically
        cars[i] = new Car(fuel, brand);
    }

    // Display all car details
    cout << "\n--- Car Service Queue ---\n";
    for(int i = 0; i < n; i++) {
        cout << "\nCar " << i + 1 << " Info:\n";
        cars[i]->displayCar();
    }

    // Clean up memory
    for(int i = 0; i < n; i++) {
        delete cars[i];
    }
    delete[] cars;
    
    cout<<"\n24CE049_Harshil\n";

    return 0;
}
