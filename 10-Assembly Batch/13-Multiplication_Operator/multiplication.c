#include<stdio.h>
#include<stdlib.h>

int main()
{
    int iNo1;
    int iNo2;

    long long int iAns;

    printf("Enter Operand 1: ");
    scanf("%d", &iNo1);

    printf("Enter Operand 2: ");
    scanf("%d", &iNo2);

    iAns = iNo1 * iNo2;

    printf("\nMultiplication is: %d\n", iAns);

    exit(0);
}
