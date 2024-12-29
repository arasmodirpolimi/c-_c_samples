#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex mtx; // Use std::timed_mutex instead of std::mutex

void task() {
    if (mtx.try_lock_for(std::chrono::milliseconds(100))) { // Attempt to acquire lock with timeout
        std::cout << "Lock acquired by thread " << std::this_thread::get_id() << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(120)); // Simulate work
        mtx.unlock(); // Release the lock
    } else {
        std::cout << "Failed to acquire lock by thread " << std::this_thread::get_id() << "\n";
    }
}

int main() {
    std::thread t1(task); // Create thread t1
    std::thread t2(task); // Create thread t2

    t1.join(); // Wait for t1 to finish
    t2.join(); // Wait for t2 to finish

    return 0;
}
