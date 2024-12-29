#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int sharedCounter = 0;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // Automatically locks and unlocks
        ++sharedCounter;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final Counter: " << sharedCounter << std::endl;
    return 0;
}
