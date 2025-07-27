//Print Linearly from 1 to N using recursion
//(But backtracking)

#include<iostream>
#include<stdio.h>

void fun(int i, int n)
{
    if(i < 1)
        return;
    fun(i-1, n);
    printf("I is %d\n", i);
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