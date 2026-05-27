//
// Print sum of N numbers

#include<iostream>

using namespace std;

void sumOfNumbers(int i, int sum, int N)
{
    if(i > N)
    {
        cout<<"Sum: "<<sum<<endl;
        return;
    }
    sumOfNumbers(i+1, sum + N - i ,N);
}

void sumOfNumbersEx(int i, int sum)
{
    if(i < 1)
    {
        cout<<"SumEx: "<<sum<<endl;
        return;
    }
    sumOfNumbersEx(i-1, sum + i);
}

int main(void)
{
    int count = 0;
    cout<<"Enter Number: ";
    cin>>count;
    sumOfNumbers(0, 0, count);
    sumOfNumbersEx(count, 0);

    return(0);
}

// O(N) Time complexity
// O(N) Space complexity