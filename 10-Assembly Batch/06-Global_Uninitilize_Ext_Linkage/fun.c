#include<stdio.h>

int g_iNo;  // Global Uninitilized defn, ext linkage

int fun()
{
    printf("In fun, Number is %d\n", g_iNo);
    g_iNo = 100;
    printf("In fun, after assign Number is %d\n", g_iNo);

}
