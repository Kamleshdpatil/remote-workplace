#include<iostream>

using namespace std;

class myClass{
    int Num = 0;
    public:
    myClass(int iNum): Num(iNum){

    }

    myClass()=default;

    void show()
    {
        cout<<"Num: "<<Num<<endl;
    }
};

int main()
{
    myClass obj(10);

    obj.show();

    myClass obj1;
    obj1.show();

    return(0);
}
