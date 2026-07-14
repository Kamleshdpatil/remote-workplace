#include<iostream>

void createLeak() {
    int* arr = new int[10000]; // Allocated on heap
    arr[0] = 10;
    // Forgot to call delete[] arr;
    delete[] arr;
}

int main() {
    createLeak();
    //std::cout << "Program finished but memory is leaked!\n";
    return 0;
}
