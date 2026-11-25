#include<stdio.h>

int g_iNo;

void fun()
{
    printf("In fun, Number is %d\n", g_iNo);
    printf("In fun, Address is %d\n", &g_iNo);

    g_iNo = 200;
    
    printf("In fun, after assign value Number is %d\n", g_iNo);
}
