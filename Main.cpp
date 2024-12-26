#include <iostream>
using namespace std;

// new comments

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Complex number class
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the + operator
    Complex operator+(const Complex other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Function to display the complex number
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2.5, 3.5); // 2.5 + 3.5i
    Complex c2(1.5, 4.5); // 1.5 + 4.5i

    // Use overloaded + operator
    Complex c3 = c1 + c2;

    // Display the result
    cout << "Result of addition: ";
    c3.display();

    return 0;
}



// int main() {
//     int a = 4;
//     int b = 0;
//     b = factorial(a);
//     std::cout << "Factorial a = " << a << " is: " << b << std::endl;
//     return 0;
// }


