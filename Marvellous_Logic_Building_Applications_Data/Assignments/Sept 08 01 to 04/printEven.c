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
	int i=1;
	while(i<=iValue*2){
		if(i%2==0)
			printf("%d\t",i);
		i++;
	}
	}