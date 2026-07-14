#include<stdio.h>
#include<stdlib.h>

int g;

int main()
{
    printf("Before Scanning, g is %d\n", g);

    printf("Enter number: ", g);
    scanf("%d", &g);

    printf("After Scanning, g is %d\n", g);

    exit(0);
}
