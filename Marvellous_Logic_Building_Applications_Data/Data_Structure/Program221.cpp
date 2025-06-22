#include<stdlib.h>
#include<iostream>

using namespace std;

void Swap(char *p, char *q)
{
	char temp;
	
	temp= *p;
	*p= *q;
	*q=temp;
}

int main()
{
	char x='\0', y='\0';
	
	cout<<"Enter First Char: \n";
	cin>>x;
	
	cout<<"Enter Second Char: \n";
	cin>>y;
	
	Swap(&x, &y);
	
	cout<<"Value X becomes: "<<x<<"\n";
	cout<<"Value Y becomes: "<<y<<"\n";
	
	return 0;
}