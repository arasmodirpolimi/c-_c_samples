#include <iostream>
#include <vector>

class MyClass {
private:
    int* data;
    size_t size;

public:
    // Constructor
    MyClass(size_t s) : size(s), data(new int[s]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = i; // Initialize data
        }
        std::cout << "Constructor: Resource allocated\n";
    }

    // Destructor
    ~MyClass() {
        delete[] data;
        std::cout << "Destructor: Resource deallocated\n";
    }

    // Copy Constructor
    MyClass(const MyClass& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy Constructor: Resource copied\n";
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr; // Leave the source object in a valid state
        other.size = 0;
        std::cout << "Move Constructor: Resource moved\n";
    }

    // Copy Assignment Operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) return *this;

        delete[] data; // Clean up current resource
        size = other.size;
        data = new int[other.size];
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Copy Assignment: Resource copied\n";
        return *this;
    }

    // Move Assignment Operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this == &other) return *this;

        delete[] data; // Clean up current resource
        data = other.data;
        size = other.size;

        other.data = nullptr; // Leave the source object in a valid state
        other.size = 0;

        std::cout << "Move Assignment: Resource moved\n";
        return *this;
    }
};

int main() {
    MyClass obj1(5);        // Constructor
    MyClass obj2 = obj1;    // Copy Constructor

    MyClass obj3 = std::move(obj1); // Move Constructor
    obj2 = obj3;                    // Copy Assignment
    obj3 = std::move(obj2);         // Move Assignment

    return 0;
}
