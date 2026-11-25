#include<stdio.h>
#include<stdlib.h>

int main()
{
    register int reg_var1 = 10;
    register int reg_var2 = 20;
    register int reg_var3 = 30;
    register int reg_var4 = 40;

    printf("Value of reg_var1: %d\n", reg_var1);
    printf("Value of reg_var2: %d\n", reg_var2);
    printf("Value of reg_var3: %d\n", reg_var3);
    printf("Value of reg_var4: %d\n", reg_var4);

    exit(0);
}

