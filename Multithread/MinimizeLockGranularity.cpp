#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int sharedCounter = 0; // Shared counter between threads

void safeIncrement() {
    int localCounter;
    {
        std::lock_guard<std::mutex> lock(mtx); // Critical section: Read sharedCounter
        localCounter = sharedCounter;
    }
    localCounter++; // Increment the local copy

    {
        std::lock_guard<std::mutex> lock(mtx); // Critical section: Update sharedCounter
        sharedCounter = localCounter;
    }
}

void worker() {
    for (int i = 0; i < 1000; ++i) {
        safeIncrement();
    }
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << "Final Counter: " << sharedCounter << std::endl;

    return 0;
}
