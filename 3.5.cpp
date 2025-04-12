#include <iostream>
#include <string>
using namespace std;

long long digitSum(const string& n) {
    long long sum = 0;
    for (char c : n)
        sum += c - '0';
    return sum;
}

long long superDigit(long long n) {
    if (n < 10)
        return n;
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return superDigit(sum);
}

int main() {
    string n;
    int k;
    
    cout << "Enter the number (as a string): ";
    cin >> n;
    
    cout << "Enter the value of k (number of repetitions): ";
    cin >> k;
    
    long long initialSum = digitSum(n) * k;
    
    cout << "Super Digit: " << superDigit(initialSum) << endl;
    cout<<"\n24CE049_Harshil\n";
    return 0;
}
