#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1, m2;

void thread1() {
    std::scoped_lock lock(m1, m2); // Locks both mutexes atomically
    std::cout << "Thread 1 acquired both locks\n";
}

void thread2() {
    std::scoped_lock lock(m1, m2); // Locks both mutexes atomically
    std::cout << "Thread 2 acquired both locks\n";
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
