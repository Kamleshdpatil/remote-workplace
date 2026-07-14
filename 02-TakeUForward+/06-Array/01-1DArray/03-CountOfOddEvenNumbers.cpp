#include<iostream>

using namespace std;

int countOfOddNumbers(int* arr, int size)
{
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 != 0)
            result++;
    }
    return result;
}

int countOfEvenNumbers(int* arr, int size)
{
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
            result++;
    }
    return result;
}

int main()
{
    int iArr[] = {10, 30, 1, 3, 5, 7, 9, 50, 70, 90, 100};

    cout<<"Count of Even elements: "<<countOfEvenNumbers(iArr, sizeof(iArr)/sizeof(int))<<endl;
    cout<<"Count of Odd elements: "<<countOfOddNumbers(iArr, sizeof(iArr)/sizeof(int));

    return(0);
}
