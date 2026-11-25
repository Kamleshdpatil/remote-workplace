#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long int lliNumerator;
    
    int iDenominator;
    int iQoutient;
    int iReminder;


    printf("Enter Numerator: ");
    scanf("%qd", &lliNumerator);

    printf("Enter Denominator: ");
    scanf("%d", &iDenominator);

    iQoutient = lliNumerator / iDenominator;
    iReminder = lliNumerator % iDenominator;


    printf("\nQoutient is: %d\n", iQoutient);
    printf("Reminder is: %d\n", iReminder);


    exit(0);
}
