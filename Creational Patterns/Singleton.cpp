#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // Private constructor

public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() {
        cout << "Singleton instance address: " << this << endl;
    }
};

// Initialize the static member
Singleton* Singleton::instance = nullptr;

int main() {
    // Access the Singleton instance
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->showMessage();

    Singleton* singleton2 = Singleton::getInstance();
    singleton2->showMessage();

    // Verify that both instances are the same
    if (singleton1 == singleton2) {
        cout << "Both are the same instance." << endl;
    }

    return 0;
}
