#include<stdio.h>
#include<stdlib.h>

void fun(int i)
{
    printf("Request number: %d\n", i);

    register int reg_var1 = 10 * i;
    printf("Value of reg_var1: %d\n\n", reg_var1);
}

int main()
{
    fun(1);
    fun(2);
    fun(3);
    fun(4);

    exit(0);
}

