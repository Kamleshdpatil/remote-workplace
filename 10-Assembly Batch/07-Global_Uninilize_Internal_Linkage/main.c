#include<stdio.h>
#include<stdlib.h>

void fun();

static int g_iNo;

int main(void)
{

    printf("In main, Number is %d\n", g_iNo);
    printf("In main, Address is %d\n", &g_iNo);

    fun();

    printf("In main, after assign value inside fun Number is %d\n", g_iNo);
 
    exit(0);
}
