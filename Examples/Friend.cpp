#include <iostream>
using namespace std;


class Box {
private:
    double length;

public:
    // Constructor to initialize length
    Box(double l) : length(l) {}

    // Friend function declaration
    friend double calculateVolume(Box b, double width, double height);
};

// Friend function definition
double calculateVolume(Box b, double width, double height) {
    // Access private member 'length'
    return b.length * width * height;
}


int main() {
    Box box(10.0);  // Length = 10.0

    // Call the friend function
    double volume = calculateVolume(box, 5.0, 2.0);

    cout << "Volume of the box: " << volume << endl;

    return 0;
}