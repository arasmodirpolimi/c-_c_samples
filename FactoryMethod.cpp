#include <iostream>
using namespace std;

class Product {
public:
    virtual void use() = 0; // Pure virtual function to be implemented by subclasses
    virtual ~Product() {} // Virtual destructor for proper cleanup
};

class ConcreteProductA : public Product {
public:
    void use() override { cout << "Using Product A" << endl; }
};

class ConcreteProductB : public Product {
public:
    void use() override { cout << "Using Product B" << endl; }
};

class Factory {
public:
    static Product* createProduct(char type) {
        if (type == 'A') return new ConcreteProductA(); // Creates a Product A
        if (type == 'B') return new ConcreteProductB(); // Creates a Product B
        return nullptr; // Returns nullptr for invalid type
    }
};

int main() {
    // Create Product A
    Product* productA = Factory::createProduct('A');
    if (productA) {
        productA->use(); // Call the `use` method on Product A
        delete productA; // Clean up to avoid memory leaks
    } else {
        cout << "Invalid product type for A!" << endl;
    }

    // Create Product B
    Product* productB = Factory::createProduct('B');
    if (productB) {
        productB->use(); // Call the `use` method on Product B
        delete productB; // Clean up to avoid memory leaks
    } else {
        cout << "Invalid product type for B!" << endl;
    }

    // Attempt to create an invalid product
    Product* invalidProduct = Factory::createProduct('C');
    if (invalidProduct) {
        invalidProduct->use();
        delete invalidProduct;
    } else {
        cout << "Invalid product type for C!" << endl;
    }

    return 0;
}
