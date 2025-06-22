#include <iostream>
using namespace std;

class A1
{
    int pri1;

protected:
    int pro1;

public:
    int pub1;
    int t1;
};

class A2 : private A1
{
protected:
    int pro2;

public:
    int t2;
    int sum() { return t1 + t2; }
    void set(int set) { t1 = set; }
    A2(int x = 0) : t2(x) {}
    void print1()
    {
        cout << "**** A1 ****" << endl;
        // cout << "Private" << endl;
        // cout << "A1: " << pri1;
        cout << "Protected" << endl;
        cout << "A1: " << pro1;
    }
};

class A3 : public A2
{
public:
    A3(int x = 0) : A2(x) { cout << t2 << endl; }
    void print()
    {
        cout << "**** A1 ****" << endl;
        //  cout << "Private" << endl;
        //  cout << "A1: " << pri1;
        cout << "Protected" << endl;
        cout << "A1: " << pro1 << endl;
        cout << "Public" << endl;
        cout << "A1 t1: " << t1 << endl;

        cout << "**** A2 ****" << endl;
        cout << "Protected" << endl;
        cout << "A2: " << pro2;
    }
};

int main()
{
    // A1 b;
    A2 d;

    // b.t1 = 10;
    d.set(20);
    // d.t1 = 20; // private inheritance
    d.t2 = 30;
    cout << d.sum();

    cout << endl;
    A3 a3;
    a3.print();

    A2 a2;
    // a2.print1();

    return 0;
}
