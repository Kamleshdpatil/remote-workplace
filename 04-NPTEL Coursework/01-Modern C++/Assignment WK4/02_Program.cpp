#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int r = 0, int i = 0) : x(r), y(i) {}
    Point &operator<<(const Point &c)
    {
        cout << "ikd" << endl;
        cout << x + c.x << "," << y + c.y << endl;
        return *this;
    }
    friend Point &operator<<(ostream &os, Point &c);
};

Point &operator<<(ostream &os, Point &c)
{
    cout << "tikd" << endl;
    cout << c.x << "," << c.y << endl;
    return c;
}

int main(void)
{
    Point c1(2, 5), c2(4, 6);
    cout << c1 << c2;
    return (0);
}
