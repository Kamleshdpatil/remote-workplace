#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}
    const Point &operator<<(ostream &os, Point &p);
};

Point &operator<<(ostream &os, Point &p)
{
    cout << "(" << p.x << "," << p.y << ")" << endl;
    return p;
}

int main(void)
{
    Point pt(2, 5);
    cout << pt;
    return (0);
}
