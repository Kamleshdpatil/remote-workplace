//Print Sum of fornt N numbers using recursion
// 3 :- 1+2+3 = 6

//Functional way
#include<iostream>
#include<stdio.h>
void fun(int n, int i)
{
    static int sum = 0;
    printf("\nEnter\n");
    sum=sum+n;
    if(i < 1)
    {
        printf("\n\nSumation: %d\n", sum);
        return;
    }
    printf("Now I is %d Sumation is: %d\n", i, sum);
    fun(n - 1, i-1); 
}

int main(void)
{
    void fun(int, int);
    int N = 0;
    
    printf("Enter Number\n");
    scanf("%d" , &N);

    fun(N,N);

    return(0);
}