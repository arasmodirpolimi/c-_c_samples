#include <iostream>

// Definition of the global variable
int sharedVariable = 42;

// Function definition
void displayVariable() {
    std::cout << "Shared Variable: " << sharedVariable << std::endl;
}
