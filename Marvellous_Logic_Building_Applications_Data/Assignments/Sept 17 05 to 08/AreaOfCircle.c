#include<stdio.h>

#define PI 3.14

double CircleArea(float);

int main(){
	float fValue=0.0;
	double dRet=0.0;
	
	printf("Enter Radius Of Circle: ");
	scanf("%f",&fValue);
	dRet=CircleArea(fValue);
	printf("Area Of Circle is %0.3lf", dRet);
	
	return 0;
}

double CircleArea(float fNo){
	double Area=0.0;
	//float PI=3.14;
	Area= PI * fNo * fNo;
	return Area;
}