#include <iostream>
using namespace std;
class Step
{
    int a;

public:
    Step(int _a = 0);
    int sum();
};
class Step1 : public Step
{
    int b;

public:
    Step1(int _a = 0, int _b = 0);
    int sum();
};
class Step2 : public Step1
{
    int c;

public:
    Step2(int _a = 0, int _b = 0, int _c = 0);
    int sum();
};
Step::Step(int _a) : a(_a) {} // LINE-1

Step1::Step1(int _a, int _b) : Step(_a), b(_b) {} // LINE-2

Step2::Step2(int _a, int _b, int _c) : Step1::Step(_a), Step1(_b), c(_c) {} // LINE-3

int Step::sum() { return a; } // LINE-4

int Step1::sum() { return a + b; } // LINE-5

int Step2::sum() { return a + b + c; } // LINE-6
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    Step aObj(a);
    Step1 bObj(a, b);
    Step2 cObj(a, b, c);
    cout << aObj.sum() << ", " << bObj.sum() << ", " << cObj.sum();
    return 0;
}