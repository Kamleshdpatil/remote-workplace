#include <iostream>
#include <vector>
#include <cmath>

void fast_task() {
    for(int i=0; i<1000; ++i) { int x = i*i; }
}

void slow_task() {
    for(int i=0; i<10000000; ++i) { double x = std::sqrt(i); } // Heavy work
}

int main() {
    while(true) { // Loop so we have time to profile it
        fast_task();
        slow_task();
    }
    return 0;
}
