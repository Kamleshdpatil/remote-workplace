#include<stdio.h>
#include<stdlib.h>

int main()
{
    int iChoice;

    printf(" 1. Addition\n 2. Substraction\n 3. Multiplication\n 4. Division\n");

    printf("Enter number: ");
    scanf("%d", &iChoice);

    switch(iChoice)
    {
        case 1:
            printf("Addition\n");
        case 2:
            printf("Substraction\n");
        case 3:
            printf("Multiplication\n");
        case 4:
            printf("Division\n");
        default:
            printf("Invalid input\n");
    }

    exit(0);    
}