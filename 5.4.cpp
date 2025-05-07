#include <iostream>
#include <queue>
using namespace std;

// Forward declaration for cross-reference
class Fahrenheit;

class Celsius {
    float temp;
public:
    // Constructor
    Celsius(float t = 0) {
        temp = t;
    }

    // Conversion to Fahrenheit
    operator Fahrenheit();

    // Getter for temperature
    float getTemp() const {
        return temp;
    }

    // Compare Celsius with Fahrenheit
    bool operator==(Fahrenheit f);
};

class Fahrenheit {
    float temp;
public:
    // Constructor
    Fahrenheit(float t = 0) {
        temp = t;
    }

    // Conversion to Celsius
    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }

    // Getter
    float getTemp() const {
        return temp;
    }

    // Compare Fahrenheit with Celsius
    bool operator==(Celsius c) {
        return temp == ((c.getTemp() * 9 / 5) + 32);
    }
};

// Celsius to Fahrenheit conversion
Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

// Celsius == Fahrenheit comparison
bool Celsius::operator==(Fahrenheit f) {
    return temp == ((f.getTemp() - 32) * 5 / 9);
}

// Main function
int main() {
    // Create temperature objects
    Celsius c1(25);
    Fahrenheit f1 = c1; // Implicit conversion

    cout << "Celsius: " << c1.getTemp() << " C" << endl;
    cout << "Fahrenheit (converted): " << f1.getTemp() << " F" << endl;

    // Compare temperatures
    if (c1 == f1) {
        cout << "Temperatures are equal." << endl;
    } else {
        cout << "Temperatures are NOT equal." << endl;
    }

    // Dynamic storage using queue (FIFO)
    queue<Fahrenheit> fQueue;
    fQueue.push(Fahrenheit(98.6));
    fQueue.push(Fahrenheit(100.0));
    fQueue.push(f1); // from earlier conversion

    cout << "\nQueue (FIFO) of Fahrenheit temps:" << endl;
    while (!fQueue.empty()) {
        cout << fQueue.front().getTemp() << " F" << endl;
        fQueue.pop();
    }

    // Static storage using array
    Celsius cArray[3] = { Celsius(0), Celsius(37), Celsius(100) };

    cout << "\nArray of Celsius temps:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << cArray[i].getTemp() << " C" << endl;
    }
    
    cout<<"\n24CE049_Harshil\n";
    return 0;
}
