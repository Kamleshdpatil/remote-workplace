// CPP Program to demonstrate the use of copy constructor 
#include <iostream> 
#include <stdio.h> 
using namespace std; 

class storeVal { 
public: 
	int* data;
	
	//Defualt Constructor 
	storeVal(int val) 
	{
		data = new int(val);
	} 

	// Deep Copy Constructor 
	// storeVal(const storeVal& s) 
	// { 
	// 	data = new int(*s.data);
	// 	cout << "Deep Copy constructor has been called " << endl; 
	// } 

	// Shallow Copy Constructor 
	storeVal(const storeVal& s) 
	{ 
		data = s.data;
		cout << "Copy constructor has been called " << endl; 
	} 
}; 

// Driver code 
int main() 
{ 
	storeVal obj1(5); 
	//storeVal obj2 = obj1; 
	//storeVal obj3(100);
	storeVal obj2(obj1);
	//obj2 = obj1; 
	//storeVal obj2(obj1); 
	//getchar(); 

	cout<<*obj1.data<<endl;
	cout<<*obj2.data<<endl;

	*obj2.data = 15;

	cout<<*obj1.data<<endl;
	cout<<*obj2.data<<endl;
	//cout<<*obj3.data<<endl;

    cout<<&obj1<<endl;
    cout<<&obj2<<endl;
    //cout<<&obj3<<endl;

	return 0; 
}
