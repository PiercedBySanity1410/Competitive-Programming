#include <iostream>
#include <vector>
using namespace std;

// Function to print submasks in increasing order
void printSubmasksIncreasing(int x) {
    cout << "Submasks in increasing order:\n";
    for (int m = 0; m <=x;m = (m - x) & x) {
        cout << m << " ";
        if(m==x)break;
    }
    cout << "\n";
}

// Function to print submasks in decreasing order
void printSubmasksDecreasing(int x) {
    cout << "Submasks in decreasing order:\n";
    for (int m = x; m > 0; m = (m - 1) & x) {
        cout << m << " ";
    }
    cout << "0\n"; // Explicitly print 0
}

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    printSubmasksIncreasing(x);
    printSubmasksDecreasing(x);

    return 0;
}
