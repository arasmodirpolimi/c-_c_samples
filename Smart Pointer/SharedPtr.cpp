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
};

int main() {
    std::shared_ptr<Resource> shared1;
    {
        // Create a shared_ptr to manage a Resource object
        std::shared_ptr<Resource> shared2 = std::make_shared<Resource>();

        // Copy the shared pointer
        shared1 = shared2;

        std::cout << "Shared pointers in scope: " << shared2.use_count() << "\n";
    }

    // shared2 is out of scope, but shared1 still owns the Resource
    std::cout << "Shared pointers in scope: " << shared1.use_count() << "\n";

    return 0;
}
