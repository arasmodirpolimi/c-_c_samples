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
        std::shared_ptr<Resource> shared2 = std::make_shared<Resource>();
        std::weak_ptr<Resource> weak = shared2; // Weak pointer

        shared1 = shared2; // Shared ownership

        // Check if the weak pointer is valid
        if (auto temp = weak.lock()) {
            std::cout << "Resource is still alive\n";
        }
    }

    // Resource is still alive because of shared1
    std::cout << "End of scope\n";

    return 0;
}
