// CPP Program as an exercise
#include <iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

class Car {
    char strCar[256];
    int i;
    public:
    Car(){cout<<"\n Empty constructor called.\n";}
    // Car(char s[]="\0", int i=0): i(i)
    // {
    //     // strCar= str; 
    //     // i = inpt;
    // }
    void Display()
    {
        cout<<"\nCar name is "<<strCar<<" Price is: "<<i<<" Lakh"<<endl;
    }
    void setString(char s[], int i)
    {
        strcpy(strCar, s);
        this->i = i;
    }
};

int main()
{
    Car* cptr =  new Car();
    // cptr->Display();

    // Car cObj("Maruti", 12);
    // cObj.Display();

    Car* cptr1;

    cptr1 = (Car*)malloc(sizeof(Car));
    //cptr->setString("Kamlesh", 1200);
    //cptr->Display();

    free(cptr);
    //delete cptr;
	return 0;
}
