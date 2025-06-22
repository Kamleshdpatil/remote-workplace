// CPP Program as an exercise
#include <iostream>
using namespace std;

class Empty {
    public:
    Empty(){cout<<"\n Empty constructor called.\n";}
};

class Derived1 : public Empty {
    int &j;
    public:
    Derived1(int& j):j(j)
    {
        cout<<"\n Derived1 constructor called.\n"; 
        cout<<"\n Sizeof int&: "<< sizeof(int&)<<endl;
    }
};

class Derived2 : virtual public Empty {
   // int i;
    public:
    Derived2(){cout<<"\n Derived2 constructor called.\n";}
};

class Derived3 : public Empty {
    int i;
	char c;
	char ch;
	char cha;
	char chara;
	char charac;
	float Fcharac;
    public:
    Derived3(){cout<<"\n Derived3 constructor called.\n";}
};

class Derived4 : virtual public Empty {
	//char c;
    public:
    Derived4(){cout<<"\n Derived4 constructor called.\n";}
};

class Dummy {
	char c;
};

int main()
{
	cout << "sizeof(Empty) " << sizeof(Empty) << endl;
	cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
	cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
	cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
	cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;
	cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;
    int i =10;
    Derived1 der(i);
	return 0;
}
