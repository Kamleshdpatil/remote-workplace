#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class base
{
    int data;
    int *p;
  public:
    base()
    {
      data = 10;
      p = new int(20);
      *p = 20;
    }

    // for implementing deep copy
    base(const base& obj)
    {
        data = 20;
        p = new int(20);
        *p = *(obj.p);
    }
    
    void show()
    {
        cout<<"Inside show data is: "<<data<<endl;
        cout<<"Inside show p is: "<<*p<<endl;
        cout<<"Address of p is: "<<p<<endl;
        cout<<endl;
    } 

    void setdata(int iValue)
    {
        for(int i = 1; i < 20; i++)
        {
            p[i] = i + this->data;
        }
        cout<<endl;
        for(int i = 0; i < 20; i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }

};


int main(void)
{
    base obj;
    //base obj2(obj);
    base obj2;
    obj2 = obj;
     
    obj.show();
    obj2.show();
    obj2.setdata(0);
    
    base b;
    b.show();

    base b1(b);
    b1.show();
    b1.setdata(0);
    return(0);
}