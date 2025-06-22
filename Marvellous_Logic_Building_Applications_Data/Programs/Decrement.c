#include<conio.h>
#include<stdio.h>

void iterate(int);

int main(){
	int iValue=0;
	printf("Enter Number: ");
	scanf("%d",&iValue);
	iterate(iValue);
	
	
	return 0;	
}

void iterate(int iNo)
{
	int i=0;
	for(i=iNo; i>=1; i--)
		printf("%d\n",i);
}