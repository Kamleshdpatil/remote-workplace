#include<stdlib.h>
#include<iostream>

using namespace std;

void Swap(char *p, char *q)
{
	char temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
}

//Generic Fuction
template <class T>
void SwapX(T *p, T *q)
{
	T temp;
	
	temp = *p;
	*p = *q;
	*q = temp;
}

int main()
{
	char x='K', y='G';
	
	SwapX(&x, &y);
	cout<<"Value X becomes: "<<x<<"\n";
	cout<<"Value Y becomes: "<<y<<"\n";
//	Swap<int>(&x, &y);
//	Swap<float>(&x, &y);
//	Swap<char>(&x, &y);
	int i=11, j=21;
	SwapX(&i, &j);
	cout<<"Value X becomes: "<<i<<"\n";
	cout<<"Value Y becomes: "<<j<<"\n";
	
	return 0;
}