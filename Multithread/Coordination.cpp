#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> dataQueue;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

void producer() {
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        dataQueue.push(i);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_one(); // Notify a waiting consumer
    }
    done = true;
    cv.notify_all(); // Notify all waiting threads
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !dataQueue.empty() || done; }); // Wait for data or done
        while (!dataQueue.empty()) {
            int data = dataQueue.front();
            dataQueue.pop();
            std::cout << "Consumed: " << data << std::endl;
        }
        if (done) break;
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();
    return 0;
}
