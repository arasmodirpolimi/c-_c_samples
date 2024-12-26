#include <iostream>
// new comments

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int a = 4;
    int b = 0;
    b = factorial(a);
    std::cout << "Factorial a = " << a << " is: " << b << std::endl;
    return 0;
}


