#include<stdio.h>
#include<stdlib.h>

int main()
{
    int iNo1;
    int iNo2;

    printf("Enter two numbers: ");
    scanf("%d%d", &iNo1, &iNo2);

    printf("iNo1 AND iNo2 : %d\n", iNo1 & iNo2);
    printf("iNo1 OR iNo2 : %d\n", iNo1 | iNo2);
    printf("iNo1 XOR iNo2 : %d\n", iNo1 ^ iNo2);
    printf("~iNo2 : %d\n", ~iNo2);
    
    printf("iNo1 << 2 : %d\n", iNo1 << 2);
    printf("iNo1 >> 2 : %d\n", iNo1 >> 2);

    exit(0);
}
