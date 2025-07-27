//Print name 1 to N times using recursion

#include<iostream>
#include<stdio.h>

void fun(int i, int n)
{
    printf("fun: Enter\n");
    if(i > n)
    {
        return;
    }

    printf("i is %d\n", i);
    fun(i+1, n);
}

int main(void)
{
    void fun(int, int);
    int count = 0;
    printf("Enter Number\n");
    scanf("%d" , &count);

    fun(1, count);

    return(0);
}