#include <iostream>
#include <thread>
#include <vector>

void workerFunction(int id) {
    std::cout << "Thread " << id << " is working\n";
}

int main() {
    const int numThreads = 4;
    std::vector<std::thread> threadPool;

    for (int i = 0; i < numThreads; ++i) {
        threadPool.emplace_back(workerFunction, i);
    }

    for (auto& t : threadPool) {
        t.join(); // Wait for all threads to finish
    }

    return 0;
}
