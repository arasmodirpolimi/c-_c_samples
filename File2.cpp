#include <iostream>

// Declaration of the global variable and function
extern int sharedVariable;
extern void displayVariable();

int main() {
    // Access the variable defined in File1.cpp
    std::cout << "Before modification: " << sharedVariable << std::endl;

    // Modify the variable
    sharedVariable = 100;

    // Call the function from File1.cpp
    displayVariable();

    return 0;
}
