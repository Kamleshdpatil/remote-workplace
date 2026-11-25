#include<stdio.h>

int g_iNo = 10;  // Global initilized defn, ext linkage

int fun()
{
    printf("In fun, Number is %d\n", g_iNo);
}
