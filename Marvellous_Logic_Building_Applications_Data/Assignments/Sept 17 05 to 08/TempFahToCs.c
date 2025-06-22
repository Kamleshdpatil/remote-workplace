#include<stdio.h>

double FhtoCs(float);

int main()
{
	float fTempF=0.0;
	double dTempCs=0.0;
	printf("Enter temperature in Fahrenheit: ");
	scanf("%f", &fTempF);
	
	dTempCs=FhtoCs(fTempF);
	printf("%f Temperature in Fahrenheit ': %lf",fTempF,dTempCs);
	
	return 0;	
}

double FhtoCs(float Fahren){
	double Celc=0.0;
	Celc = ((Fahren -32) * (5/9));
	return Celc;
}