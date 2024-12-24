#include <iostream>
#include <string>
using namespace std;

// Product: The object being constructed
class House {
public:
    string foundation, walls, roof;

    void show() {
        cout << "House with " << foundation << ", " << walls << ", and " << roof << "." << endl;
    }
};

// Abstract Builder: Defines the steps to build the product
class HouseBuilder {
public:
    virtual void buildFoundation() = 0;
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual House* getResult() = 0;
    virtual ~HouseBuilder() {}
};

// Concrete Builder: Implements the steps for a specific product
class WoodenHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    WoodenHouseBuilder() { house = new House(); }

    void buildFoundation() override { house->foundation = "Wooden foundation"; }
    void buildWalls() override { house->walls = "Wooden walls"; }
    void buildRoof() override { house->roof = "Wooden roof"; }
    House* getResult() override { return house; }
};

class BrickHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    BrickHouseBuilder() { house = new House(); }

    void buildFoundation() override { house->foundation = "Concrete foundation"; }
    void buildWalls() override { house->walls = "Brick walls"; }
    void buildRoof() override { house->roof = "Tile roof"; }
    House* getResult() override { return house; }
};

// Director: Orchestrates the building process
class HouseDirector {
public:
    void construct(HouseBuilder* builder) {
        builder->buildFoundation();
        builder->buildWalls();
        builder->buildRoof();
    }
};

// Main function
int main() {
    // Build a wooden house
    WoodenHouseBuilder woodenBuilder;
    HouseDirector director;
    director.construct(&woodenBuilder);
    House* woodenHouse = woodenBuilder.getResult();
    woodenHouse->show();

    // Build a brick house
    BrickHouseBuilder brickBuilder;
    director.construct(&brickBuilder);
    House* brickHouse = brickBuilder.getResult();
    brickHouse->show();

    // Clean up memory
    delete woodenHouse;
    delete brickHouse;

    return 0;
}
