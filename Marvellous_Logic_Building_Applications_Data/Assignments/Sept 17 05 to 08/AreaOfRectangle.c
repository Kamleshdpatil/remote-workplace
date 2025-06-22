#include<stdio.h>

double RectArea(float,float);

int main(){
	float fWidth=0.0, fHeight=0.0;
	double dRet=0.0;
	printf("Enter Width of Rectangle: ");
	scanf("%f", &fWidth);
	printf("Enter Height of Rectangle: ");
	scanf("%f", &fHeight);
	
	dRet=RectArea(fWidth,fHeight);
	printf("Area of rectangle is: %0.3lf", dRet);
	return 0;
}

double RectArea(float fWidth,float fHeight){
	double Area=0.0, dRet=0.0;
	
	Area=fWidth * fHeight;
	
	return Area;
}