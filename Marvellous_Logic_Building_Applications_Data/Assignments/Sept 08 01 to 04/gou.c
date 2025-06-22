/////////////////////////////////////////////////////////
//Accept number
//Store number
//using loop find number of oods
//print each number if its even
/////////////////////////////////////////////////////////

#include<stdio.h>

void Even(int);

int main(){
	int iNo=0;
	printf("Enter number for Print Even numbers : ");
	scanf("%d",&iNo);
	
	Even(iNo);
	
	return 0;
}

void Even(int iValue){
	int i=1,j=0;
		while(i<=iValue){
			for(j=1;j<=i;j++)
				printf(" %d ",j);
		i++;
		}
	}