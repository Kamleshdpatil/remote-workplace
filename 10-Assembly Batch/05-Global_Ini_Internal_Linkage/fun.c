#include<stdio.h>

int g_iNo = 200;

void fun()
{
    printf("In fun, Number is %d\n", g_iNo);
    printf("In fun, Address is %d\n", &g_iNo);
}
