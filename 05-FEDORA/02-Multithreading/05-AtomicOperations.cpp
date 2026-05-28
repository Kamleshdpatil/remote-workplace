#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<int> counter(0); // Atomic integer

void work() {
    for(int i = 0; i < 1000; ++i) {
        counter++; // This is thread-safe and faster than a Mutex!
    }
}

int main() {
    std::vector<std::thread> threads;
    for(int i = 0; i < 10; ++i) threads.push_back(std::thread(work));
    for(auto& t : threads) t.join();

    std::cout << "Final count: " << counter << "\n"; // Will be exactly 10,000
    return 0;
}
