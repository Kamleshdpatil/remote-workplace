#include<stdio.h>

void iterate(int);

int main(){
	int iNo;
	printf("Enter number for dispaly: ");
	scanf("%d",&iNo);
	
	iterate(iNo);
	return 0;
}

void iterate(int iValue)
{
	int i=0;
	if(iValue <0){
		iValue = -iValue;
	}
	for(i=1; i<= iValue; i++)
	{
		printf("%d\n",i);
	}
}