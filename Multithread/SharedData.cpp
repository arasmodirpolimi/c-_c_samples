#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 1000; ++i) {
        ++counter; // Thread-safe without locks
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final Counter: " << counter << std::endl;
    return 0;
}
