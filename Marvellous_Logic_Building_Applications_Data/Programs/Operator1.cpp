#include<iostream>
using namespace std;
#include<stdbool.h>

class Demo
{
private:
    int i,j;
    
public:
    Demo(int x = 10, int y = 20)
    {
        i = x;
        j = y;
    }
    void Display()
    {
        cout<<i<<"\t"<<j<<"\n";
    }
    
    friend Demo operator + (Demo , Demo );
    friend Demo operator * (Demo , Demo );
    friend bool operator >(Demo , Demo );
    friend bool operator ==(Demo, Demo );
};

//     ret = obj1 + obj2;      // ret = +(obj1,obj2);
// Return_value     operator    Symbol  (Parameters)
Demo operator + (Demo op1, Demo op2)
{
    cout<<"Inside + operator\n";
    return Demo(op1.i + op2.i, op1.j+op2.j);
}

Demo operator * (Demo op1, Demo op2)
{
    cout<<"Inside  *operator\n";
    return Demo(op1.i * op2.i, op1.j*op2.j);
}

// ==    >   <  >=   <=   !=
bool operator >(Demo op1, Demo op2)
{
    if((op1.i > op2.i) &&(op1.j > op2.j))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator ==(Demo op1, Demo op2)
{
    if((op1.i == op2.i) &&(op1.j == op2.j))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Demo obj1(6,21);
    Demo obj2(7,5);
    
    Demo ret(0,0);
    
    ret = obj1 + obj2;      // ret = +(obj1,obj2);
    ret.Display();
    
    ret = obj1 * obj2;      // ret = *(obj1,obj2);
    ret.Display();
    
    if(obj1 > obj2)     // if(>(obj1,obj2))
    {
        cout<<"Obj1 is bigger\n";
    }
    else
    {
        cout<<"Obj2 is bigger\n";
    }

    if(obj1 == obj2)
    {
        cout<<"obj1 and obj2 is equal \n";
    }
    else
    {
        cout<<"obj1 and obj2 is not equal \n";
    }
        return 0;
}






























