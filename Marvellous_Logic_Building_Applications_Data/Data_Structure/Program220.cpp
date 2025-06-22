#include<stdlib.h>
#include<iostream>

using namespace std;

void Swap(float *p, float *q)
{
	float temp;
	
	temp= *p;
	*p= *q;
	*q=temp;
}

int main()
{
	float x=0, y=0;
	
	cout<<"Enter First number: \n";
	cin>>x;
	
	cout<<"Enter Second number: \n";
	cin>>y;
	
	Swap(&x, &y);
	
	cout<<"Value X becomes: "<<x<<"\n";
	cout<<"Value Y becomes: "<<y<<"\n";
	
	return 0;
}