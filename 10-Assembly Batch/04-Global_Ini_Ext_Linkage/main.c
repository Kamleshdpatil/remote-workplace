#include<stdio.h>
#include<stdlib.h>

void fun();

int main(void)
{
    extern int g_iNo;  // Decleration

    printf("In main, Number is %d\n", g_iNo);

    fun();
 
    exit(0);
}
