#include<stdio.h>
#include<stdlib.h>

void fun();

int main(void)
{
    extern int g_iNo;  // Decleration

    printf("In main, Number is %d\n", g_iNo);

    fun();

    printf("In main, after fun Call Number is %d\n", g_iNo);
 
    exit(0);
}
