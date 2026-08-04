#include<stdio.h>
#include<stdlib.h>

int main()
{
    int iNo1;
    int iNo2;
    int iNo3;
    int iAns;

    printf("Enter three number: \t");
    scanf("%d%d%d", &iNo1, &iNo2, &iNo3);

    iAns =  iNo1 && ++iNo2 || ++iNo3;

    printf("\niNo1 = %d iNo2 = %d iNo3 = %d iAns = %d\n", iNo1, iNo2, iNo3, iAns);

    exit(0);
}
