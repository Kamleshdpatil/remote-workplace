//Print N to 1 numbers using recursion

#include<iostream>
#include<stdio.h>

void fun(int i, int n)
{
    printf("fun: Enter\n");
    if(i < 1)
    {
        return;
    }

    printf("i is %d n is %d\n", i, n);
    fun(i-1, n);
}

int main(void)
{
    void fun(int, int);
    int count = 0;
    printf("Enter Number\n");
    scanf("%d" , &count);

    fun(count, count);

    return(0);
}