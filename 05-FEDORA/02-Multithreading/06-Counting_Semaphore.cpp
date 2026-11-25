#include <iostream>
#include <thread>
#include <semaphore> // C++20
#include <chrono>
#include <mutex>
#include <condition_variable>

class ManualSemaphore {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int count;

public:
    explicit ManualSemaphore(int init_count) : count(init_count) {}

    void acquire() {
        std::unique_lock<std::mutex> lock(mtx);
        // Wait until count > 0
        cv.wait(lock, [this] { return count > 0; });
        count--;
    }

    void release() {
        std::lock_guard<std::mutex> lock(mtx);
        count++;
        cv.notify_one();
    }
};

ManualSemaphore gate(3);

void accessDatabase(int id) {
    std::cout << "Thread " << id << " is waiting for a slot...\n";
    gate.acquire(); // Decrements the counter (blocks if 0)
    
    std::cout << "Thread " << id << " is IN the database.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    
    std::cout << "Thread " << id << " is leaving.\n";
    gate.release(); // Increments the counter
}

int main() {
    std::thread threads[10];
    for(int i = 1; i <= 10; ++i) threads[i] = std::thread(accessDatabase, i);
    for(auto& t : threads) {
        if(t.joinable())
            t.join();
    }
    return 0;
}
