#include<stdio.h>
#include<stdlib.h>

void fun();

static int g_iNo = 500;  // Decleration

int main(void)
{

    printf("In main, Number is %d\n", g_iNo);
    printf("In main, Address is %d\n", &g_iNo);

    fun();
 
    exit(0);
}
