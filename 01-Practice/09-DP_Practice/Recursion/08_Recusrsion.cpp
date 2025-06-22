//Print Sum of fornt N numbers using recursion
// 3 :- 1+2+3 = 6

//Functional way
#include<iostream>
#include<stdio.h>
int fun(int n)
{
    if(n == 0)
        return(0);
    
    return n + fun(n - 1); 
}

int main(void)
{
    int fun(int);
    int N = 0;
    
    printf("Enter Number\n");
    scanf("%d" , &N);

    int sum = fun(N);
    printf("Sumation is: %d\n", sum);
    return(0);
}