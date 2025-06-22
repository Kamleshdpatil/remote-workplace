#include<stdio.h>

int Distance(int);

int main()
{
	int iKm=0, iMetre=0;
	printf("Enter Number: ");
	scanf("%d", &iKm);
	
	iMetre=Distance(iKm);
	printf("%d Kilometer\'s in Meter ': %d",iKm,iMetre);
	
	return 0;	
}

int Distance(int Km){
	int Mtr=0;
	Mtr = Km * 1000;
	return Mtr;
}