//Print Sum of fornt N numbers using recursion
// 3 :- 1+2+3 = 6

//Parametrised way
#include<iostream>
#include<stdio.h>

void fun(int i, int sum)
{
    if(i < 1)
    {
        printf("\n\nSumation: %d\n", sum);
        return;
    }
    printf("Now I is %d Sumation is: %d\n", i-1, sum+i);
    fun(i-1, sum + i); 
}

int main(void)
{
    void fun(int, int);
    int count = 0;
    int sum = 0;
    printf("Enter Number\n");
    scanf("%d" , &count);

    fun(count, sum);

    return(0);
}