#include<stdio.h>
#include<stdlib.h>

int main()
{
    int iChoice;

    printf("1. Addition\n 2. Substraction\n 3. Multiplication\n 4. Division\n");

    printf("Enter number: ");
    scanf("%d", &iChoice);

    if(iChoice == 1)
        printf("Addition\n");
    else if(iChoice == 2)
        printf("Substraction\n");
    else if(iChoice == 3)
        printf("Multiplication\n");
    else if(iChoice == 4)
        printf("Division\n");
    else
        printf("Invalid input");

    exit(0);    
}