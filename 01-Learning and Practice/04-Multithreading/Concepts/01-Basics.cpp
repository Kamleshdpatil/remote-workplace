// Find the addition of all odd numbers from 1 to 1900000000 and all even numbers from 1 to 1900000000

#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEvenSum(ull start, ull end)
{
    for(ull i = start; i < end; i++){
        if((i & 1) == 0){
            evenSum += i;
        }
    }
}

void findOddSum(ull start, ull end)
{
    for(ull i = start; i < end; i++){
        if((i & 1) == 1){
            oddSum += i;
        }
    }
}

int main()
{
    ull start = 0, end = 1900000000;

    auto startTime = chrono::high_resolution_clock::now();
    
    std::thread t1(findEvenSum, start, end);
    std::thread t2(findOddSum, start, end);

    // findOddSum(start, end);
    // findEvenSum(start, end);

    t1.join();
    t2.join();

    auto stopTime = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stopTime - startTime);
    
    cout<<"Odd Sum: "<<oddSum<<endl;
    cout<<"Even Sum: "<<evenSum<<endl;
    cout<<"Duration(sec): "<<duration.count() / 1000000 <<endl;

    return 0;
}
