#include <iostream>
#include <memory> // For smart pointers

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired\n";
    }
    ~Resource() {
        std::cout << "Resource released\n";
    }
    void sayHello() {
        std::cout << "Hello from Resource\n";
    }
};

int main() {
    {
        // Create a unique_ptr to manage a Resource object
        std::unique_ptr<Resource> resPtr = std::make_unique<Resource>();

        // Use the Resource
        resPtr->sayHello();

        // No need to manually delete resPtr; it will be automatically released when it goes out of scope
    }

    std::cout << "End of scope reached\n";

    return 0;
}
