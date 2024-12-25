#include <iostream>
#include <string>

// Component: The base interface for coffee
class Coffee {
public:
    virtual std::string getDescription() = 0;
    virtual double getCost() = 0;
    virtual ~Coffee() {}
};

// ConcreteComponent: Base coffee
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() override {
        return "Simple Coffee";
    }
    double getCost() override {
        return 2.00; // Base price of simple coffee
    }
};

// Decorator: Base decorator for coffee extras
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee; // Pointer to the coffee being decorated
public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
    std::string getDescription() override {
        return coffee->getDescription();
    }
    double getCost() override {
        return coffee->getCost();
    }
};

// ConcreteDecorator: Milk
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}
    std::string getDescription() override {
        return coffee->getDescription() + ", Milk";
    }
    double getCost() override {
        return coffee->getCost() + 0.50; // Adding milk costs $0.50
    }
};

// ConcreteDecorator: Sugar
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}
    std::string getDescription() override {
        return coffee->getDescription() + ", Sugar";
    }
    double getCost() override {
        return coffee->getCost() + 0.25; // Adding sugar costs $0.25
    }
};

// ConcreteDecorator: Whipped Cream
class WhippedCreamDecorator : public CoffeeDecorator {
public:
    WhippedCreamDecorator(Coffee* c) : CoffeeDecorator(c) {}
    std::string getDescription() override {
        return coffee->getDescription() + ", Whipped Cream";
    }
    double getCost() override {
        return coffee->getCost() + 0.75; // Adding whipped cream costs $0.75
    }
};

// Main function
int main() {
    // Start with a simple coffee
    Coffee* myCoffee = new SimpleCoffee();
    std::cout << "Order: " << myCoffee->getDescription() << ", Cost: $" << myCoffee->getCost() << std::endl;

    // Add milk to the coffee
    myCoffee = new MilkDecorator(myCoffee);
    std::cout << "Order: " << myCoffee->getDescription() << ", Cost: $" << myCoffee->getCost() << std::endl;

    // Add sugar to the coffee
    myCoffee = new SugarDecorator(myCoffee);
    std::cout << "Order: " << myCoffee->getDescription() << ", Cost: $" << myCoffee->getCost() << std::endl;

    // Add whipped cream to the coffee
    myCoffee = new WhippedCreamDecorator(myCoffee);
    std::cout << "Order: " << myCoffee->getDescription() << ", Cost: $" << myCoffee->getCost() << std::endl;

    // Clean up memory
    delete myCoffee;

    return 0;
}
