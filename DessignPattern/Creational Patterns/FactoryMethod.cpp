#include <iostream>
#include <string>
using namespace std;

// Product Interface
class Vehicle {
public:
    virtual void describe() = 0;
    virtual ~Vehicle() {}
};

// Concrete Product: Car
class Car : public Vehicle {
public:
    void describe() override { cout << "This is a Car." << endl; }
};

// Concrete Product: Bike
class Bike : public Vehicle {
public:
    void describe() override { cout << "This is a Bike." << endl; }
};

// Factory
class VehicleFactory {
public:
    static Vehicle* createVehicle(const string& type) {
        if (type == "Car") return new Car();
        if (type == "Bike") return new Bike();
        return nullptr;
    }
};

// Main function
int main() {
    // Create a Car
    Vehicle* car = VehicleFactory::createVehicle("Car");
    if (car) {
        car->describe();
        delete car;
    }

    // Create a Bike
    Vehicle* bike = VehicleFactory::createVehicle("Bike");
    if (bike) {
        bike->describe();
        delete bike;
    }

    // Invalid vehicle type
    Vehicle* unknown = VehicleFactory::createVehicle("Plane");
    if (!unknown) {
        cout << "Unknown vehicle type!" << endl;
    }

    return 0;
}
