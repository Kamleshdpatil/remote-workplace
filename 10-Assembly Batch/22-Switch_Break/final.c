#include<stdio.h>
#include<stdlib.h>

int Addition(int iNo1, int iNo2);
int Substraction(int iNo1, int iNo2);
int Multiplication(int iNo1, int iNo2);
int Division(int iNo1, int iNo2);

int main()
{
    int iNo1;
    int iNo2;
    int iAns;
    int iCh;

    do
    {
        printf("\n 1. Addition\n 2. Substraction\n 3. Multiplication\n 4. Division\n 5. Exit\n");

        printf("Enter number: ");
        scanf("%d", &iCh);

        if(iCh > 0 && iCh < 5)
        {
            printf("Enter two numbers: ");
            scanf("%d%d", &iNo1, &iNo2);
        }

        switch(iCh)
        {
            case 1:
                iAns = Addition(iNo1, iNo2);
                break;

            case 2:
                iAns = Substraction(iNo1, iNo2);
                break;
            
            case 3:
                iAns = Multiplication(iNo1, iNo2);
                break;
                
            case 4:
                iAns = Division(iNo1, iNo2);
                break;

            case 5:
                exit(0);
            
            default:
                printf("Enter valid choice: ");
                iCh = 1;
                continue;   
        }

        printf("Answer is %d\n\n", iAns);

        printf("Are you want to enter more choice? (1/0): ");
        scanf("%d", &iCh);

    } while (iCh == 1);
    
    exit(0);
}

int Addition(int iNo1, int iNo2)
{
    return iNo1 + iNo2;
}

int Substraction(int iNo1, int iNo2)
{
    return iNo1 - iNo2;
}

int Multiplication(int iNo1, int iNo2)
{
    return iNo1 * iNo2;
}

int Division(int iNo1, int iNo2)
{
    return iNo1 / iNo2;
}

