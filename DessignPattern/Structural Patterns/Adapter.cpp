#include <iostream>
using namespace std;

// Target Interface: The expected interface
class Target {
public:
    virtual void request() = 0; // The client expects this method
    virtual ~Target() {}
};

// Adaptee: The existing class with an incompatible interface
class Adaptee {
public:
    void specificRequest() {
        cout << "Adaptee: Handling specific request (220V)" << endl;
    }
};

// Class Adapter: Bridges the Target and Adaptee
class Adapter : public Target, private Adaptee {
public:
    void request() override {
        cout << "Adapter: Translating request to Adaptee" << endl;
        specificRequest(); // Calls the Adaptee's method
    }
};

// Main function
int main() {
    // Client uses the Target interface
    Target* adapter = new Adapter();
    adapter->request(); // Client calls the standard Target method

    // Clean up
    delete adapter;

    return 0;
}   