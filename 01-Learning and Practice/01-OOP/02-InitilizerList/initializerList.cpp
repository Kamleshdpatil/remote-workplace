#include<iostream>

using namespace std;

class Point
{
private:
    //const int x;
    int x;
    int y;
    int z;
public:
    // Point(int i = 0, int j=0, int k=0):x(i), y(j), z(k)
    // {
    //     // x = i;
    //     // y = j;
    //     cout<<"In constructor"<<endl;
    // }

    // Point()
    // {
    //     z = 300;
    // }

    void setData(int i)
    {
        y = i;
        y = i + i;
    }

    // Point(int i = 0, int j = 0, int k=0)
    // {
    //     //x = i;
    //     y = j;
    //     z = k;
    //     cout<<"In constructor"<<endl;
    // }

    ~Point()
    {
        cout<<"In destructor"<<endl;
    }
    void print()
    {
        cout<<"X is: "<<x<<" and Y is: "<<y<<" Z is: "<<z<<endl;
    }
};



int main()
{
    Point p;
    p.print();
    int iY = 100;

    //Point *ptr = new Point(1200, iY, 120);
    //ptr->print();
    //ptr->setData(1);

    //ptr->print();

    //delete ptr;
    return(0);
}
