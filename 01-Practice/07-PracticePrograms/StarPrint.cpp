#include<iostream>
#include<stdio.h>

using namespace std;

void PrintStar(int num)
{
    int iSpace = num /2;

    for(int i = 0; i<num; i++)
    {
        for(int j = 0; j<num; j++)
        {
            if(j == iSpace)
            {
                printf("*");
            }
            else if(i == iSpace)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

}

int main(void)
{
    int num = 0;
    scanf("%d", &num);
    PrintStar(num);
    return(0);
}