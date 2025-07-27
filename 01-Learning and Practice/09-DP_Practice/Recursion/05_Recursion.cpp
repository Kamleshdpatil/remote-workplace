//Print Linearly from N to 1 using recursion
//(But backtracking)
// eg. 3 2 1 (Without using fun(i-1, N))
#include<iostream>
#include<stdio.h>

void fun(int i, int n)
{
    if(i < 1)
    {
        return;
    }
    printf("i is %d and n is %d\n", i, n);
    i--;
    fun(i, n); 
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