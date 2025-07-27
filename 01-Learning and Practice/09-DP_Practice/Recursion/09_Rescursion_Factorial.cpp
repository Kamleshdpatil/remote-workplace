//Print Sum of fornt N numbers using recursion
// 3 :- 1+2+3 = 6

//Functional way
#include<iostream>
#include<stdio.h>
int factorial(int n)
{
    if(n == 0)
        return(1);
    
    return (n * (factorial(n - 1))); 
}

int main(void)
{
    int factorial(int);
    int N = 0;
    
    printf("Enter Number\n");
    scanf("%d" , &N);

    int fact = factorial(N);
    printf("Factorial is: %d\n", fact);
    return(0);
}